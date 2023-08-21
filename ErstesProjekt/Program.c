#include <stdio.h>  // standard input & output 

// Einsprungpunkt
void main_hello_world()
{
	// Ausgabe auf die Konsole
	printf("Hello World\n");
}

// ==================================

void main_datentyp_und_variable()
{
	// Datentyp und Variable

	int zahl = 1;

	int zahlZwei;

	zahlZwei = zahl;

	// zahl = 123;
}


void main_if_die_erste ()
{
	// Kontrollstruktur

	int a = 1;
	int b = 2;

	// ...
	// 1. Variante
	if ( a > b ) {
		printf("a ist groesser als b\n");
	}

	// 2. Variante
	if (a > b) {
		printf("a ist groesser als b\n");
	}
	else {
		printf("a ist nicht groesser als b\n");
	}

	// 3. Variante
	if (a > b) {
		printf("a ist groesser als b\n");
	}

	if (a < b) {
		printf("a ist kleiner als b\n");
	}

	if (a == b) {
		printf("a und b sind gleich\n");
	}

	// 3. Variante
	// BESSER
	if (a > b) {
		printf("a ist groesser als b\n");
	}
	else if (a < b) {  // <=
		printf("a ist kleiner als b\n");
	}
	else if (a == b) {
		printf("a und b sind gleich\n");
	}

	printf("Ende von main");
}

void main_mit_logischen_operatoren ()
{
	// Kontrollstruktur

	int a = 1;
	int b = 2;
	int c = 10;
	int d = 11;

	// int whoKnows;

	int x  = 1 + 2 * 3;
	// identisch !!!
	int x1 = (1 + 2) * 3;

	// 1. Beispiel
	if ( a > b || c > d ) {
		printf("Bedingung ist erfuellt\n");
	}

	if ( ! ( a  > b ) ) {
		printf("Bedingung ist erfuellt\n");
	}

	// Operatoren Vorrang versus Assoziativität

	int z = 1 - 2 - 3; // -4 vs +2

	int z1, z2, z3, z4;

	z1 = z2 = (z3 = (z4 = 1));

	printf("Ende von main");
}


void main_typ_konvertierung()
{
	int a = 11;

	int b = 12;

	double d = 123.756;

    // Wertzuweisung // Assignment
	// Links und rechts: Variablen DESSELBEN Datentyps !
	a = b;

	// d = a;  // double = int

	a = (int) d;  // int = double
}


void main_while_die_erste()
{
	int n = 10;

	while ( n >= 0 ) {

		printf("Wert von n = %d\n", n);

		n = n - 1;
		// oder = ist identisch mit
		n--;
	}

	printf("Ende\n");
}

void main_while_mit_schachtelung ()
{
	int n = 10;

	while ( n >= 0 ) {

		printf("Wert von n = %d\n", n);

		if ( (n % 2) == 0 ) {
			printf("  n is even\n");
		}
		else {
			printf("  n is not even\n");
		}

		n--;
	}

	printf("Ende\n");
}

void main()
{
	int n = 10;

	while (n >= 0) {

		int ergebnis = 0;

		int n = 5;   // Ohhhhhhhhhhhhhhh bzw.aus Versehen

		printf("Wert von n = %d\n", n);

		ergebnis = n % 2;
		if (ergebnis == 0) {
			printf("  n is even\n");
		}
		else {
			printf("  n is not even\n");
		}

		printf("Wert von otto = %d\n", ergebnis);
		n--;
	}

	// printf("Wert von otto = %d\n", ergebnis);

	printf("Ende\n");
}