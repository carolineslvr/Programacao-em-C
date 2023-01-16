#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<cmath>
#include<cstring>

using namespace std;

void gerar(int **pvet, int **px);
void mostrar (int **pvet, int **px);
void fmaior (int **pvet, int **px);

main()
{
	setlocale (LC_ALL , "Portuguese");

	int *x = new int;

	cout << "Informe o número de elementos presentes no vetor: ";
	cin >> *x;
	fflush(stdin);

	int *vet = new int[*x];

	gerar(&vet, &x);
	mostrar(&vet, &x);
	getchar();
	fmaior(&vet, &x);


}

void gerar(int **pvet, int **px)
{
    srand(time(NULL));

    int *i = new int;

    for (*i = 0; *i < **px; (*i)++)
    {
        **pvet = rand() % 50;

        (*pvet)++;
    }
    (*pvet) -= **px;

    delete i;
}

void mostrar (int **pvet, int **px)
{
    int *i = new int;

    cout << "Vetor formado pelos elementos:\n\n";

    for (*i = 0; *i < **px; (*i)++)
    {
        cout << **pvet << ", ";

        (*pvet)++;
    }
    (*pvet) -= **px;

    delete i;
}

 void fmaior (int **pvet, int **px)
 {
     int *i = new int;
     int *j = new int;
     int *maior = new int;
     int *cont = new int(0);

     for (*i = 0; *i < **px; (*i)++)
     {
         if (*i == 0)
         {
             *maior = **pvet;

         } else if (**pvet > *maior)
         {
             *maior = **pvet;

         }

         (*pvet)++;
     }
     delete i;

     *pvet -= **px;

      for (*j = 0; *j < **px; (*j)++)
     {
         if (*maior == **pvet)
         {
             (*cont)++;
         }
         (*pvet)++;
     }
     delete j;
    *pvet -= **px;

     cout << "\n\nO maior elemento do vetor é " << *maior << " e aparece no vetor " << *cont << " vezes";
 }
