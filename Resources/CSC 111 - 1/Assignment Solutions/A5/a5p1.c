/*
 *  Author:      Hausi A. Muller
 *  UVicID:      V00123456
 *  Date:        Oct 5, 2013
 *  Lecture:     Assignment 5
 *  File name:   a5p1.c
 *  Description: Generate a simple HTML5 SVG file.
 */

#include <stdio.h>
#include <stdlib.h>

/* prototypes */
FILE* createSVGfile(char* fnam, int width, int height);
void closeHTML5SVGfile(FILE* ofp);
void frame(FILE* ofp, int x, int y, int width, int height, int frameWidth, int r, int g, int b, float op);
void circle(FILE* ofp, int cx, int cy, int radius, int r, int g, int b, float op);
void square(FILE* ofp, int x, int y, int width, int r, int g, int b, float op);
void rectangle(FILE* ofp, int x, int y, int width, int height, int r, int g, int b, float op);
void ellipse(FILE* ofp, int cx, int cy, int rx, int ry, int r, int g, int b, float op);
void drawRandomArt(FILE* ofp);
int main(void);

FILE* createSVGfile(char* fnam, int width, int height) {
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
} /*createSVGfile*/

void closeHTML5SVGfile(FILE* ofp) {
	fprintf(ofp, "\t\t</svg>\n");
	fprintf(ofp, "\t</body>\n");
	fprintf(ofp, "</html>\n");
	fclose(ofp);
} /*closeHTML5SVGfile*/

void frame(FILE* ofp, int x, int y, int width, int height, int frameWidth, int r, int g, int b, float op) {
	fprintf(ofp, "\t\t\t<rect x=\"%d\" y=\"%d\" width=\"%d\" height=\"%d\" style=\"fill: none; stroke-width: %d; stroke:rgb(%d,%d,%d); stroke-opacity:%.1f;\" />\n", x, y, width, height, frameWidth, r, g, b, op);
} /*frame*/

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

void drawRandomArt(FILE* ofp) {
	circle(ofp, 350, 100, 100, 0, 255, 0, 1.0);
	square(ofp, 50, 150, 100, 0, 255, 255, 0.8);
	ellipse(ofp, 200, 100, 175, 75, 0, 0, 255, 0.6);
	rectangle(ofp, 200, 200, 300, 75, 255, 0, 0, 1.0);
} /*drawRandomArt*/

int main(void) {
	printf("Welcome\n");
	int frameX = 0;
	int frameY = 0;
	int canvasWidth = 500;
	int canvasHeight = 300;
	int frameWidth = 5;
	int frameRed = 255;
	int frameGreen = 51;
    int framBlue = 153;
    float frameOpacity = 1.0;
	FILE* ofp = createSVGfile("a5p1.html", canvasWidth, canvasHeight);
	drawRandomArt(ofp);
	frame(ofp, frameX, frameY, canvasWidth, canvasHeight, frameWidth, frameRed, frameGreen, framBlue, frameOpacity);
	closeHTML5SVGfile(ofp);
	printf("Bye bye\n");
	return EXIT_SUCCESS;
} /*main*/





