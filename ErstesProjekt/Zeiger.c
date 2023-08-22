#include <stdio.h>  

void zeiger_wie_groß_ist_ein_int()
{
    // wieviele Bytes benötigt ein int im Speicher
    int anzahlBytesProInt = sizeof(int);
}

void zeiger_zum_ersten()
{
    // Variablen Vereinbarung: Einer int Variable
    int n = 123;

    n = 456;
    // Direkter Variablen Zugriff == 1 MOV Befehl

    // Variablen Vereinbarung: Einer Zeiger Variable
    int* ip = NULL;

    // Adresse von n ermitteln // Anweisung
    // Adress-Operator
    ip =  &n;

    // Wert 789 in n schreiben - ohne 'n' zu benutzen // Anweisung
    // Indirekter Zugriff: Eine Zeigervariable (ip) de-referenzieren 
    // Verweis - Operator
    *ip = 789;
    // Indirekter Variablen Zugriff == 2 MOV Befehle
}

void zeiger()
{
    zeiger_zum_ersten();

    printf("bin hier\n");
}

// ================================================================