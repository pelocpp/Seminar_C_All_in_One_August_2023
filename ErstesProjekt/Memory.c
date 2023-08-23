#include <stdio.h>  

void func_01();
void func_02();
void func_03();

int g_var_1 = 123;
int g_var_2 = 456;

void zaehleEinsDazu(int n)
{
	n++;
}

void test_zaehleEinsDazu()
{
	int x;

	x = 123;

	zaehleEinsDazu(x);

	printf("x = %d\n", x);
}

void zaehleEinsDazu_ZumZweiten(int* n)
{
	(*n)++;

	// oder

	// ++*n;  // Oki doki ...
}

void test_zaehleEinsDazu_ZumZweiten()
{
	int x;

	x = 123;

	zaehleEinsDazu_ZumZweiten( &x );

	printf("x = %d\n", x);
}


void func_01()
{
	int x = 1;

	func_02();
}

void func_02()
{
	int y = 2;

	func_03();
}

void func_03()
{
	int z = 3;
}

void memory_zum_ersten()
{
	func_01();
}

void memory()
{
	test_zaehleEinsDazu_ZumZweiten();
}

