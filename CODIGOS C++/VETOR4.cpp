#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<cmath>
#include<cstring>

using namespace std;

void gerar (int *pvet, int *pvet2, int **pn, int **pn2);
void mostrar (int *pvet, int *pvet2, int *pn, int *pn2);
void tercvet (int *pvet, int *pvet2, int *pn, int *pn2);

main()
{
	setlocale (LC_ALL , "Portuguese");

	int *n = new int;
	int *n2 = new int;


	cout << "Informe o número de elementos do primeiro vetor: ";
	cin >> *n;
	fflush(stdin);

    int *vet = new int[*n];

    cout << "Informe o número de elementos do sengundo vetor: ";
    cin >> *n2;
    fflush(stdin);

    int *vet2 = new int[*n2];

    gerar (vet, vet2, &n, &n2);
    mostrar (vet, vet2, n, n2);
    tercvet (vet, vet2, n, n2);

}

void gerar (int *pvet, int *pvet2, int **pn, int **pn2)
{
    srand(time(NULL));

    int *i = new int;
    int *j = new int;
    int *k = new int;
    int *l = new int;
    int *aux = new int;
    int *igual = new int(0);
    int *aux2 = new int;
    int *igual2 = new int(0);


    for (*i = 0; *i < **pn; (*i)++)
    {
        *aux = rand() % ((**pn) * (**pn2));
        if (*i == 0)
        {
            *(pvet + *i) = *aux;

        } else
        {
            *igual = 0;
            for (*k = 0; *k < *i; (*k)++)
            {
                if (*(pvet + *k) == *aux)
                {
                    (*igual)++;

                    break;
                }
            }
            if (*igual == 0)
            {
                *(pvet + *k) = *aux;

            } else
            {
                (*i)--;
            }

        }
    }

    delete i;

    for (*j = 0; *j < **pn2; (*j)++)
    {
        *aux2 = rand() % ((**pn) * (**pn2));
        if (*j == 0)
        {
            *(pvet2 + *j) = *aux2;

        } else
        {
            *igual2 = 0;
            for (*l = 0; *l < *j; (*l)++)
            {
                if (*(pvet2 + *l) == *aux2)
                {
                    (*igual2)++;

                    break;
                }
            }
            if (*igual2 == 0)
            {
                *(pvet2 + *l) = *aux2;

            } else
            {
                (*j)--;
            }

        }

    }
    delete j;
}

void mostrar (int *pvet, int *pvet2, int *pn, int *pn2)
{
    int *i = new int;
    int *j = new int;

    cout << "\nPrimeiro vetor formado pelos elementos:\n";

    for (*i = 0; *i < *pn; (*i)++)
    {
        cout << *pvet << ", ";

        pvet++;
    }

    pvet -= *pn;

    delete i;

    cout << "\n\nSegundo vetor formado pelos elementos:\n";

    for (*j = 0; *j < *pn2; (*j)++)
    {
        cout << *pvet2 << ", ";

        pvet2++;
    }
    delete j;

    pvet2 -= *pn2;
}

void tercvet (int *pvet, int *pvet2, int *pn, int *pn2)
{
    int *i = new int;
    int *j = new int;
    int *cont = new int(0);
    int *pvet3 = new int[(*pn) + (*pn2)];


     cout << "\n\nTerceiro vetor formado pelos elementos:\n";


    for (*i = 0; *i < *pn; (*i)++)
    {
        for (*j = 0; *j < *pn2; (*j)++)
        {
            if (pvet[*i] == pvet2[*j])
            {
                (*cont)++;
                *pvet3 = pvet[*i];

                 cout << *pvet3 << ", ";

                pvet3++;
            }
        }
    }

    pvet3 -= *cont;
}
