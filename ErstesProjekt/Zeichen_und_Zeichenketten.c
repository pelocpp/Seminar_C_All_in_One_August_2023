#include <stdio.h>  

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

void zeichen()
{
	zeichenkette_zum_zweiten();
}

