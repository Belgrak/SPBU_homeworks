#ifndef SPBU_C_HOMEWORKS_VECTOR_H
#define SPBU_C_HOMEWORKS_VECTOR_H

typedef struct Vector Vector;

Vector* makeNewVector(const int* data);
int getScalarProduct(Vector* firstVector, Vector* secondVector, int defaultValue);
int getVectorLength(Vector* vector);
Vector* vectorSummation(Vector* firstVector, Vector* secondVector);
Vector* vectorSubtraction(Vector* firstVector, Vector* secondVector);

void vectorFree(Vector* vector);

#endif // SPBU_C_HOMEWORKS_VECTOR_H
