// #define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Modellierung eines einzelnen Kontakts
struct contact
{
	char* firstName;
	char* lastName;
    
	int phoneNumber;

	unsigned char empty;   // ist der eintrag benutzt oder leer: 0 == leer, 1 == belegt
}; 

typedef struct contact Contact;

#define BUFFER_SIZE  64
#define MAX_CONTACTS 32

// Funktionsprototypen
void printContacts();
void enterContact();
void clearContacts();

// Datenhaltung für Kontakte (32 Kontakte möglich)
struct contact contacts[MAX_CONTACTS];

void uebung_08_kontakte_menu()
{
	for (int i = 0; i < MAX_CONTACTS; i++) {
		contacts[i].empty = 0;   // Variable 'empty':  Guard / Wächter
		
		// contacts[i].firstName = NULL;
	}


	int fertig = 1;   // 1 == nicht fertig, 0 ist fertig

	while (fertig != 0) {

		// printf - menu :)
		printf("\n\n"); 
		printf("Meine Kontakte:\n\n");
		printf("Bitte Aktion waehlen:\n");
		printf("(1) = Kontakte ausgeben\n");
		printf("(2) = Kontakt eingeben\n");
		printf("(3) = Alle Kontakte loeschen\n");
		printf("(4) = Programm verlassen\n");

		int aktion = -1;
		scanf_s("%d", &aktion, 4);

		switch (aktion)
		{
		case 1:
			printContacts();
			break;
		case 2:
			enterContact();
			break;
		case 3:
			clearContacts();
			break;
		case 4:
			clearContacts();
			fertig = 0;
			break;
		default:
			printf("Menue unbekannt: %d\n", aktion);
			break;
		}
	}
}

void uebung_08_kontakte_vorbereitung_01 ( int slot )
{
	Contact test;

	// Eingabe von der Konsole:

	printf("Geben Sie den Vornamen ein: ");
	char buffer[BUFFER_SIZE] = { '\0' };
	// Liest eine Zeile bis zum Drücken der Return Tast ein
	// fgets(buffer, sizeof buffer, stdin);
	scanf_s("%s", buffer, BUFFER_SIZE);
	fflush(stdin);

	// Vornamen in einem dynamisch angelegten Puffer ablegen:
	//
	int len = (int) strlen(buffer);  // Wie lange ist der Vorname
	char* tmp = malloc( len + 1 );   // Puffer auf dem Heap / Halde anlegen
	
	if (tmp == NULL) {
		printf("No Memory.");
		exit(-1);
	}

	strcpy_s(tmp, len + 1, buffer);  // Puffer von Stack auf Heap umkopieren
	test.firstName = tmp;            // Adresse des Vornamens in Contact eintragen
	
	printf("Geben Sie den Nachnamen ein: ");
	scanf_s("%s", buffer, BUFFER_SIZE);
	fflush(stdin);

	// Nachnamen in einem dynamisch angelegten Puffer ablegen:
    //
	len = (int)strlen(buffer);  // Wie lange ist der Nachname
	tmp = malloc(len + 1);      // Puffer auf dem Heap / Halde anlegen

	if (tmp == NULL) {
		printf("No Memory.");
		exit(-1);
	}

	strcpy_s(tmp, len + 1, buffer); // Puffer von Stack auf Heap umkopieren
	test.lastName = tmp;            // Adresse des Nachnamens in Contact eintragen

	// Telefonnummer eingeben:
    //
	int tmpPhone = -1;
	printf("Geben Sie die Telefonnummer ein: ");
	
	// Variante 1:
	//int read = scanf_s("%d", &tmpPhone, sizeof(int));
	//if (read == 0) {

	//	printf("Achtung: Falsches Format für Telefonnummer !!!");
	//}

	// Variante 2:
	// EMPTY INPUT BUFFER !!!!!
	fgets(buffer, sizeof buffer, stdin);

	// read input from keyboard
	fgets(buffer, sizeof buffer, stdin);

	// remove '\n' !!!!!!!!!
	int lenBuf = strlen(buffer);
	buffer[lenBuf - 1] = '\0';
	lenBuf--;

	// verify phone number:
	for (int k = 0; k < lenBuf; k++) {
		if (!isdigit(buffer[k])) {

			printf("Wrong Input !!!");
		}
	}

	// Zeichenkette in ganze Zahl umwandeln
	tmpPhone = atoi(buffer);

	test.phoneNumber = tmpPhone;

	// ------------------------------------------
	// Die Struktur test enthält nun einen vollständigen Eintrag:
	// Beachte:  Strukturen können 1:1 kopiert werden
	// Kopiere temporäre Struktur test in das globale Feld contacts um:
	
	// Markiere 'test' als belegt
	test.empty = 1;

	contacts[slot] = test;

	// Achtung: Kein free ... Vorbereitung
}

void printContacts() {

	printf("Meine Kontakte:\n");

	for (int i = 0; i < MAX_CONTACTS; i++) {

		if (!(contacts[i].empty == 0)) {

			printf("   Vorname:  %s\n", contacts[i].firstName);
			printf("   Nachname: %s\n", contacts[i].lastName);
			printf("   Phone:    %d\n", contacts[i].phoneNumber);
			printf("\n");

		}
	}
}

void enterContact()
{
	// a) Wo ist ein freier Platz im Array
	int index = -1;
	for (int i = 0; i < MAX_CONTACTS; i++) {

		if (contacts[i].empty == 0) {

			index = i;
			break;
		}
	}

	uebung_08_kontakte_vorbereitung_01(index);
}

void clearContacts() {

	for (int i = 0; i < MAX_CONTACTS; i++) {

		if (contacts[i].empty == 1) {

			free(contacts[i].firstName);
			free(contacts[i].lastName);

			contacts[i].empty = 0;
		}
	}
}

void uebung_08_kontakte()
{
	uebung_08_kontakte_menu();
}
