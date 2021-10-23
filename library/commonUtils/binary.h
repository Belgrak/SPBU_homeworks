#ifndef SPBU_C_HOMEWORKS_BINARY_H
#define SPBU_C_HOMEWORKS_BINARY_H

int binToDec(const int* binaryCode);
int* decToBin(int number);
int* binToTwosComplement(int* binaryCode);
int* binSummation(const int* firstBin, const int* secondBin);
int* twosComplementToBin(int* binaryCode);
int* decToTwosComplement(int number);
void binaryPrint(int* binaryCode, char* comment);
int* leftShift(int* binaryCode, int count);
int* rightShift(int* binaryCode, int count);

#endif // SPBU_C_HOMEWORKS_BINARY_H
