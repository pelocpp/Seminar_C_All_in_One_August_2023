#include <stdio.h>

extern int str_length(char* quelle);

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
		ziel[i + 1] = quelle[i];
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

void uebung_06_strings()
{
	test_replace();
	test_insert();
}