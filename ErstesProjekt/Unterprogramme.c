#include <stdio.h>  // standard input & output 

// Definition einer globalen Variablen
int globaleVariable = 123;

// 1. Beispiel:
// Prozedur

void verwendeGlobaleVariable()
{
	printf("Wert von globaleVariable: %d\n", globaleVariable);
}

void verwendeAuchGlobaleVariable()
{
	globaleVariable++;
}

void hauptprogramm()
{
	verwendeGlobaleVariable();
	verwendeAuchGlobaleVariable();
	verwendeGlobaleVariable();
	verwendeAuchGlobaleVariable();
	verwendeGlobaleVariable();
	verwendeAuchGlobaleVariable();
}

void ausgabe ( int anzahl )
{
	for (int i = 0; i < anzahl; i++) {
		printf("%2d: Ich bin ein Unterprogramm\n", (i+1) );
	}
	printf("\n");
}

// 2. Beispiel:
// Funktion

int malDrei( int wert) {

	int ergebnis;

	ergebnis = wert * 3;

	return ergebnis;
}

int doSomething(int wert) {

    // rechnet, rechnet , rechnet .... FEHLER

	// exit(123);

	return 1;
}

int doSomethingZwei(int wert, int* result) {

	// rechnet, rechnet , rechnet .... FEHLER

	// exit(123);

	return 1;   // Zwei Wert; 1 == okay, 0 = Fehler
}

// Beobachtung: Python kann in einem Tupel mehrere Werte zurückliefern ...
// 
// Das könnten wir auch ähnlich in C machen: Ein struct entspricht einem Tupel 

void hauptprogramm_fuer_funktionen ()
{
	int result;

	result = malDrei(5);

	// int wasIstDas = printf("5 mal 3 = %d\n", result);
	
	printf("5 mal 3 = %d\n", result);
}

void hauptprogramm_fuer_prozeduren()
{
	int wieOft = 5;

	ausgabe(wieOft);

	wieOft = 3;
	ausgabe(wieOft);

	wieOft = 1;
	ausgabe(wieOft);
}
