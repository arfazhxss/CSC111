/*
 *  Author:      Hausi A. Muller, Bill Bird, and D. Michael Miller
 *  UVicID:      V00123456
 *  Date:        Oct 19, 2013
 *  Assignment:  Assignment 6 Part 1
 *  File name:   a6p1template.c
 *  Description: Vector linear algebra functions
 *  Reference:   http://reference.wolfram.com/mathematica/tutorial/VectorsAndMatrices.html
 *  Reference:   http://reference.wolfram.com/mathematica/tutorial/VectorOperations.html
 *  Reference:   http://reference.wolfram.com/mathematica/guide/OperationsOnVectors.html
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <float.h>
/* constant FLT_EPSILON is defined in <float.h> */
#define BIG_EPSILON  (1.0)

typedef int Index;
typedef float Item;

#define VSIZE (4)
typedef Item Vector[VSIZE];

void setVector1(Vector V, Item x) {
	/* V = {x, y} */
	V[0] = x; V[1] = 0.0;	V[2] = 0.0; V[3] = 0.0;
} /* setVector1 */

void setVector2(Vector V, Item x, Item y) {
	/* V = {x, y} */
	V[0] = x; V[1] = y;	V[2] = 0.0; V[3] = 0.0;
} /* setVector2 */

void setVector3(Vector V, Item x, Item y, Item z) {
	/* V = {x, y, z} */
	V[0] = x; V[1] = y; V[2] = z; V[3] = 0.0;
} /* setVector3 */

void setVector4(Vector V, Item x, Item y, Item z, Item h) {
	/* V = {x, y, z} */
	V[0] = x; V[1] = y; V[2] = z; V[3] = h;
} /* setVector4 */

void printVector(Vector V, Index size) {
	/* output V[0], V[1], V[2], ..., V[size-1] */
	Index k;
	printf("   ");
	for (k=0; k<size; k++) printf("%.1f  ", V[k]);
	printf("\n");
} /* printVector */

void printVectorPrecise(Vector V, Index size) {
	/* output V[0], V[1], V[2], ..., V[size-1] */
	Index k;
	printf("   ");
	for (k=0; k<size; k++) printf("%.7f  ", V[k]);
	printf("\n");
} /* printVector */

bool equalVectors(Vector V1, Vector V2, Index size, Item eps) {
	/* return true if V1 == V2; false otherwise */
	Index k;
	for (k=0; k<size; k++) {
		if (fabs(V1[k]-V2[k]) > eps) {
			// Vectors are not equal
			return false;
		} /* if */
	} /* for */
	return true;
} /* equalVectors */

bool equalVectors2(Vector V1, Item x, Item y, Item eps) {
	/* return true if V1 == {x, y}; false otherwise */
	Index k;
	Vector V2 = {x, y};
	for (k=0; k<2; k++) {
		if (fabs(V1[k]-V2[k]) > eps) {
			printf("Vectors are not equal\n");
			return false;
		} /* if */
	} /* for */
	return true;
} /* equalVectors2 */

bool equalVectors3(Vector V1, Item x, Item y, Item z, Item eps) {
	/* return true if V1 == {x, y, z}; false otherwise */
	Index k;
	Vector V2 = {x, y, z};
	for (k=0; k<3; k++) {
		if (fabs(V1[k]-V2[k]) > eps) {
			printf("Vectors are not equal\n");
			return false;
		} /* if */
	} /* for */
	return true;
} /* equalVectors3 */

bool equalVectors4(Vector V1, Item x, Item y, Item z, Item h, Item eps) {
	/* return true if V1 == {x, y, z, h}; false otherwise */
	Index k;
	Vector V2 = {x, y, z, h};
	for (k=0; k<4; k++) {
		if (fabs(V1[k]-V2[k]) > eps) {
			printf("Vectors are not equal\n");
			return false;
		} /* if */
	} /* for */
	return true;
} /* equalVectors4 */

Item sumItems(Vector V, Index size) {
	/* return sum(V[0], V[1], V[2], ..., V[size-1]) */
	Index k;
	Item sum = 0.0;
	for (k=0; k<size; k++) sum += V[k];
	return sum;
} /* sumItems */

void initIndexVector(Vector V, Index size) {
	/*  V[0]=0, V[1]=1, V[2]=2, ..., V[size-1]=size-1) */
	Index k;
	for (k=0; k<size; k++) V[k] = (Item)k;
} /* initIndexVector */

