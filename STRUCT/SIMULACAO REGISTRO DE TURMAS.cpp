#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<cmath>
#include<cstring>

using namespace std;

struct alunos
{
    int matricula;
    string nome;
    int turma;
    string curso;
    float media;
    int frequencia;
};

void cadastrar (alunos vet[], int &ind);
void mostre (alunos vet[], int &ind);
void aprovados (alunos vet[], int &ind);
void medias (alunos vet[], int &ind);

main()
{
	setlocale (LC_ALL , "Portuguese");

	int menu = -1, indice = -1;

	alunos vet[50];

	do
    {
        system("cls");

        cout << "********** MENU DE OPÇÕES *********" << endl;
        cout << "* 0 - Sair                        *" << endl;
        cout << "* 1 - Cadastrar aluno             *" << endl;
        cout << "* 2 - Lista alunos por turma      *" << endl;
        cout << "* 3 - Aprovados por curso         *" << endl;
        cout << "* 4 - Média por turma             *" << endl;
        cout << "***********************************" << endl;
        cout << "Sua escolha: ";
        cin >> menu;
        fflush(stdin);

        system("cls");

        if (menu == 0)
        {
            cout << "Programa encerrado com sucesso!\n\n";

        } else if (menu == 1)
        {
            cadastrar(&vet[0], indice);

        } else if (menu == 2)
        {
            if (indice < 0)
            {
                cout << "Nenhum aluno cadastrado!";
                getchar();

            } else
            {
                mostre(&vet[0], indice);
                getchar();
            }
        } else if (menu == 3)
        {
            if (indice < 0)
            {
                cout << "Nenhum aluno cadastrado!";
                getchar();

            } else
            {
                aprovados(&vet[0], indice);
                getchar();
            }
        } else if (menu == 4)
        {
            if (indice < 0)
            {
                cout << "Nenhum aluno cadastrado!";
                getchar();

            } else
            {
                medias(&vet[0], indice);
                getchar();
            }
        }
    }while (menu != 0);
}

void cadastrar (alunos vet[], int &ind)
{
    ind++;

    int aux, igual, i, x;

        cout << "\nInforme o número da matrícula do aluno [" << ind << "]: ";
        cin >> aux;
        fflush(stdin);

       for (i = 0; i <= ind; i++)
       {
            if(ind == 0)
            {
               vet[ind].matricula = aux;

            } else
            {
                igual = 0;
                for (x = 0; x < ind; x++)
            {
                if (vet[x].matricula == aux)
                {
                    igual++;
                    break;
                }
            }
            if (igual == 0)
            {
                vet[ind].matricula = aux;

            } else
            {
                cout << "Atenção! Matrícula já cadastrada. Tente novamente.";
                getchar();
                ind--;

                return;
            }
        }
    }

    cout << "Informe o nome do aluno [" << ind << "]: ";
    getline(cin, vet[ind].nome);
    fflush(stdin);

    cout << "Informe a turma do aluno [" << ind << "]: ";
    cin >> vet[ind].turma;
    fflush(stdin);

    cout << "Informe o curso do aluno [" << ind << "]: ";
    getline(cin, vet[ind].curso);
    fflush(stdin);

    cout << "Informe a média do aluno [" << ind << "]: ";
    cin >> vet[ind].media;
    fflush(stdin);

    cout << "Informe a frequência do aluno [" << ind << "]: ";
    cin >> vet[ind].frequencia;
    fflush(stdin);

    system("cls");
    cout << "Aluno cadastrado com sucesso!";
    getchar();
}

void mostre (alunos vet[], int &ind)
{
    int i, num, cont = 0;

    cout << "Informe a turma desejada: ";
    cin >> num;
    fflush(stdin);

    for (i = 0; i <= ind; i++)
    {
        if (num == vet[i].turma)
        {

            cout << "Número da matricula: " << vet[i].matricula << endl;
            cout << "Nome do aluno: " << vet[i].nome << endl;
            cout << "Curso: " << vet[i].curso << endl;
            cout << fixed;
            cout.precision(2);
            cout << "Média: " << vet[i].media << endl;
            cout << "Frequência: " << vet[i].frequencia << endl;
            cout << "\n--------------------------------\n" << endl;

            cont --;

        } else
        {
            cont++;
        }
    }
    if (cont > 0)
    {
        cout << "Turma não encontrada! Tente novamente!";
        getchar();

        return;
    }
}

void aprovados (alunos vet[], int &ind)
{
    int i, cont = 0, aprov = 0;
    string c;

    cout << "Informe o curso desejado: ";
    getline(cin, c);
    fflush(stdin);

    for (i = 0; i <= ind; i++)
    {
        if (c == vet[i].curso)
        {
            cont--;
            if (vet[i].media >= 6 && vet[i].frequencia >= 75)
            {
                cout << "Número da matricula: " << vet[i].matricula << endl;
                cout << "Nome do aluno: " << vet[i].nome << endl;
                cout << "Curso: " << vet[i].curso << endl;
                cout << fixed;
                cout.precision(2);
                cout << "Média: " << vet[i].media << endl;
                cout << "Frequência: " << vet[i].frequencia << endl;
                cout << "\n--------------------------------\n" << endl;

                aprov++;

            } else
            {
               aprov --;
            }
        } else
        {
            cont++;
        }
    }

    if (aprov <= 0)
    {
        cout << "Não há alunos aprovados neste curso;";
        getchar();

        return;
    }
    if (cont >= 0)
    {
        cout << "Curso não encontrado! Tente novamente!";
        getchar();

        return;
    }
}

void medias(alunos vet[], int &ind)
{
    int i, x, num, menor, maior, cont = 0;

    cout << "Informe a turma desejada: ";
    cin >> num;
    fflush(stdin);

    cout << "Médias da turma:\n\n";

    for (i = 0; i <= ind; i++)
    {
        if (num == vet[i].turma)
        {
            cont --;

            cout << vet[i].media << endl;
            cout << "\n--------------------------------\n" << endl;

            for (x = 0; x <= ind; x++)
            {
                if (x == 0)
                {
                    maior = x;

                } else if (vet[x].media > vet[maior].media)
                {
                    maior = x;
                }
            }
             for (x = 0; x <= ind; x++)
            {
                if (x == 0)
                {
                    menor = x;

                } else if (vet[x].media < vet[menor].media)
                {
                    menor = x;
                }
            }
        } else
        {
            cont++;
        }

    }
        cout << "\nMaior média:\n";
        cout << "Matrícula: " << vet[maior].matricula << endl;
        cout << fixed;
        cout.precision(2);
        cout << "Média: " << vet[maior].media << endl;

        cout << "\nMenor média:\n";
        cout << "Matrícula: " << vet[menor].matricula << endl;
        cout << fixed;
        cout.precision(2);
        cout << "Média: " << vet[menor].media << endl;

    if (cont > 0)
    {
        cout << "Turma não encontrada, tente novamente!";
        getchar();
        return;
    }
}

