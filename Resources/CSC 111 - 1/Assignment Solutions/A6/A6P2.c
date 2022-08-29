/*
 *  Authors:     Bill Bird, D. Michael Miller, and Hausi A. Muller
 *  Date:        Oct 23, 2013
 *  Assignment:  Assignment 6 Part 2
 *  File name:   a6p2solution.c
 *  Description: Generate HTML5 and SVG code to display wire frame.
 *               The wire frame is specified in an input text file identified WIREFRAME_INPUT_FILENAME.
 *               The HTML5/SVG code is output into a text file identified by HTML5_SVG_OUTPUT_FILENAME.
 *  References:  http://reference.wolfram.com/mathematica/tutorial/VectorsAndMatrices.html
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

//The name of the input file
#define WIREFRAME_INPUT_FILENAME ("A6teapot.txt")
// The name of the output file
#define HTML5_SVG_OUTPUT_FILENAME ("A6P2teapot.html")
#define OBJECT_COLOR_0  ("magenta")
#define OBJECT_COLOR_1  ("cyan")
#define OBJECT_COLOR_2  ("blue")
#define OBJECT_COLOR_3  ("purple")


/* ========================================================================= */
/*                              Type Definitions                             */
/*          Do not alter the provided definitions (they will be used         */
/*            for marking). You may add new definitions as needed.           */
/* ========================================================================= */

//The amount to rotate around the X axis (in radians)
#define ROTATION_ANGLE_X (20*(M_PI/180)) //i.e. 20 degrees
//The amount to rotate around the Y axis (in radians)
#define ROTATION_ANGLE_Y (0*(M_PI/180)) //i.e. 0 degrees
//The amount to rotate around the Z axis (in radians)
#define ROTATION_ANGLE_Z (45*(M_PI/180)) //i.e. 45 degrees
#define SCALE_FACTOR (400)
#define TRANSLATION_X  (250)
#define TRANSLATION_Y  (0)
#define TRANSLATION_Z  (250)

#define MATRIX_MAX (4)
#define PROJECTED  (2)
#define MAX_WIREFRAME_EDGES (1000)
#define POINTS_PER_EDGE  (6)

typedef float Matrix[MATRIX_MAX][MATRIX_MAX];

/* matMul
   You are to implement the following matrix multiplication function.
   Computes the matrix product A*B, which is stored in the matrix C.
   ARows and ACols contain the number of rows and columns of the matrix A.
   BCols contains the number of columns in B (the number of rows in B is the same
   as the number of columns in A).
   The outRows and outCols parameters, which are passed by reference, must be
   set to the number of rows and columns in the resulting matrix C.
*/
void matMul(Matrix A, Matrix B, int ARows, int ACols, int BCols, Matrix C, int *outRows, int *outCols){
	*outRows = ARows;
	*outCols = BCols;
	int i,j,k;
	for (i = 0; i < ARows; i++) {
		for (j = 0; j < BCols; j++) {
			C[i][j] = 0;
			for (k = 0; k < ACols; k++) {
				C[i][j] += A[i][k]*B[k][j];
			} /*for*/
		} /*for*/
	} /*for*/
} /* matMul */

/* ========================================================================= */
/*                       Library Function  Declarations                      */
/*            These functions are defined at the end of the file.            */
/*      (Do not modify these declarations or the corresponding functions)    */
/* ========================================================================= */


/* writePrologue
   This function writes the initial part of the HTML5 file (which sets up the
   graphics interface). This must be called before any graphical data is written
   to the file.
*/
void writePrologue(FILE *f);

/* writeEpilogue
   This function writes the final part of the HTML5 file. This must be called
   after all data has been written, but before the file is closed.
   (The caller is responsible for closing the file afterwards).
*/
void writeEpilogue(FILE *f);

/* writeLineSegment
   This function writes a line segment into the HTML5 file referenced by f.
   The line segment begins at point (x1,y1) and ends at point (x2,y2).
   The line is drawn with the specified colour.
*/
void writeLineSegment(FILE *f, float x1, float y1, float x2, float y2, char colour[]);

/* projectionMatrix
   This function sets the provided matrix to a 2x4 projection matrix, which
   is used to convert points in 3 dimensions to points in 2 dimensions.
*/

void projectionMatrix(Matrix outM);

/* rotationMatrixX
   Sets the matrix outM to contain a 4x4 rotation matrix for a rotation
   of the given angle (which is provided in radians) around the X axis.

*/
void rotationMatrixX(float angle, Matrix outM);

/* rotationMatrixY
   Sets the matrix outM to contain a 4x4 rotation matrix for a rotation
   of the given angle (which is provided in radians) around the Y axis.
*/

void rotationMatrixY(float angle, Matrix outM);

/* rotationMatrixZ
   Sets the matrix outM to contain a 4x4 rotation matrix for a rotation
   of the given angle (which is provided in radians) around the Z axis.

*/
void rotationMatrixZ(float angle, Matrix outM);

/* scalingMatrix
   Sets the matrix outM to contain a 4x4 scaling matrix where the three
   scaling factors are xs, ys, zs.

*/
void scalingMatrix(float xs, float ys, float zs, Matrix outM);

