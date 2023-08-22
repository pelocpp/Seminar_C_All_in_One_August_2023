#include <stdio.h>  

void array_zum_ersten ()
{
    int zahlen [10];

    zahlen[0] = 123;

    zahlen[3] = 456;

    //VORSICHT

    // [0],  [1], .......  [ 9 ]    

    for (int i = 0; i < 10; ++i) {

        zahlen[i] = 123 + i;
    }

    // oder 

    for (int i = 0; i <= 9; ++i) {

        zahlen[i] = 456 + i;
    }
}

void array_mit_falschem_index_zugriff (int index)
{
    int zahlen[10];

    if (index < 0 || index >= 10) {

        printf("Achtung: FALSCHER Index: %d\n", index);

        // das Unterprogramm verlassen
        return;
    }

    zahlen[index] = 123;
}

#define LENGTH  10

const int Length = 10;

void array_einfache_demo()
{
    // array definiere
    int zahlen[LENGTH];

    // array füllen / schreiben
    for (int i = 0; i < LENGTH; i++) {
        zahlen[i] = 2 * i;
    }

    // array lesen
    for (int i = 0; i < LENGTH; i++) { 
        printf("%d: %d\n", i, zahlen[i]);
    }
}

// =====================================================

// Prozedur
void fillArray( int feld[], int length, int vorbelegungsWert ) {

    for (int i = 0; i < length ; i++) {
        feld[i] = vorbelegungsWert;
    }
}

// Funktion:
int sumOfElementsOfArray(int feld[], int length)
{
    int result = 0;

    for (int i = 0; i < length; i++) {
        result += feld[i];
        // result = result + feld[i];
    }

    return result;
}

void multiplyElementsOfArrayByTwo(int feld[], int length)
{
    for (int i = 0; i < length; i++) {
        feld[i] = feld[i] * 2;
    }
}

//void multiplyElementByTwo(int element)
//{
//    element = element * 2;
//}

// Unterprogramm
void printArray(int feld[], int length) {
    for (int i = 0; i < length; i++) {
        printf("%d: %d\n", i, feld[i]);
    }
}

void array_einfache_demo_zum_zweiten()
{
    // array definiere
    int zahlen[10];
    int summe;

    // array füllen / schreiben
    fillArray(zahlen, 10, 123);
    printArray(zahlen, 10);

    multiplyElementsOfArrayByTwo(zahlen, 10);
    printArray(zahlen, 10);

    summe = sumOfElementsOfArray(zahlen, 10);
    printf("Summe aller Elemente: %d\n", summe);

    // array lesen / ausgeben
    printArray(zahlen, 10);
}

void arrays()
{
    array_einfache_demo_zum_zweiten();

    printf("bin hier\n");
}
