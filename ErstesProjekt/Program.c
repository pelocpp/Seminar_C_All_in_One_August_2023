#include <stdio.h>  // standard input & output 

// Funktions-Prototyp
void uebung_01_teufel();
void uebung_02_zinsen();

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

void main_blockschachtelung_mit_variablen()
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


void main_mit_continue_oder_break ()
{
	int n = 10;

	while (n >= 0) {

		// printf("bin hier\n");

		if (n == 5) {
			n--;
			continue;
		}

		printf("Wert von n = %d\n", n);
		n--;

		// etwas unvorhergesehenes ist eingetreten
		//if (n == 5) {
		//	break;
		//}
	}

	printf("Ende\n");
}

void main_two_divisions ()
{
	double d1, d2;

	d1 = 3.0;
	d2 = 6.0;

	double result = d1 / d2;

	printf("Result: %.2f / %.2f = %.2f\n", d1, d2, result);

	int i1, i2;

	i1 = 3;
	i2 = 6;

	int iresult = i1 / i2;

	printf("Result: %d / %d = %d\n", i1, i2, iresult);

	result = (double) i1 / i2;

	printf("Result: %d / %d = %.2f\n", i1, i2, result);
}

void main_for()
{
	// for die erste
	//for ( int i = 0 ; i < 3 ; i++ )
	//{
	//	printf("bin in der for-Schleife: %d\n", i);
	//}

	// =========================================

	// Varianten - für Extreme - ist eine Endlos Schleife
	// Embedded Devices kennen das
	//for ( ; ; )
	//{
	//	printf("bin in der for-Schleife\n");
	//}

	//// ist dasselbe wie
	//while (1) {

	//}

	// =========================================

	//int n = 0;
	//for ( ; n < 10 ; n = n + 2 )
	//{
	//	printf("bin in der for-Schleife: %d\n", n);
	//}

	// =========================================

	for ( int i = 0 ; i < 3 ; i++ )
	{
		printf("bin in der for-Schleife: %d\n", i);
	}

	// ist IDENTISCH zu 

	int i = 0;
	while (i < 3) {
		printf("bin in der for-Schleife: %d\n", i);
		i++;
	}
}

void main_post_pre_increment ()
{
	//int n = 10;

	//++n;
	//n++;

	//printf("n = %d\n", n);

	// ============================

	int n = 10;
	int m;

	m = ++n;     // Pre - Inkrement
	printf("m = %d\n", m);

	// oder 

	n = 10;
	m = n++;     // Post - Inkrement
	printf("m = %d\n", m);

	// ============================

    n = 10;

	n++;         // Inkrement
	m = n;       // Wertzuweisung
	printf("m = %d\n", m);

	// oder 

	n = 10;
	m = n;     // Wertzuweisung
	n++;       // Inkrement
	printf("m = %d\n", m);
}

void main()
{
	uebung_02_zinsen();
}
