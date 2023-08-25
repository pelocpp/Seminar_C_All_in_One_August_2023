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

void initTime(struct Time t, int hours, int minutes, int seconds)
{

}

void strukturen_die_erste()
{
	//int uhrzeit[3];
	//uhrzeit[0] = 9;   // Neeeeeeeeeeeeeeee

	struct Time jetzt;
	struct Time mittagsPause;

	jetzt.hours = 9;
	jetzt.minutes = 20;
	jetzt.seconds = 37;

	mittagsPause.hours = 12;
	mittagsPause.minutes = 0;
	mittagsPause.seconds = 0;

	// Unterprogramm ....
	initTime();

	int aktuelleStunde = jetzt.hours;
}

void strukturen()
{
	strukturen_die_erste();
}
