#include <stdio.h>  

void func_01();
void func_02();
void func_03();

int g_var_1 = 123;
int g_var_2 = 456;

void tauscheZweiWerte_zumDritten(int* n, int* m)
{
	int tmp = *n;   // indirekter Zugriff // Gebrauch des Verweis Operators *
	*n = *m;        // ZWEIMAL  indirekter Zugriff : links und rechts
	*m = tmp;
}

void tauscheZweiWerte_zumZweiten(int* n, int* m)
{
	int tmp1 = *n;   // indirekter Zugriff // Gebrauch des Verweis Operators *
	int tmp2 = *m;

	*m = tmp1;       // indirekter Zugriff // Gebrauch des Verweis Operators *
	*n = tmp2;
}

void test_tauscheZweiWerte_zumZweiten()
{
	int x = 5;
	int y = 6;

	tauscheZweiWerte_zumZweiten( &x, &y );

	printf("%d - %d", x, y);  // ===========> 6 - 5
}



void tauscheZweiWerte(int n, int m)
{
	int tmp1 = n;
	int tmp2 = m;

	m = tmp1;
	n = tmp2;
}

void test_tauscheZweiWerte()
{
	int x = 5;
	int y = 6;

	tauscheZweiWerte(x, y);

	printf("%d - %d", x, y);  // ===========> 6 - 5
}




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
	test_tauscheZweiWerte_zumZweiten();
}

