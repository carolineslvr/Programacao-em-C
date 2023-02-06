#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<cmath>
#include<cstring>

using namespace std;

struct dados
{
    float horas;
    float distancia;
};

struct jogadores
{
    int camisa;
    int idade;
    float peso;
    dados x;
};


void incluir (jogadores vetor[], int &ind);
void mostrar (jogadores vetor[], int &ind);
void velocidade (jogadores vetor[], int &ind, float vmedia[]);
void calorias (jogadores vetor[], int ind, float vmedia[]);
void distancias (jogadores vetor[], int ind);

main()
{
	setlocale (LC_ALL , "Portuguese");

	int menu = -1, indice = -1;
	float vmedia[100];

	jogadores vetor[100];

	do
    {
        system("cls");

        cout << "*********** MENU DE OPÇÕES ***********" << endl;
        cout << "* 0 - Sair                           *" << endl;
        cout << "* 1 - Cadastrar atleta               *" << endl;
        cout << "* 2 - Mostrar cadastrados            *" << endl;
        cout << "* 3 - Velocidade média               *" << endl;
        cout << "* 4 - Distâncias - ordem decrescente *" << endl;
        cout << "* 5 - Consumo de calorias            *" << endl;
        cout << "**************************************" << endl;
        cout << "Sua escolha: ";
        cin >> menu;
        fflush(stdin);

        system("cls");

        if (menu == 0)
        {
            cout << "Programa encerrado com sucesso!\n\n";

        } else if (menu == 1)
        {
            incluir(&vetor[0], indice);

            system("cls");
            cout << "Atleta cadastrado com sucesso!";
            getchar();

        } else if (menu == 2)
        {
            if (indice < 0)
            {
                cout << "Nenhum participante cadastrado!";
                getchar();

            } else
            {
                mostrar(&vetor[0], indice);
                getchar();
            }


        } else if (menu == 3)
        {
            if (indice < 0)
            {
                cout << "Nenhum participante cadastrado!";
                getchar();

            } else
            {
                velocidade(&vetor[0], indice, &vmedia[0]);
                getchar();
            }
        } else if (menu == 4)
        {
            if (indice < 0)
            {
                cout << "Nenhum participante cadastrado!";
                getchar();

            } else
            {
                distancias (&vetor[0], indice);
                getchar();
            }
        } else if (menu == 5)
        {
            if (indice < 0)
            {
                cout << "Nenhum participante cadastrado!";
                getchar();

            } else
            {
                calorias(&vetor[0], indice, &vmedia[0]);
                getchar();
            }
        }

    }while (menu != 0);
}
void incluir (jogadores vetor[], int &ind)
{
    ind++;
    int i;

    cout << "Informe o número da camisa do atleta " << ind << ": ";
    cin >> vetor[ind].camisa;
    fflush(stdin);

    cout << "Informe a idade do atleta " << ind << ": ";
    cin >> vetor[ind].idade;
    fflush(stdin);

    cout << "Informe o peso do jogador " << ind << ": ";
    cin >> vetor[ind].peso;
    fflush(stdin);

    cout << "Informe a quantidade de horas em atividade: ";
    cin >> vetor[ind].x.horas;
    fflush(stdin);

    cout << "Informe a distância percorrida: ";
    cin >> vetor[ind].x.distancia;
    fflush(stdin);
}

void mostrar (jogadores vetor[], int &ind)
{
    int i;

    cout << ">>> ATLETAS CADASTRADOS: <<<" << endl << endl;

    for (int i = 0; i <=ind; i++)
    {
        cout << "Número camisa: " << vetor[i].camisa << endl;
        cout << "Idade: " << vetor[i].idade << endl;
        cout << fixed;
        cout.precision(2);
        cout << "Peso: " << vetor[i].peso << endl;
        cout << "Distância percorrida: " << vetor[i].x.distancia << endl;
        cout << "Horas em atividade: " << vetor[i].x.horas << endl;
        cout << "\n--------------------------------\n";
    }
}

void velocidade (jogadores vetor[], int &ind, float vmedia[])
{
    int i;

    for (i = 0; i <= ind; i++)
    {
        cout << "Velocidade média atleta " << i << ": " << vetor[i].x.distancia / vetor[i].x.horas << "km/h" << endl;

        vmedia[i] = vetor[i].x.distancia / vetor[i].x.horas;
    }
}

void calorias (jogadores vetor[], int ind, float vmedia[])
{
    float cmin[100], c_horas[100];
    int i, maior, menor;

    for (i = 0; i <= ind; i++)
    {
        cmin[i] = vetor[i].peso * vmedia[i] * 0.0175;
    }

    for (i = 0; i <= ind; i++)
    {
       c_horas[i] = cmin[i] * 60;
    }

    for (i = 0; i <= ind; i++)
    {
        if (i == 0)
        {
            maior = i;

        } else if (c_horas[i] > c_horas[maior])
        {
            maior = i;
        }
    }
    cout << "Atleta com mais consumiu calorias:" << endl;
    cout << "Camisa: " << vetor[maior].camisa << endl;
    cout << "Consumo: " << c_horas[maior] << endl;

     for (i = 0; i <= ind; i++)
    {
        if (i == 0)
        {
            menor = i;

        } else if (c_horas[i] < c_horas[menor])
        {
            menor = i;
        }
    }
    cout << "\nAtleta com menos consumiu calorias:" << endl;
    cout << "Camisa: " << vetor[menor].camisa << endl;
    cout << "Consumo: " << c_horas[menor];
}

void distancias (jogadores vetor[], int ind)
{
    int i, j, aux;

    float vdistancia[100];

    for (i = 0; i <= ind; i++)
    {
       vdistancia[i] = vetor[i].x.distancia;
    }

    for (i = 0; i < ind; i++)
    {
        for (j = i + 1; j <= ind; j++)
        {
            if (vdistancia[i] < vdistancia[j])
                {
                    aux = vdistancia[i];
                    vdistancia[i] = vdistancia[j];
                    vdistancia[j] = aux;
                }
        }
    }

    cout << "Distâncias percorridas em ordem decrescente:\n";
    for (i = 0; i <= ind; i++)
    {
        cout << vdistancia[i] << " km/h" << endl;
    }
}
