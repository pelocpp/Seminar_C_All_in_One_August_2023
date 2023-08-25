#include <stdio.h>
#include <math.h>

#include "Vector.h"

// list of all functions:
// function prototypes (Funktionsprototyp)
//void vectorInit(double vector[], int len);
//double vectorLength(double vector[], int len);
//void vectorNormalize(double result[], double vec[], int len);
//void vectorAdd(double result[], double vec1[], double vec2[], int len);
//void vectorSub(double result[], double vec1[], double vec2[], int len);
//void vectorScalarMul(double result[], double vec[], int len, double scalar);
//double vectorScalarProduct(double vec1[], double vec2[], int len);
//int isEqual(double vec1[], double vec2[], int len);
//int isUnequal(double vec1[], double vec2[], int len);
//void vectorPrint(double vector[], int len);

// implementation
void vectorInit(double vector[], int len)
{
    for (int i = 0; i < len; i++) {
        vector[i] = 0.0;
    }
}

double vectorLength(double vector[], int len)
{
    double result = 0.0;

    for (int i = 0; i < len; i++) {
        result += vector[i] * vector[i];
    }

    result = sqrt(result);

    return result;
}

void vectorNormalize(double result[], double vec[], int len)
{
    double norm = 1.0 / vectorLength(vec, len);

    //  normalize vector
    for (int i = 0; i < len; i++) {
        result[i] = vec[i] * norm;
    }
}

void vectorAdd(double result[], double vec1[], double vec2[], int len)
{
    for (int i = 0; i < len; i++) {
        result[i] = vec1[i] + vec2[i];
    }
}

void vectorSub(double result[], double vec1[], double vec2[], int len)
{
    for (int i = 0; i < len; i++) {
        result[i] = vec1[i] - vec2[i];
    }
}

void vectorScalarMul(double result[], double vec[], int len, double scalar)
{
    for (int i = 0; i < len; i++) {
        result[i] = vec[i] * scalar;
    }
}

double vectorScalarProduct(double vec1[], double vec2[], int len)
{
    double result = 0.0;

    for (int i = 0; i < len; i++) {
        result += vec1[i] * vec2[i];
    }

    return result;
}

int isEqual(double vec1[], double vec2[], int len)
{
    for (int i = 0; i < len; i++) {
        if (vec1[i] != vec2[i]) {
            return 0;
        }
    }

    return 1;
}

int isUnequal(double vec1[], double vec2[], int len)
{
    return ! isEqual(vec1, vec2, len);
}

void vectorPrint(double vec[], int len)
{
    printf("{ ");

    for (int i = 0; i < len - 1; i++) {
        printf("%.3f, ", vec[i]);
    }

    printf("%.3f }", vec[len - 1]);
}

void uebung_04_vector()
{
    double vector[3];
    double vector1[3] = { 3, 6,  8 };
    double vector2[3] = { 8, 16, 23 };
    double result[3];

    // testing vector initialization (zero vector)
    vectorInit(vector, 3);
    vectorPrint(vector, 3);
    printf("\n");

    // testing vector length
    double length = vectorLength(vector1, 3);
    vectorPrint(vector1, 3);
    printf(": Length = %.3f\n", length);

    // testing vector normalization
    vectorNormalize(result, vector1, 3);
    printf("Normalized: ");
    vectorPrint(result, 3);
    length = vectorLength(result, 3);
    printf(": Length = %.3f\n", length);

    // testing vector addition
    vectorAdd(result, vector1, vector2, 3);
    vectorPrint(vector1, 3);
    printf(" + ");
    vectorPrint(vector2, 3);
    printf(" = ");
    vectorPrint(result, 3);
    printf("\n");

    // testing scalar multiplication
    vectorScalarMul(result, vector1, 3, 10.0);
    printf(" 10 ");
    printf(" * ");
    vectorPrint(vector1, 3);
    printf(" = ");
    vectorPrint(result, 3);
    printf("\n");

    // testing scalar product
    double product = vectorScalarProduct(vector1, vector2, 3);
    vectorPrint(vector1, 3);
    printf(" * ");
    vectorPrint(vector2, 3);
    printf(" = %lf  [scalar product]\n", product);

    // testing vector comparison
    int comparison = isEqual(vector1, vector2, 3);
    vectorPrint(vector1, 3);
    printf(" == ");
    vectorPrint(vector2, 3);
    printf(" : %d\n", comparison);

    comparison = isUnequal(vector1, vector2, 3);
    vectorPrint(vector1, 3);
    printf(" != ");
    vectorPrint(vector2, 3);
    printf(" : %d\n", comparison);

    comparison = isEqual(vector1, vector1, 3);
    vectorPrint(vector1, 3);
    printf(" == ");
    vectorPrint(vector1, 3);
    printf(" : %d\n", comparison);
}