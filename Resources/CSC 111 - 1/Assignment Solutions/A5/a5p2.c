/*
 *  Author:      Hausi A. Muller and D. Michael Miller
 *  UVicID:      V00123456
 *  Date:        Oct 5, 2013
 *  Lecture:     Assignment 5 Part 2
 *  File name:   A5P22013.c
 *  Description: Generate random numbers for CSC 111 Art.
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

#define NO_SHAPES 20

#define X_RANGE 800
#define Y_RANGE 400
#define SHAPE_RANGE 4
#define WIDTH_RANGE 80
#define HEIGHT_RANGE 40
#define RED_RANGE 256
#define GREEN_RANGE 256
#define BLUE_RANGE 256
#define OPACITY_RANGE 100

#define OUTPUT_FILE_NAME "a5p2randomnumbers.txt"

void outputRandomNumbers(FILE* ofp, int n) {
	int k = 0;       // count number of shapes generated
	int shape = 0;   // random shape: rectangle or circle
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
	fprintf(ofp, "Table of random numbers for drawing geometric shapes in different colours, sizes and opacities\n");
	printf("%7s %7s %7s %7s %7s %7s %7s %7s %7s %7s\n",
			"shape#", "RSCE", "x", "y", "width", "height", "red", "green", "blue", "opacity");
	fprintf(ofp, "%7s %7s %7s %7s %7s %7s %7s %7s %7s %7s\n",
			"shape#", "RSCE", "x", "y", "width", "height", "red", "green", "blue", "opacity");
	while (k < n) {
		shape = rand() % SHAPE_RANGE;
		x = rand() % X_RANGE;
		y = rand() % Y_RANGE;
		width = rand() % WIDTH_RANGE;
		height = rand() % HEIGHT_RANGE;
		red = rand() % RED_RANGE;
		green = rand() % GREEN_RANGE;
		blue = rand() % BLUE_RANGE;
		iopacity = rand() % OPACITY_RANGE;
		opacity = (float)iopacity / 100.0;

		// print a table of random numbers generated on console
        printf("%7d %7d %7d %7d %7d %7d %7d %7d %7d %7.2f\n", k, shape, x, y, width, height, red, green, blue, opacity);
        fprintf(ofp, "%7d %7d %7d %7d %7d %7d %7d %7d %7d %7.2f\n", k, shape, x, y, width, height, red, green, blue, opacity);

		k = k + 1;
	} /*while*/
} /*outputRandomNumbers*/

int main(void) {
	FILE *ofp;   // output file

	ofp = fopen(OUTPUT_FILE_NAME, "w");
	if (ofp == NULL) {
		printf("Cannot open output file %s\n", OUTPUT_FILE_NAME);
		exit(EXIT_FAILURE);
	} /* if */

	outputRandomNumbers(ofp, NO_SHAPES);

	fclose(ofp);
	return EXIT_SUCCESS;
} /* main */