/* translationMatrix
   Sets the matrix outM to contain a 4x4 translation matrix where the three
   translation factors are xt, yt, zt.

*/
void translationMatrix(float xt, float yt, float zt, Matrix outM);


int readWireFrame(Matrix wireFrame[]) {
	FILE *inFile = fopen(WIREFRAME_INPUT_FILENAME, "r");
	if (inFile == NULL){
		printf("Error: Unable to open input file %s\n", WIREFRAME_INPUT_FILENAME);
		exit(EXIT_FAILURE);
	} /*if*/

	int edge = 0;
	int noItemsRead;

	while(true) {
		noItemsRead = fscanf(inFile, "%f %f %f %f %f %f",
				             &wireFrame[edge][0][0],
				             &wireFrame[edge][1][0],
				             &wireFrame[edge][2][0],
				             &wireFrame[edge][0][1],
				             &wireFrame[edge][1][1],
				             &wireFrame[edge][2][1]);
		if (noItemsRead != POINTS_PER_EDGE) break;

		wireFrame[edge][3][0] = 1;
		wireFrame[edge][3][1] = 1;
		edge++;
	} /*while*/

	fclose(inFile);

	return edge;
} /*readWireFrame*/

void computeTransformationMatrix(Matrix M, int* Mrows, int* Mcols, float scale, float xt, float yt, float zt, float rx, float ry, float rz) {
	// return in parameter Matrix M -- final transformation matrix M = P * M4
	Matrix P;   // projection matrix
	Matrix S;   // scaling matrix
	Matrix T;   // translation matrix
	Matrix R_X; // rotation about x-axis matrix
	Matrix R_Y; // rotation about y-axis matrix
	Matrix R_Z; // rotation about z-axis matrix
	Matrix M1;  // intermediate transformation matrix M1 = R_Y * R_Z
	Matrix M2;  // intermediate transformation matrix M2 = R_X * M1
	Matrix M3;  // intermediate transformation matrix M3 = S * M2
	Matrix M4;  // intermediate transformation matrix M4 = T * M3

	// initialize transformation matrices
	projectionMatrix(P);
	rotationMatrixX(rx, R_X);
	rotationMatrixY(ry, R_Y);
	rotationMatrixZ(rz, R_Z);
	scalingMatrix(scale, scale, -scale, S);  // note -1 because SVG vertical axis goes downward
	translationMatrix(xt, yt, zt, T);

	// compute final transformation matrix M using matrix multiplication M = P * T * S * R_X * R_Y * R_Z
	matMul(R_Y, R_Z, MATRIX_MAX, MATRIX_MAX, MATRIX_MAX, M1, Mrows, Mcols);
	matMul(R_X, M1, MATRIX_MAX, MATRIX_MAX, MATRIX_MAX, M2, Mrows, Mcols);
	matMul(S, M2, MATRIX_MAX, MATRIX_MAX, MATRIX_MAX, M3, Mrows, Mcols);
	matMul(T, M3, MATRIX_MAX, MATRIX_MAX, MATRIX_MAX, M4, Mrows, Mcols);
	matMul(P, M4, MATRIX_MAX, MATRIX_MAX, MATRIX_MAX, M, Mrows, Mcols);
} /*computeTransformationMatrix*/

void drawWireFrame(FILE* outFile, Matrix wireFrame[], int noEdges, Matrix M, char col[]) {
	Matrix R;
	int Rrows, Rcols;
	int edge;
	for (edge=0; edge<noEdges; edge++) {
		// transform line segment
		matMul(M, wireFrame[edge], MATRIX_MAX, MATRIX_MAX, MATRIX_MAX, R, &Rrows, &Rcols);
		// generate SVG for line segment
		writeLineSegment(outFile, R[0][0], R[1][0], R[0][1], R[1][1], col);
		printf("%7.2f %7.2f %7.2f %7.2f\n", R[0][0], R[1][0], R[0][1], R[1][1]);
	} /*for*/
} /*drawWireFrame*/

void generateSVGfile(Matrix wireFrame[], int noEdges) {
	FILE *inFile = fopen(WIREFRAME_INPUT_FILENAME, "r");
	if (inFile == NULL){
		printf("Error: Unable to open input file %s\n", WIREFRAME_INPUT_FILENAME);
		exit(EXIT_FAILURE);
	} /*if*/

	FILE *outFile = fopen(HTML5_SVG_OUTPUT_FILENAME, "w");
	writePrologue(outFile);

    Matrix M;   // compute final transformation matrix
    int Mrows, Mcols;
	computeTransformationMatrix(M, &Mrows, &Mcols, 200, 125, 0, 125, 100, 200, 0);
	drawWireFrame(outFile, wireFrame, noEdges, M, OBJECT_COLOR_0);

	writeEpilogue(outFile);

	fclose(outFile);
} /*generateSVGfile*/


int main(){
	Matrix wireFrame[MAX_WIREFRAME_EDGES];
    int noEdges = readWireFrame(wireFrame);

	generateSVGfile(wireFrame, noEdges);

	return EXIT_SUCCESS;
} /* main */


