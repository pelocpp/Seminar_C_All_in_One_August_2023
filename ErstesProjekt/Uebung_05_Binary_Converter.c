#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int computeNumberOfBits(int number)
{
	int count = 0;

	while ( number != 0 ) {
		number = number / 2;
		count++;
	}

	return count;
}

void printBinary(int* bits, int count)
{
	for (int i = 0; i < count; i++) {
		// printf("%d", bits[i]);
		printf("%d", * (bits + i));
	}
}

void convertBinary(int number, int* bits, int count)
{
	int index = 0;

	while ( number != 0 ) {

		// number = 13
		// compute bit
		int bit = number % 2;
		number = number / 2;

		// store bit in buffer
		bits[count - index - 1] = bit; 
		// oder
		// *(bits + count - index - 1) = bit;

		index++;
	}
}

void convertBinaryMain (int number)
{
	// a1) Anzahl der Bits bestimmen
	int count = computeNumberOfBits(number);

	// a2) Ich lege dynamisch Speicher an (Zeiger)
	int* buffer = malloc( count * sizeof (int) );

	// a3) rufe convertBinary mit der Zahl und dem Speicher
	// und der Länge des Speichers auf
	convertBinary(number, buffer, count);

	// a4) Gebe das Ergbis mit einer Funkion printBinary aus
	printBinary(buffer, count);

	free(buffer);
}

// ===========================================================

int* convertBinaryEx(int number, int* count)
{
	//  b1) Muss intern computeNumberOfBits aufrufen
	int numBits = computeNumberOfBits(number);

	// b2) Muss intern dynamisch Speicher anlegen (Zeiger)
	int* buffer = malloc(numBits * sizeof(int));

	// b3) Muss das Ergebnis im Speicher ablegen (Berechnung)
	int index = 0;
	while (number != 0) {

		// compute bit
		int bit = number % 2;
		number = number / 2;

		// store bit in buffer
		buffer[numBits - index - 1] = bit;
		index++;
	}

	// b4) Liefert das Ergebnis(Speicher plus Länge) zurück
	*count = numBits;
	return buffer;
}

// ===========================================================


void test_01() {

	int count = computeNumberOfBits(13);
	count = computeNumberOfBits(12345);
}

void test_02() {

	convertBinaryMain(12345);
}

void test_03() {

	int numBits = 0;

	int* buffer = convertBinaryEx(13, &numBits);
	
	printBinary(buffer, numBits);
}


void uebung_05_binary_converter()
{
	test_03();
}