void initVectorWithValue(Vector V, Index size, Item val) {
	/*  V[0]=val, V[1]=val, V[2]=val, ..., V[size-1]=val) */
	Index k;
	for (k=0; k<size; k++) V[k] = val;
} /* initVectorWithValue */

void allOnesVector(Vector V, Index size) {
	/*  V[0]=1, V[1]=1, V[2]=1, ..., V[size-1]=1) */
	initVectorWithValue(V, size, 1.0);
} /* allOnesVector */

void addScalarToVector(Vector V, Index size, Item s) {
	/*  V[0]=V[0]+s, V[1]+s, V[2]+s, ..., V[size-1]=V[size-1]+s) */
	Index k;
	for (k=0; k<size; k++) V[k] += s;
} /* addScalarToVector */

void mulVectorByScalar(Vector V, Index size, Item s) {
	/*  V[0]=V[0]*s, V[1]*s, V[2]*s, ..., V[size-1]=V[size-1]*s) */
	Index k;
	for (k=0; k<size; k++) V[k] *= s;
} /* mulVectorByScalar */

void addVectors(Vector V1, Vector V2, Vector V3, Index size) {
	/*  V3[0]=V1[0]+v2[0], V3[1]=V1[1]+v2[1], V3[2]=V1[2]+v2[2], ..., V3[size-1]=V1[size-1]+v2[size-1]) */
	Index k;
	for (k=0; k<size; k++) V3[k] = V1[k] + V2[k];
} /* addVectors */

void mulVectors(Vector V1, Vector V2, Vector V3, Index size) {
	/*  V3[0]=V1[0]*v2[0], V3[1]=V1[1]*v2[1], V3[2]=V1[2]*v2[2], ..., V3[size-1]=V1[size-1]*v2[size-1]) */
	Index k;
	for (k=0; k<size; k++) V3[k] = V1[k] * V2[k];
} /* mulVectors */

Item dotProduct(Vector V1, Vector V2, Index size) {
	/*  return sum(V1[0]*v2[0], V1[1]*v2[1], V1[2]*v2[2], ..., V1[size-1]*v2[size-1]) */
	Index k;
	Item sum = 0;
	for (k=0; k<size; k++) sum += V1[k] * V2[k];
	return sum;
} /* dotProduct */

Item vectorLength(Vector V, Index size) {
	/* also known as the L2 norm of a vector */
	/* return |V| = square-root(V[0]*v[0], V[1]*v[1], V[2]*v[2], ..., V[size-1]*v[size-1]) */
	Index k;
	Item sum = 0.0;
	for (k=0; k<size; k++) sum += V[k]*V[k];
	return sqrt(sum);
} /* vectorLength */

void normalizeVector(Vector V, Index size) {
	/* V[0]/|V|, V[1]/|V|, V[2]/|V|, ..., V[size-1]/|V| */
	/* use vectorLength routine to compute |V| */
	Item norm = vectorLength(V, size);
	mulVectorByScalar(V, size, 1.0/norm);
} /* normalizeVector */


