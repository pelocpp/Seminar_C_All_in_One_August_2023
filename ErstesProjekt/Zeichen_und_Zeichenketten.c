// #define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h>  
#include <stdlib.h>  
#include <string.h>  

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

void replace(char* quelle, int pos, char ch) {

	int lenQuelle = str_length(quelle);

	if (pos >= lenQuelle) {
		return;
	}

	quelle[pos] = ch;
}

void test_replace()
{
	//  "ABCDE", an der Position 3 das 'D' durch ein '!' ersetzen ===> "ABC!E"

	// char* quelle = "ABCDE";  // VORSICHT !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	//                "ABCDE" liegt im Codesegment -- hier ist ein SCHREIBEN VERBOTEN / Absturz

	char quelle[] = "ABCDE";
	// Haben wir mit quelle ein Array, das am Stack liegt
	// Es wird "ABCDE" in das Array umkopiert, bzw. das Array damit vorgelegt.

	printf("Quelle: Vorher:  %s\n", quelle);

	replace(quelle, 5, '!');
	printf("Quelle: Nachher: %s\n", quelle);
}

// =====================================================

void insert(char* quelle, int pos, char ch, char ziel[]) {

	int lenQuelle = str_length(quelle);
	if (pos > lenQuelle) {
		return;
	}

	// copy first part of quelle to ziel
	int index = 0;
	for (; index < pos; ++index) {
		ziel[index] = quelle[index];
	}

	// copy character to insert into ziel
	ziel[index] = ch;

	// copy second part of quelle to ziel
	for (int i = index; i < lenQuelle; ++index, ++i) {
		ziel[i+1] = quelle[i];
	}

	// terminate ziel
	// ziel[index] = '\0';   // oder
	ziel[lenQuelle + 1] = '\0';
}

void test_insert()
{
	// "ABCDE"  , an der Position 3 ein '!' einfügen ===> "ABC!DE"
	char* quelle = "ABCDE";
	printf("Quelle: %s\n", quelle);

	char ziel[100];
	insert(quelle, 5, '!', ziel);
	printf("Ziel:   %s\n", ziel);
}

// =====================================================

void test_c_library_strlen()
{
	//int x = sizeof(int);
	//int y = sizeof(size_t);

	//int y1 = sizeof(long);
	//int y2 = sizeof(long long);

	char string1[] = "Das ist ein Test";   // am Stack als Array

	size_t length;

	length = strlen(string1);

	printf("Der String \"%s\" hat %lld Zeichen\n", string1, length);
}

void test_c_library_strcat()
{
	//// anhängen: to append oder to concatenate   => cat
	//// 
	//char text[20] = "Hallo!";
	//
	//printf("%s\n", text);

	//strcat(text, "Ja, du!");

	//printf("%s\n", text);
}

void test_c_library_strcat_secure()
{
	// anhängen: to append oder to concatenate   => cat
	// 
	char text[20] = "HALLO!";

	printf("%s\n", text);

	strcat_s(text, 20, "Ja, du!");   // statt 20 geht auch sizeof (text)

	printf("%s\n", text);
}

// =====================================================


void zeichen()
{
	test_c_library_strcat_secure();
}

