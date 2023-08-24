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

void files()
{
	file_die_erste();
}