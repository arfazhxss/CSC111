/*
 *  Author:      Hausi A. Muller
 *  UVicID:      V00123456
 *  Date:        Oct 5, 2013
 *  Lecture:     Assignment 5 Part 2
 *  File name:   A5P22013.c
 *  Description: Generate random CSC 111 Art.
 *  Learning outcomes:
 *  - generate random numbers
 *  - opening, writing and closing files
 *  - output formats
 *  - control flow: function calls, while, if
 *  - defining and calling functions
 *  - calling library functions
 *  - gentle introduction to HTML 5 canvas
 *  - int, string, literals
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define NO_SHAPES 5000

#define X_RANGE 800
#define Y_RANGE 400
#define SHAPE_RANGE 4
#define WIDTH_RANGE 100
#define HEIGHT_RANGE 200
#define RED_RANGE 255
#define GREEN_RANGE 255
#define BLUE_RANGE 255
#define OPACITY_RANGE 100

#define CIRCLE_SHAPE 0
#define SQUARE_SHAPE 1
#define ELLIPSE_SHAPE 2
#define RECTANGLE_SHAPE 3

#define SHAPE_PERCENTAGE 100
#define CIRCLE_PERCENTAGE 40
#define SQUARE_PERCENTAGE 10
#define ELLIPSE_PERCENTAGE 40
#define RECTANGLE_PERCENTAGE 10

#define FRAME_RED 0
#define FRAME_GREEN 0
#define FRAME_BLUE 0
#define FRAME_WIDTH 3

#define MAX_CONSOLE_LINES 5


#define OUTPUT_FILE_NAME "a5p3randomart.html"

FILE* createHTML5SVGFile(char* fnam, int width, int height);
void closeHTML5SVGFile(FILE* ofp);
void frame(FILE* ofp, int x, int y, int width, int height, int frameWidth, int r, int g, int b, float op);
void circle(FILE* ofp, int cx, int cy, int radius, int r, int g, int b, float op);
void square(FILE* ofp, int x, int y, int width, int r, int g, int b, float op);
void rectangle(FILE* ofp, int x, int y, int width, int height, int r, int g, int b, float op);
void ellipse(FILE* ofp, int cx, int cy, int rx, int ry, int r, int g, int b, float op);
void drawRandomArt(FILE* ofp, int noOfShapes);

FILE* createHTML5SVGFile(char* fnam, int width, int height) {
	FILE* ofp;
	ofp = fopen(fnam, "w");
	if (ofp == NULL) {
		printf("Cannot open output file %s\n", fnam);
		exit(EXIT_FAILURE);
	} /* if */
	fprintf(ofp, "<!DOCTYPE html>\n");
	fprintf(ofp, "<html>\n");
	fprintf(ofp, "\t<head>\n");
	fprintf(ofp, "\t\t<title>My CSC 111 Art</title>\n");
	fprintf(ofp, "\t</head>\n");
	fprintf(ofp, "\t<body>\n");
	fprintf(ofp, "\t\t<p>Hi Mom and Dad! Happy Thanksgiving!</p>\n");
	fprintf(ofp, "\t\t<svg id=\"myart\" width=\"%d\" height=\"%d\" xmlns=\"http://www.w3.org/2000/svg\">\n", width, height);
	fprintf(ofp, "\t\t\t<defs>\n");
	fprintf(ofp, "\t\t\t\t<clipPath id=\"myframe\"> <rect x=\"0\" y=\"0\" width=\"%d\" height=\"%d\" /> </clipPath>\n", width, height);
	fprintf(ofp, "\t\t\t</defs>\n");
	return ofp;
} /*createHTML5SVGFile*/

void closeHTML5SVGFile(FILE* ofp) {
	fprintf(ofp, "\t\t</svg>\n");
	fprintf(ofp, "\t</body>\n");
	fprintf(ofp, "</html>\n");
	fclose(ofp);
} /*closeHTML5SVGFile*/

void frame(FILE* ofp, int x, int y, int width, int height, int frameWidth, int r, int g, int b, float op) {
	fprintf(ofp, "\t\t\t<rect x=\"%d\" y=\"%d\" width=\"%d\" height=\"%d\" style=\"fill: none; stroke-width: %d; stroke:rgb(%d,%d,%d); stroke-opacity:%.1f;\" />\n", x, y, width, height, frameWidth, r, g, b, op);
} /*rectangle*/

void circle(FILE* ofp, int cx, int cy, int radius, int r, int g, int b, float op) {
	fprintf(ofp, "\t\t\t<circle cx=\"%d\" cy=\"%d\" r=\"%d\" clip-path=\"url(#myframe)\"; style=\"fill:rgb(%d,%d,%d); fill-opacity:%.1f\"/>\n", cx, cy, radius, r, g, b, op);
} /*circle*/