/* ========================================================================= */
/*                           Library Functions                               */
/*        These are declared above, and will be useful to generate           */
/*            the output file. Do not modify these functions.                */
/* ========================================================================= */

/* Canvas size (used by the functions below) - Do not change */
#define CANVAS_SIZE_X (500)
#define CANVAS_SIZE_Y (500)

/* writePrologue
   This function writes the initial part of the HTML5 file (which sets up the
   graphics interface). This must be called before any graphical data is written
   to the file.
*/
void writePrologue(FILE *f){
	if (f == NULL){
		printf("writePrologue error: output file == NULL\n");
		exit(EXIT_FAILURE);
	} /*if*/
	fputs("<!DOCTYPE html>\n", f);
	fputs("<html>\n", f);
	fputs("<head>\n", f);
	fputs("<title>CSC 111 Assignment 6 Part II</title>\n", f);
	fputs("</head>\n", f);
	fputs("<body>\n", f);
	fprintf(f,"<svg width=\"%dpx\" height=\"%dpx\">\n", CANVAS_SIZE_X, CANVAS_SIZE_Y);
} /* writePrologue */

void writeEpilogue(FILE *f){
	if (f == NULL){
		printf("writeEpilogue error: output file == NULL\n");
		exit(EXIT_FAILURE);
	} /*if*/
	fputs("</svg>\n",f);
	fputs("</body>\n",f);
	fputs("</html>\n",f);
} /* writeEpilogue */

void projectionMatrix(Matrix outM){
	outM[0][0] = 1; outM[0][1] = 0; outM[0][2] = 0; outM[0][3] = 0;
	outM[1][0] = 0; outM[1][1] = 0; outM[1][2] = 1; outM[1][3] = 0;
} /* projectionMatrix */

void rotationMatrixX(float angle, Matrix outM){
	outM[0][0] = 1; outM[0][1] = 0;           outM[0][2] = 0;          outM[0][3] = 0;
	outM[1][0] = 0; outM[1][1] = cos(angle);  outM[1][2] = sin(angle); outM[1][3] = 0;
	outM[2][0] = 0; outM[2][1] = -sin(angle); outM[2][2] = cos(angle); outM[2][3] = 0;
	outM[3][0] = 0; outM[3][1] = 0;           outM[3][2] = 0;          outM[3][3] = 1;
} /* rotationMatrixX */

void rotationMatrixY(float angle, Matrix outM){
	outM[0][0] = cos(angle);  outM[0][1] = 0; outM[0][2] = sin(angle);  outM[0][3] = 0;
	outM[1][0] = 0;           outM[1][1] = 1; outM[1][2] = 0;           outM[1][3] = 0;
	outM[2][0] = -sin(angle); outM[2][1] = 0; outM[2][2] = cos(angle);  outM[2][3] = 0;
	outM[3][0] = 0;           outM[3][1] = 0; outM[3][2] = 0;           outM[3][3] = 1;
} /* rotationMatrixY */

void rotationMatrixZ(float angle, Matrix outM){
	outM[0][0] = cos(angle); outM[0][1] = -sin(angle); outM[0][2] = 0; outM[0][3] = 0;
	outM[1][0] = sin(angle); outM[1][1] = cos(angle);  outM[1][2] = 0; outM[1][3] = 0;
	outM[2][0] = 0;          outM[2][1] = 0;           outM[2][2] = 1; outM[2][3] = 0;
	outM[3][0] = 0;          outM[3][1] = 0;           outM[3][2] = 0; outM[3][3] = 1;
} /* rotationMatrixZ */

void scalingMatrix(float xs, float ys, float zs, Matrix outM){
	outM[0][0] = xs; outM[0][1] = 0;  outM[0][2] = 0;  outM[0][3] = 0;
	outM[1][0] = 0;  outM[1][1] = ys; outM[1][2] = 0;  outM[1][3] = 0;
	outM[2][0] = 0;  outM[2][1] = 0;  outM[2][2] = zs; outM[2][3] = 0;
	outM[3][0] = 0;  outM[3][1] = 0;  outM[3][2] = 0;  outM[3][3] = 1;
} /* scaleingMatrix */

void translationMatrix(float xt, float yt, float zt, Matrix outM){
	outM[0][0] = 1; outM[0][1] = 0; outM[0][2] = 0; outM[0][3] = xt;
	outM[1][0] = 0; outM[1][1] = 1; outM[1][2] = 0; outM[1][3] = yt;
	outM[2][0] = 0; outM[2][1] = 0; outM[2][2] = 1; outM[2][3] = zt;
	outM[3][0] = 0; outM[3][1] = 0; outM[3][2] = 0; outM[3][3] = 1;
} /* translationMatrix */

void writeLineSegment(FILE *f, float x1, float y1, float x2, float y2, char colour[]){
	if (f == NULL){
		printf("writeLineSegment error: output file == NULL\n");
		exit(EXIT_FAILURE);
	} /*if*/
	fprintf(f,"<line x1=\"%.1f\" y1=\"%.1f\" x2=\"%.1f\", y2=\"%.1f\" style=\"stroke: %s;\" />\n",
			x1, y1, x2, y2, colour);
} /* writeLineSegment */


