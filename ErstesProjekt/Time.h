#pragma once

// struct declarations
struct Time
{
	int hours;
	int minutes;
	int seconds;
};

// functions prototypes
void printTime(const struct Time* t);

void initTime(struct Time* t, int hours, int minutes, int seconds);

void incrementTime(struct Time* t);
