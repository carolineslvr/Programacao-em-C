#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<cmath>
#include<cstring>

using namespace std;

int potencia (int b, int e);

main()
{
	setlocale (LC_ALL , "Portuguese");

	int base, expo;

	cout << "Informe a base: ";
	cin >> base;
	fflush (stdin);

	cout << "Informe o expoente: ";
	cin >> expo;
	fflush(stdin);

	cout << "O número " << base << " elevado a " << expo << " é igual a " << potencia(base, expo);

}

int potencia (int b, int e)
{
    if (e == 0)
    {
        return 1;

    } else
    {
        return b * potencia(b, (e -1));
    }
}
