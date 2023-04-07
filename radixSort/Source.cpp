#include <iostream>
#include "RadixSorts.h"
#include "RandAndTimers.h"
#include <fstream>
#include <stdio.h>
#include <sstream>
#include <conio.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <typeinfo>

using std::cout;
using std::endl;
using namespace std;

//#define length 10

void testFloatSort() {
	int diziSec, length;
	flag1:
	cout << "1) 10'luk dizi" << endl;
	cout << "2) 100'luk dizi" << endl;
	cout << "3) 100000'lik dizi" << endl;
	cin >> diziSec;
	cout << "--------------------------------------------------------------------" << endl;
	if (diziSec == 1) {
		length = 10;

		float* floatArr = new float[length];
		float sayi1;
		int dosya1Elemansayisi = 0;
		ifstream dosyaOku("10lukliste.txt");
		string karakter;

		if (dosyaOku.is_open()) {

		} while (dosya1Elemansayisi != 10) {
			dosyaOku >> karakter;
			sayi1 = stof(karakter);
			floatArr[dosya1Elemansayisi] = sayi1;
			dosya1Elemansayisi++;
		}

		dosyaOku.close();

		startTimer();
		floatRadixSort(floatArr, length);
		cout << "float sort took " << stopTimer() << " seconds" << endl;
		for (int y = 0; y < 10; y++) {
			cout << floatArr[y] << endl;
		}
		for (int i = 1; i < length; i++)
			if (floatArr[i - 1] < floatArr[i])
				cout << "Error, " << floatArr[i - 1] << " < " << floatArr[i] << endl;

		delete[] floatArr;
		
	}
	else if (diziSec == 2)
	{
		length = 100;

		float* floatArr = new float[length];
		float sayi1;
		int dosya1Elemansayisi = 0;
		ifstream dosyaOku("100lükliste.txt");
		string karakter;

		if (dosyaOku.is_open()) {

		} while (dosya1Elemansayisi != 100) {
			dosyaOku >> karakter;
			sayi1 = stof(karakter);
			floatArr[dosya1Elemansayisi] = sayi1;
			dosya1Elemansayisi++;
		}

		dosyaOku.close();

		startTimer();
		floatRadixSort(floatArr, length);
		cout << "float sort took " << stopTimer() << " seconds" << endl;
		for (int y = 0; y < 100; y++) {
			cout << floatArr[y] << endl;
		}
		for (int i = 1; i < length; i++)
			if (floatArr[i - 1] < floatArr[i])
				cout << "Error, " << floatArr[i - 1] << " < " << floatArr[i] << endl;

		delete[] floatArr;
	}
	else if (diziSec == 3) {
		length = 100000;

		float* floatArr = new float[length];
		float sayi1;
		int dosya1Elemansayisi = 0;
		ifstream dosyaOku("100000likliste.txt");
		string karakter;

		if (dosyaOku.is_open()) {

		} while (dosya1Elemansayisi != 100000) {
			dosyaOku >> karakter;
			sayi1 = stof(karakter);
			floatArr[dosya1Elemansayisi] = sayi1;
			dosya1Elemansayisi++;
		}

		dosyaOku.close();

		startTimer();
		floatRadixSort(floatArr, length);
		cout << "float sort took " << stopTimer() << " seconds" << endl;
		for (int y = 0; y < 100000; y++) {
			cout << floatArr[y] << endl;
		}
		for (int i = 1; i < length; i++)
			if (floatArr[i - 1] < floatArr[i])
				cout << "Error, " << floatArr[i - 1] << " < " << floatArr[i] << endl;

		delete[] floatArr;
	}
	else
	{
		cout << "Hatali Secim!!" << endl;
		goto flag1;
	}
}


void main() {
	testFloatSort();
	int secimEkrani;
flag2:
	cout << "--------------------------------------------------------------------" << endl;
	cout << "1) Cikis" << endl;
	cout << "2)Tekrar Secim" << endl;
	cin >> secimEkrani;
	if (secimEkrani == 2) {
		testFloatSort();
		goto flag2;
	}
	else if (secimEkrani == 1) {
		exit(0);
	}
	else {
		cout << "Hatali Secim!!" << endl;
		goto flag2;
	}
}