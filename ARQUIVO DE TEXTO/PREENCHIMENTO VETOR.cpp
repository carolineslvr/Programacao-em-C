#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<cmath>
#include<cstring>
#include<fstream>

using namespace std;

void gerar (int v[], int tam);
void escrever (int vet[], int tam);
void excluir (int vet[], int tam, int v2[], int &posicao);
void mostrar (int tam, int vet2[], int &posicao);

main()
{
	setlocale (LC_ALL , "Portuguese");

	int t, p;

	cout << "Informe o tamanho do vetor: ";
	cin >> t;

	int vetor[t], vetor2[t];

	gerar(vetor, t);
	escrever(vetor, t);
	getchar();
	excluir(vetor, t, vetor2, p);
	getchar();
	getchar();
	mostrar(t, vetor2, p);
}

void gerar (int v[], int tam)
{
    srand(time(NULL));

    int i, x, aux, igual;

    for (i = 0; i < tam; i++)
    {
         aux = rand () % 500;

         if(i == 0)
         {
             v[i] = aux;
         } else
         {
             igual = 0;

             for (x = 0; x < i; x++)
             {
                 if (v[x] == aux)
                 {
                     igual ++;
                     break;
                 }
             }
             if (igual == 0)
             {
                 v[i] = aux;
             } else
             {
                 i--;
             }
         }
    }
}

void escrever (int vet[], int tam)
{
    int i, j, aux;

    for (i = 0; i < tam; i++)
    {
        for (j = i + 1; j < tam; j++)
        {
           if (vet[i] > vet[j])
           {
                aux = vet[i];
                vet[i] = vet[j];
                vet[j] = aux;
           }
        }
    }

    ofstream escrita("valores.txt", ios::out);

    if (escrita.is_open())
    {
        for (i = 0; i < tam; i++)
        {
            if (i == 0)
            {
                escrita << vet[i];

            } else
            {
                escrita << ", " << vet[i];
            }
        }
        cout << "\nValores gerados e escritos no arquivo:\n";

         for (i = 0; i < tam; i++)
         {
             cout << vet[i] << ", ";
         }

    } else
    {
        cout << "\nErro ao abrir o arquivo!\n";
    }

    escrita.close();
}

void excluir (int vet[], int tam, int v2[], int &posicao)
{
    int i, x, j, k;

    cout << "\n\nInforme o valor que deseja excluir: ";
    cin >> x;

    for (i = 0; i < tam; i++)
    {

        v2[i] = vet[i];

        if (vet[i] == x)
        {
           posicao = i;

        }
    }
    if (posicao >= 0 && posicao < tam)
    {
        for (j = posicao; j < tam - 1; j++)
        {
            v2[j] = vet[j + 1];
        }

        ofstream escrita("valores.txt", ios::out);

        if (escrita.is_open())
        {
            for (k = 0; k < tam - 1; k++)
            {
                if (k == 0)
                {
                    escrita << v2[k];

                } else
                {
                    escrita << ", " << v2[k];
                }

            }

        cout << "\n\nValor excluído com sucesso!\n";

        } else
        {
            cout << "\nErro ao abrir o arquivo!\n";
        }
            escrita.close();
    } else
    {
        cout << "\nValor digitado não existe no vetor!";
    }
}

void mostrar (int tam, int vet2[], int &posicao)
{
    int y, z;

    cout << "\nDados no arquivo:\n";

    ifstream leitura("valores.txt", ios::in);

     if (leitura.is_open())
     {
         if(posicao >= 0 && posicao < tam)
         {
             for (y = 0; y < tam - 1; y++)
                {
                    cout << vet2[y] << ", ";
                }
         } else
         {
            for (z = 0; z < tam; z++)
                {
                    cout << vet2[z] << ", ";
                }
         }

         cout << endl;
     } else
     {
         cout << "\nErro ao abrir o arquivo!\n";
     }
    leitura.close();
}
