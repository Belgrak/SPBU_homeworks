#ifndef SPBU_C_HOMEWORKS_BINARY_H
#define SPBU_C_HOMEWORKS_BINARY_H

typedef int* bin;

int binToDec(bin binaryCode);
bin decToBin(int number);
bin binToBinsComplement(bin binaryCode);
bin binSummation(bin firstBin, bin secondBin);
bin binsComplementToBin(bin binaryCode);
bin decToBinsComplement(int number);
void binaryPrint(bin binaryCode, char* comment);
bin leftShift(bin binaryCode, int count);
int multiply(bin firstBin, bin secondBin);

#endif // SPBU_C_HOMEWORKS_BINARY_H
