#define _CRT_SECURE_NO_WARNINGS 

// CRT = C Runtime Library

#include <stdio.h>  
#include <stdlib.h>  

#define BUFFER_SIZE 100

void uebung_07_statistik()
{
	char* fileName = "C:\\PeterLoos\\ErstesProjekt\\Eine_TextDatei.txt";

	FILE* fp;

	int statistik[127] = { 0 };   // Feld zum Zählen aller Ascii Codes

	fp = fopen(fileName, "r");

	if (fp == NULL) {

		printf("Kann Datei %s nicht finden!\n", fileName);
		exit(1);
	}
	else {
		printf("Datei %s geoeffnet!\n", fileName);

		// die gesamte Datei auslesen
		// 

		char buffer[BUFFER_SIZE];
		int ascii;

		while (1) {

			char* result = fgets(buffer, BUFFER_SIZE, fp);

			// keine Zeile mehr erhalten
			if (result == NULL) {
				break;
			}

			// traversiere Zeile von Anfang bis Ende
			int pos = 0;
			while (buffer[pos] != '\0') {

				ascii = buffer[pos];  // int Variable ==> ASCII Code 
				statistik[ascii]++;   // Zähler des entsprechenden Zeichens um 1 erhöhen !

				pos++;
			}
		}

		fclose(fp);

		// suche häufigstes Zeichen
		int maxAscii = -1;
		int maxCounter = 0;
		for (int i = 0; i < 127; i++) {

			// Wenn man das Blank nicht möchte ...
			if (i == 32) {
				continue;
			}

			if (statistik[i] > maxCounter) {
				maxAscii = i;
				maxCounter = statistik[i];
			}
		}

		printf("Haeufigstes Zeichen: \'%c\' = %d // Vorkommen: %d\n",
			maxAscii, maxAscii, maxCounter);
	}
}
