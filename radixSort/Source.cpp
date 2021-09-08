#include <iostream>
#include "RadixSorts.h"
#include "RandAndTimers.h"

using std::cout;
using std::endl;

#define length 10000000

void testUnsignedIntSort() {
	unsigned int* unsignedIntArr = new unsigned int[length];

	for (int i = 0; i < length; i++)
		unsignedIntArr[i] = intRand();

	startTimer();
	unsignedIntRadixSort(unsignedIntArr, length);
	cout << "unsigned int sort took " << stopTimer() << " seconds" << endl;

	for (int i = 1; i < length; i++)
		if (unsignedIntArr[i - 1] < unsignedIntArr[i])
			cout << "Error, " << unsignedIntArr[i - 1] << " < " << unsignedIntArr[i] << endl;

	delete[] unsignedIntArr;
}

void testIntSort() {
	int* intArr = new int[length];

	for (int i = 0; i < length; i++)
		intArr[i] = intRand();

	startTimer();
	intRadixSort(intArr, length);
	cout << "int sort took " << stopTimer() << " seconds" << endl;

	for (int i = 1; i < length; i++)
		if (intArr[i - 1] < intArr[i])
			cout << "Error, " << intArr[i - 1] << " < " << intArr[i] << endl;

	delete[] intArr;
}

void testFloatSort() {

	float* floatArr = new float[length];

	for (int i = 0; i < length; i++)
		floatArr[i] = 100 * (doubleRand() - 0.5);

	startTimer();
	floatRadixSort(floatArr, length);
	cout << "float sort took " << stopTimer() << " seconds" << endl;

	for (int i = 1; i < length; i++)
		if (floatArr[i - 1] < floatArr[i])
			cout << "Error, " << floatArr[i - 1] << " < " << floatArr[i] << endl;

	delete[] floatArr;
}

void testDoubleSort() {
	double* doubleArr = new double[length];

	for (int i = 0; i < length; i++)
		doubleArr[i] = 100 * (doubleRand() - 0.5);

	startTimer();
	doubleRadixSort(doubleArr, length);
	cout << "double sort took " << stopTimer() << " seconds" << endl;

	for (int i = 1; i < length; i++)
		if (doubleArr[i - 1] < doubleArr[i])
			cout << "Error, " << doubleArr[i - 1] << " < " << doubleArr[i] << endl;

	delete[] doubleArr;
}

void main() {
	testUnsignedIntSort();
	testIntSort();
	testFloatSort();
	testDoubleSort();
}