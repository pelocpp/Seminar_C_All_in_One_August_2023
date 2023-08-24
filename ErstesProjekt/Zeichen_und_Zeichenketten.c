#include <stdio.h>  
#include <stdlib.h>  

void zeichen_zum_ersten()
{
	char ch = 'A';

	char ch1 = '\\';   // Sonderzeichen:  \  n = new Line  t = tabulator

	char ch2 = '?';

	char ch4 = 0;   // NULL Zeichen == terminierendes NULL Zeichen
	// oder
	char ch5 = '\0';


	// char ch3 = '0x22';

	printf("%c und %c und %c\n", ch, ch1, ch2);
}

void zeichen_zum_zweiten()
{
	char ch;

	int n;

	ch = 50;

	n = '?';

	n = ch;

	ch = n;

	ch = 64;

	printf("ch = %c\n", ch);
}

void zeichen_zum_dritten()
{
	for (int i = 0; i <= 255; ++i) {

		printf("%d: %c\n", i, i);
	}
}

void zeichenkette_zum_ersten()
{
	int n = 50;

	const char* kette = "ABC";

	// Wording: 

	// Länge von kette:              3
	// Anzahl der Bytes im Speicher: 4
}

void zeichenkette_zum_zweiten()
{
	// Konstante Zeichenketten
	const char* kette = "ABC";

	printf("kette: %s\n", kette);

	// Nicht konstante Zeichenkette für "ABC"
	char kette2[10];   // 4 wäre der kleins-mögliche korrekte Wert - NICHT 3

	kette2[0] = 'A';
	kette2[1] = 'B';
	kette2[2] = 'C';
	kette2[3] = '\0';  // oder = 0;

	printf("kette2: %s.\n", kette2);
}

// ===================================================

int str_length(char* s)
{
	int index = 0;

	while ( s[index] != '\0') {

		index++;
	}

	return index;
}

void test_str_length()
{
	int len = str_length("ABC");
	printf("len = %d\n", len);

	len = str_length("");
	printf("len = %d\n", len);
}

// ===================================================

void str_append (char* ursprung, char* s, char buffer[])
{
	//i)   In buffer habe ich Platz für das Ergebnis
	//ii)  Erst Quelle nach buffer umkopieren

	int index = 0;
	while (ursprung [index] != '\0') {

		buffer[index] = ursprung[index];

		index++;
	}

	// iii) Dann s nach buffer umkopieren
	int indexFuerS = 0;

	while (s[indexFuerS] != '\0') {

		buffer[index] = s[indexFuerS];

		indexFuerS++;
		index++;
	}

	// iV)  Am Ende eine terminierende Null noch ergänzen.
	buffer[index] = '\0';
}

void test_append()
{
	//                   "ABC"   "XYZ"         Wohin / Ziel

	char ziel[100];

	str_append("ABC", "XYZ", ziel);
}

void test_append_optimized()  // bzgl. Speicherplatz
{
	char* ursprung = "ABC";
	char* s = "XYZ";

	int lenUrsprung = str_length(ursprung);
	int lenS = str_length(s);

	// char ziel[100];
	// ACHTUNG: Ein char für das NULL-Byte nicht vegessen
	char* ziel = malloc( (lenUrsprung + lenS + 1) * sizeof(char) );

 	str_append(ursprung, s, ziel);

	free(ziel);
}

// =====================================================

void zeichen()
{
	test_append_optimized();
}

