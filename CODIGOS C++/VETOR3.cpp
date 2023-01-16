#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<cmath>
#include<cstring>

using namespace std;

void gera (int *pvet, int *pvet2, int *pvet3, int **px, int **px2);
void mostra (int *pvet, int *pvet2, int *pvet3, int *px, int *px2);
void ordemcr (int *pvet3, int *px, int *px2);
void maior (int *pvet3, int *px, int *px2);

main()
{
	setlocale (LC_ALL , "Portuguese");

	int *x = new int;
	int *x2 = new int;

	cout << "Informe o número de elementos do primeiro vetor: ";
	cin >> *x;
	fflush(stdin);

    int *pv = new int[*x];

    cout << "Informe o número de elementos do sengundo vetor: ";
    cin >> *x2;
    fflush(stdin);

    int *pv2 = new int[*x2];

    int *pv3 = new int[*x + *x2];

    gera(pv, pv2, pv3, &x, &x2);
    mostra(pv, pv2, pv3, x, x2);
    getchar();
    ordemcr(pv3, x, x2);
    getchar();
    maior(pv3, x, x2);

}

void gera (int *pvet, int *pvet2, int *pvet3, int **px, int **px2)
{
    srand(time(NULL));

    int *i = new int;
    int *z = new int;
    int *y = new int;
    int *w = new int;

     for (*i = 0; *i < **px; (*i)++)
    {
        *(pvet + *i) = rand() % 100;
    }
    delete i;

     for (*z = 0; *z < **px2; (*z)++)
    {
        *(pvet2 + *z) = rand() % 100;
    }
    delete z;

    for (*y = 0; *y < **px; (*y)++)
    {
        *(pvet3 + *y) = *(pvet + *y);
    }
    delete y;

     for (*w = 0; *w < **px2; (*w)++)
    {
       pvet3[*w + **px] = pvet2[*w];
    }
    delete w;


}

void mostra (int *pvet, int *pvet2, int *pvet3, int *px, int *px2)
{
    int *j = new int;
    int *k = new int;
    int *l = new int;

    cout << "\n\nVetor número 1:\n\n";

    for (*j = 0; *j < *px; (*j)++)
    {
        cout << *pvet << ", ";

        pvet++;
    }
    delete j;

     cout << "\n\nVetor número 2:\n\n";

     for (*k = 0; *k < *px2; (*k)++)
    {
        cout << *pvet2 << ", ";

        pvet2++;
    }
    delete k;

    cout << "\n\nVetor número 3:\n\n";

     for (*l = 0; *l < *px + *px2; (*l)++)
    {
        cout << *pvet3 << ", ";

        pvet3++;
    }
    delete l;
    pvet3 -= *px + *px2;

}

void ordemcr (int *pvet3, int *px, int *px2)
{
   int *l = new int;
   int *k = new int;
   int *b = new int(*px + *px2);
   int *aux = new int;
   int *a = new int;

    for (*l = 0; *l < *b - 1; (*l)++)
    {
        for (*k = *l + 1; *k < *b; (*k)++)
        {
            if (pvet3[*l] > pvet3[*k])
            {
                *aux = pvet3[*l];
                pvet3[*l] = pvet3[*k];
                pvet3[*k] = *aux;
            }
        }

    }
    delete l;
    delete k;

    cout << "\n\nVetor em ordem crescente:\n\n";

     for (*a = 0; *a < *px + *px2; (*a)++)
    {
        cout << *pvet3 << ", ";

        pvet3++;
    }

    pvet3 -= *px + *px2;
}

void maior (int *pvet3, int *px, int *px2)
{
    int *i = new int;
    int *e = new int;
    int *maior = new int;
    int *menor = new int;

    for (*i = 0; *i < *px + *px2; (*i)++)
    {
        if (*i == 0)
        {
            *maior = *(pvet3 + *i);

        } else if (*(pvet3 + *i) > *maior)
        {
            *maior = *(pvet3 + *i);
        }
    }
    delete i;

     for (*e = 0; *e < *px + *px2; (*e)++)
    {
        if (*e == 0)
        {
            *menor = *(pvet3 + *e);

        } else if (*(pvet3 + *e) < *menor)
        {
            *menor = *(pvet3 + *e);
        }
    }
    delete e;

    cout << "\n\nMaior número presente no vetor: " << *maior;
    cout << "\n\nMenor número presente no vetor: " << *menor;


}