void square(FILE* ofp, int x, int y, int width, int r, int g, int b, float op) {
	fprintf(ofp, "\t\t\t<rect x=\"%d\" y=\"%d\" width=\"%d\" height=\"%d\" clip-path=\"url(#myframe)\"; style=\"fill:rgb(%d,%d,%d); fill-opacity:%.1f\"/>\n", x, y, width, width, r, g, b, op);
} /*square*/

void rectangle(FILE* ofp, int x, int y, int width, int height, int r, int g, int b, float op) {
	fprintf(ofp, "\t\t\t<rect x=\"%d\" y=\"%d\" width=\"%d\" height=\"%d\" clip-path=\"url(#myframe)\"; style=\"fill:rgb(%d,%d,%d); fill-opacity:%.1f;\"/>\n", x, y, width, height, r, g, b, op);
} /*rectangle*/

void ellipse(FILE* ofp, int cx, int cy, int rx, int ry, int r, int g, int b, float op) {
	fprintf(ofp, "\t\t\t<ellipse cx=\"%d\" cy=\"%d\" rx=\"%d\" ry=\"%d\" clip-path=\"url(#myframe)\"; style=\"fill:rgb(%d,%d,%d); fill-opacity:%.1f\"/>\n", cx, cy, rx, ry, r, g, b, op);
} /*ellipse*/

void drawRandomArt(FILE* ofp, int noOfShapes) {
	int k = 0;       // count number of shapes generated
	int shape = 0;   // random shape: rectangle or circle
	int shapePercentage; // percentage of circles, squares, ellipses and rectangles -- in this order
	int x = 0;       // random location of shape to be drawn
	int y = 0;
	int width = 0;   // random size of shape to be drawn
	int height = 0;
	int red = 0;     // random color of shape to be drawn
	int green = 0;
	int blue = 0;
	int iopacity = 0;
	float opacity = 1.0; // shape transparency

	srand(time(NULL));  // seed random number generator

	// print a table of random numbers generated on console
	printf("Table of random numbers for drawing geometric shapes in different colours, sizes and opacities\n");
	printf("%7s %7s %7s %7s %7s %7s %7s %7s %7s %7s\n",
			"shape#", "shape", "x", "y", "width", "height", "red", "green", "blue", "opacity");
	while (k < noOfShapes) {
		shape = rand() % SHAPE_RANGE;
		shapePercentage = rand() % SHAPE_PERCENTAGE;
		x = rand() % X_RANGE;
		y = rand() % Y_RANGE;
		width = rand() % WIDTH_RANGE;
		height = rand() % HEIGHT_RANGE;
		red = rand() % RED_RANGE;
		green = rand() % GREEN_RANGE;
		blue = rand() % BLUE_RANGE;
		iopacity = rand() % OPACITY_RANGE;
		opacity = (float)iopacity / 100.0;

		// print a table of the first few random numbers generated on console
		if (k < MAX_CONSOLE_LINES || k > noOfShapes-MAX_CONSOLE_LINES) {
			printf("%7d %7d %7d %7d %7d %7d %7d %7d %7d %7.2f\n", k, shape, x, y, width, height, red, green, blue, opacity);
		} /*if*/
        if (shapePercentage <= CIRCLE_PERCENTAGE) {
        	circle(ofp, x, y, width, red, blue, green, opacity);
        } else if (shapePercentage <= SQUARE_PERCENTAGE) {
        	square(ofp, x, y, width, red, blue, green, opacity);
        } else if (shapePercentage <= ELLIPSE_PERCENTAGE) {
       	ellipse(ofp, x, y, width, height, red, blue, green, opacity);
        } else if (shapePercentage <= RECTANGLE_PERCENTAGE) {
       	rectangle(ofp, x, y, width, height, red, blue, green, opacity);
        } else {
        	printf("No such shape %d\n", shape);
        } /*if*/

		k = k + 1;
	} /*while*/
} /*drawRandomArt*/

int main(void) {
	printf("Welcome\n");
	int frameX = 0;
	int frameY = 0;
	int canvasWidth = X_RANGE;
	int canvasHeight = Y_RANGE;
	int frameWidth = FRAME_WIDTH;
	int frameRed = FRAME_RED;
	int frameGreen = FRAME_GREEN;
    int framBlue =  FRAME_BLUE;
    float frameOpacity = 1.0;
	FILE* ofp = createHTML5SVGFile(OUTPUT_FILE_NAME, canvasWidth, canvasHeight);
	drawRandomArt(ofp, NO_SHAPES);
	frame(ofp, frameX, frameY, canvasWidth, canvasHeight, frameWidth, frameRed, frameGreen, framBlue, frameOpacity);
	closeHTML5SVGFile(ofp);
	printf("Bye bye\n");
	return EXIT_SUCCESS;
} /*main*/