int main(void) {
	Vector Vec1, Vec2, Vec3;
	Item m = 3.0;
	Item sum;
	Item dot;
	Item length;

	printf("Testing vector linear algebra functions\n");
	printf("Template Version 3\n\n");
	initIndexVector(Vec1, VSIZE);
	printf("Test initIndexVector\n");
	printf("   expected    0.0  1.0  2.0  3.0\n");
	printf("   computed ");
	printVector(Vec1, VSIZE);
	if (!equalVectors4(Vec1, 0.0, 1.0, 2.0, 3.0, FLT_EPSILON)) printf("   ==> initIndexVector error\n");

	addScalarToVector(Vec1, VSIZE, m);
	printf("Test addScalarToVector\n");
	printf("   expected    3.0  4.0  5.0  6.0\n");
	printf("   computed ");
	printVector(Vec1, VSIZE);
	if (!equalVectors4(Vec1, 3.0, 4.0, 5.0, 6.0, FLT_EPSILON)) printf("   ==> addScalarToVector error\n");

	mulVectorByScalar(Vec1, VSIZE, m);
	printf("Test mulVectorByScalar\n");
	printf("   expected    9.0  12.0  15.0  18.0\n");
	printf("   computed ");
	printVector(Vec1, VSIZE);
	if (!equalVectors4(Vec1, 9.0, 12.0, 15.0, 18.0, FLT_EPSILON)) printf("   ==> mulVectorByScalar error\n");

	initVectorWithValue(Vec1, VSIZE, m);
	printf("Test initVectorWithValue\n");
	printf("   expected    3.0  3.0  3.0  3.0\n");
	printf("   computed ");
	printVector(Vec1, VSIZE);
	if (!equalVectors4(Vec1, 3.0, 3.0, 3.0, 3.0, FLT_EPSILON)) printf("   ==> initVectorWithValue error\n");

	printf("Test sumItems\n");
	initIndexVector(Vec1, VSIZE);
	sum = sumItems(Vec1, VSIZE);
	printf("   expected    sum = 6.0\n");
	printf("   computed ");
	printf("   sum = %.1f\n", sum);
	if (fabs(sum - 6.0) > BIG_EPSILON) printf("   ==> sumItems error\n");

	printf("Test dotProduct\n");
	setVector4(Vec1, 1.0, 2.0, 3.0, 4.0);
	setVector4(Vec2, 1.0, 4.0, 6.0, 8.0);
	dot = dotProduct(Vec1, Vec2, VSIZE);
	printf("   expected    dotProduct = 59.0\n");
	printf("   computed ");
	printf("   dotProduct = %.1f\n", dot);
	if (fabs(dot - 59.0) > BIG_EPSILON) printf("   ==> dotProduct error\n");

	printf("Test addVectors\n");
	setVector4(Vec1, 1.0, 2.0, 3.0, 4.0);
	setVector4(Vec2, 1.0, 4.0, 6.0, 8.0);
	addVectors(Vec1, Vec2, Vec3, VSIZE);
	printf("   expected    2.0  6.0  9.0  12.0\n");
	printf("   computed ");
	printVector(Vec3, VSIZE);
	if (!equalVectors4(Vec3, 2.0, 6.0, 9.0, 12.0, FLT_EPSILON)) printf("   ==> addVectors error\n");

	printf("Test mulVectors\n");
	setVector4(Vec1, 1.0, 2.0, 3.0, 4.0);
	setVector4(Vec2, 1.0, 4.0, 6.0, 8.0);
	mulVectors(Vec1, Vec2, Vec3, VSIZE);
	printf("   expected    1.0  8.0  18.0  32.0\n");
	printf("   computed ");
	printVector(Vec3, VSIZE);
	if (!equalVectors4(Vec3, 1.0, 8.0, 18.0, 32.0, FLT_EPSILON)) printf("   ==> mulVectors error\n");

	printf("Test vectorLength\n");
	setVector4(Vec1, 1.0, 2.0, 3.0, 4.0);
	length = vectorLength(Vec1, VSIZE);
	printf("   expected    length = 5.5\n");
	printf("   computed ");
	printf("   length = %.1f\n", length);
	if (fabs(length - 5.5) > BIG_EPSILON) printf("   ==> vectorLength error\n");

	printf("Test normalizeVector\n");
	setVector4(Vec1, 1.0, 2.0, 3.0, 4.0);
	normalizeVector(Vec1, VSIZE);
	printf("   expected    0.2  0.4  0.5  0.7\n");
	printf("   computed ");
	printVector(Vec1, VSIZE);
	if (!equalVectors4(Vec1, 0.2, 0.4, 0.5, 0.7, BIG_EPSILON)) printf("   ==> normalizeVector error\n");

	printf("Test vectorLength\n");
	initIndexVector(Vec1, VSIZE);
	length = vectorLength(Vec1, VSIZE);
	printf("   expected    length = 3.7\n");
	printf("   computed ");
	printf("   length = %.1f\n", length);
	printVector(Vec1, VSIZE);
	if (fabs(length - 3.7) > BIG_EPSILON) printf("   ==> vectorLength error\n");

	printf("Test allOnesVector\n");
	allOnesVector(Vec1, VSIZE);
	length = vectorLength(Vec1, VSIZE);
	printf("   expected    length = 2.0\n");
	printf("   computed ");
	printf("   length = %.1f\n", length);
	printVector(Vec1, VSIZE);
	if (fabs(length - 2.0) > BIG_EPSILON) printf("   ==> allOnesVector error\n");

	printf("\nTemplate Version 4\n");
	printf("Bye bye\n");

	return EXIT_SUCCESS;
} /* main */
