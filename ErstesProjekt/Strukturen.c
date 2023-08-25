#include <stdio.h>  

#include "Time.h"
#include "Vector.h"
#include "Common.h"

// 1. Beispiel:

struct Student
{
	char vorname[32];
	char nachname[32];
	int alter;
	int immatrikulations_nummer;
	// etc. etc.

	struct Adresse
	{
		char wohnort[32];
	};
};

// Uhrzeit
//struct Time
//{
//	int hours;
//	int minutes;
//	int seconds;
//};

void printTime(const struct Time* t)
{
	// t->seconds = 59;
	int wievieleSekunden = t->seconds;

	printf("%02d:%02d:%02d\n", t->hours, t->minutes, t->seconds);
}

void incrementTime(struct Time* t)
{
	// very, very simple --- mostly wrong
	t->seconds = t->seconds + 1;
}

void initTime(struct Time* t, int hours, int minutes, int seconds)
{
	//t.hours = hours;
	//t.minutes = minutes;
	//t.seconds = seconds;

	//(*t).hours = hours;
	//(*t).minutes = minutes;
	//(*t).seconds = seconds;

	// ist identisch:
	t->hours = hours;
	t->minutes = minutes;
	t->seconds = seconds;
}

void strukturen_uebung()
{
	struct Time t;

	initTime(&t, 11, 12, 58);
	printTime(&t);

	incrementTime(&t);
	printTime(&t);

	incrementTime(&t);
	printTime(&t);

}

void strukturen_die_erste()
{
	//int uhrzeit[3];
	//uhrzeit[0] = 9;   // Neeeeeeeeeeeeeeee

	struct Time jetzt;
	struct Time mittagsPause;

	jetzt.hours = 0;   // bitte mal diese Zeilen ignorieren
	jetzt.minutes = 0;
	jetzt.seconds = 0;
	printTime(&jetzt);

	initTime(&jetzt, 9, 20, 37);  // hier habe ich die relevanten Daten erhalten
	printTime(&jetzt);

	mittagsPause.hours = 12;
	mittagsPause.minutes = 0;
	mittagsPause.seconds = 0;

	int aktuelleStunde = jetzt.hours;
}

void strukturen()
{
	strukturen_uebung();
}
