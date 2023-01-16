#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<cmath>
#include<cstring>

using namespace std;

void gerar (int **pvet);
void mostrar (int **pvet);
void contrario (int **pvet);

main()
{
	setlocale (LC_ALL , "Portuguese");

	int *vet = new int[10];

	gerar(&vet);
	mostrar(&vet);
	getchar();
	contrario(&vet);
}

void gerar (int **pvet)
{
    srand(time(NULL));
    int *i = new int;

    for (*i = 0; *i < 10; (*i)++)
    {
        **pvet = rand() % 26 + 30;

        (*pvet)++;
    }
    delete i;
    (*pvet)-= 10;
}

void mostrar (int **pvet)
{
     int *i = new int;

     cout << "\nVetor formado pelos valores:\n\n";

     for (*i = 0; *i < 10; (*i)++)
    {
        cout << **pvet << ", ";

        (*pvet)++;
    }
    delete i;
}

void contrario (int **pvet)
{
    int *i = new int;
    int *j = new int;
    int *pvaux = new int[10];

    cout << "\n\nVetor invertido:\n\n";

     for (*i = 9; *i >= 0; (*i)--)
    {
        (*pvet)--;

        *pvaux = **pvet;
        pvaux++;
    }
    delete i;
    pvaux -= 10;

    for (*j = 0; *j < 10; (*j)++)
    {
        **pvet = *pvaux;

        cout << **pvet << ", ";
        pvaux++;
        (*pvet)++;

    }
    pvaux -= 10;
    *pvet -= 10;

    cout << endl;
}

