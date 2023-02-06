#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<cmath>
#include<cstring>

using namespace std;

float harmonico(int n);

main()
{
	setlocale (LC_ALL , "Portuguese");

	int num;

	cout << "Digite o n�mero: ";
	cin >> num;
	fflush(stdin);

	cout << "N�mero harm�nico: " << harmonico(num);
}

float harmonico(int n)
{
    if (n == 1)
    {
        return 1;

    } else
    {
        return (1.0 / (float)n + harmonico(n -1));
    }
}
