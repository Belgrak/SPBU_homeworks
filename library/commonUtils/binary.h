#ifndef SPBU_C_HOMEWORKS_BINARY_H
#define SPBU_C_HOMEWORKS_BINARY_H

int binToDec(const int* binaryCode);
int* decToBin(int number);
int* binToBinsComplement(int* binaryCode);
int* binSummation(const int* firstBin, const int* secondBin);
int* binsComplementToBin(int* binaryCode);
int* decToBinsComplement(int number);
void binaryPrint(int* binaryCode, char* comment);
int* leftShift(int* binaryCode, int count);
int* rightShift(int* binaryCode, int count);
int multiply(int* firstBin, int* secondBin);

#endif // SPBU_C_HOMEWORKS_BINARY_H