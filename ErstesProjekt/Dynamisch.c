#include <stdio.h>  
#include <stdlib.h>  

void dynamisch_zum_Ersten()
{
	// Speicher reservieren bzw. verfügbar machen

	// Speicher für 1 int Wert dynamisch anfordern

	// malloc erwartet eine Angabe in Bytes

	int anzahlBytesEinesInt = sizeof(int);  // meistens 4

	int* var = malloc(anzahlBytesEinesInt);  
	
	// implizit: Typkonvertierung von void* nach int* statt

	// Wie kann ich nun diesen Speicher verwenden ???

	*var = 123;

	free(var);
}

void dynamisch_zum_Zweiten()
{
	// Speicher reservieren bzw. verfügbar machen

	// Speicher für 1 int Wert dynamisch anfordern

	// malloc erwartet eine Angabe in Bytes

	int anzahlBytesEinesInt = sizeof(int);  // meistens 4

	int* var = malloc(anzahlBytesEinesInt);

	if (var == NULL) {

		printf("Habe keinen Speicher erhalten");

		exit(1);
	}
	else {

		// dynamischen Speicher verwendet
		*var = 123;

		// wir benötigen diesen nicht mehr
		free(var);
	}
}

int wieLangSollDasFeldSein()
{
	// komplizierte Berechnung .........
	return 10;
}

void dynamisch_zum_Dritten()
{
	// Feld: hat eine FESTE Länge // statisch
	int numbers[10];

	//const int n = 10;
	//n = wieLangSollDasFeldSein();
	//int zahlen2[n];

	// Feld dynamischer Länge: Geht doch
	int n = wieLangSollDasFeldSein();

	// Feld dynamischer Länge von int- Werten:
	// malloc reserviert einen beliebig langen Speicherbereich:
	// dieser kann als ein Feld betrachtet werden.
	// Beispiel: Länge ist 40 Bytes ====>  Entspricht 10 int Werten
	// Entspricht einem int-Array der Länge 10
	int* zahlen = malloc( n * sizeof (int) );   // n = 10

	if (zahlen == NULL) {
		return;
	}

	int* testZeiger = zahlen + 3;

	// Wie greife ich auf dieses Feld zu ?????????????????????
	// Da gibt es mehrere Möglichkeiten:

	// Beispiel: Feld mit den Zahlen 0, 1, 2, 3, ... vorbelegen

	// 1. Möglichkeit: Zeiger Arithmetik
	for (int i = 0; i < 10; i++) {

		// Addition: Zeiger + int-Wert
		* (zahlen + i) = i;
	}

	// 2. Möglichkeit: In einer anderen Schreibweise 
	// - mit eckigen Klammern: Index-Operator
	for (int i = 0; i < 10; i++) {

		zahlen[i] = i;
	}
}

void test_dynamisch()
{
	dynamisch_zum_Dritten();
}
