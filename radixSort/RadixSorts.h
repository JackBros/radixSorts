#pragma once

static void floatRadixSort(float in[], int size) {
	long* arr = new long[size];
	long* arr2 = new long[size];
	int* bucket = new int[2048];

	for (int i = 0; i < size; i++)
		arr[i] = *(long*)&in[i];

	for (int shift = 0; shift < 22; shift += 11)
	{
		for (int i = 0; i <= 0x7ff; i++)
			bucket[i] = 0;

		for (int i = 0; i < size; i++)
			bucket[arr[i] >> shift & 0x7ff]++;

		for (int i = 0x7ff; i > 0; i--)
			bucket[i - 1] += bucket[i];

		for (int i = size - 1; i >= 0; i--)
			arr2[--bucket[arr[i] >> shift & 0x7ff]] = arr[i];

		long* tmp = arr;
		arr = arr2;
		arr2 = tmp;
	}

	for (int i = 0; i <= 0x1ff; i++)
		bucket[i] = 0;

	for (int i = 0; i < size; i++)
		bucket[arr[i] >> 22 & 0x1ff]++;

	for (int i = 0x1ff; i > 0; i--)
		bucket[i - 1] += bucket[i];

	for (int i = size - 1; i >= 0; i--)
		arr2[--bucket[arr[i] >> 22 & 0x1ff]] = arr[i];

	bucket[0] = 0;
	bucket[1] = 0;

	for (int i = 0; i < size; i++)
		bucket[arr2[i] >> 31 & 1]++;

	bool p;
	int b;

	for (int i = size - 1; i >= 0; i--)
	{
		p = arr2[i] >> 31 & 1;
		b = --bucket[p];
		in[b - p * (b + b - size + 1)] = *(float*)&arr2[i];
	}

	delete[] arr;
	delete[] arr2;
	delete[] bucket;

	
}