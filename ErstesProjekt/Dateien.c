#define _CRT_SECURE_NO_WARNINGS 
 
// CRT = C Runtime Library

#include <stdio.h>  
#include <stdlib.h>  

#define BUFFER_SIZE 100

void file_die_erste()
{
	char* fileName = "C:\\PeterLoos\\ErstesProjekt\\Eine_TextDatei.txt";

	FILE* fp;

	fp = fopen(fileName, "r");

	if (fp == NULL) {

		printf("Kann Datei %s nicht finden!\n", fileName);
		exit(1);
	}
	else {
		printf("Datei %s geoeffnet!\n", fileName);

		// die gesamte Datei auslesen
		// 

		int lineCounter = 1;

		char buffer[BUFFER_SIZE];
		char* result;

		while (   (result = fgets(buffer, BUFFER_SIZE, fp)) != NULL  ) {

			printf("%03d: %s", lineCounter,  buffer);

			lineCounter++;
		}

		fclose(fp);
	}
}

void file_vorbereitung_uebung()
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

		int lineCounter = 1;

		char buffer[BUFFER_SIZE];
		char* result;

		fgets(buffer, BUFFER_SIZE, fp);

		// Auswerten des ersten Zeichens der Zeile
		int ascii = buffer[0];
		statistik[ascii]++;   // Zähler des 35.-ten Zeichens in diesem Beispiel um 1 erhöhen !
		
		// Auswerten aller Zeichen EINER Zeile / der ersten Zeile
		int index = 0;

		while (buffer[index] != '\0') {

			ascii = buffer[index];  // int Variable ==> ASCII Code 
			statistik[ascii]++;     // Zähler des entsprechenden Zeichens um 1 erhöhen !
		
			index++;
		}

		fclose(fp);
	}
}


void files()
{
	file_vorbereitung_uebung();
}