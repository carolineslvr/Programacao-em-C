#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<cmath>
#include<cstring>

using namespace std;

struct data
{
    int n_mes;
    string nomemes;
    string abrmes;
    int diasmes;
};

void leitura(data &mes, int &numero);
int testedata(data &mes, int &numero);
void validacao(data &mes, int &numero);

main()
{
	setlocale (LC_ALL , "Portuguese");

	data mes;

	int numero;

	leitura(mes, numero);
	validacao(mes, numero);


}

void leitura(data &mes, int &numero)
{

    do
    {
         cout << "Informe o número de um mês qualquer: ";
         cin >> mes.n_mes;
         fflush(stdin);

         if (mes.n_mes < 1 or mes.n_mes > 12)
         {
             system("cls");
             cout << "Mês informado é inexistente. Por favor, tente novamente.";
             getchar();
             system("cls");
         }
    }while (mes.n_mes < 1 or mes.n_mes > 12);


    do
    {
        cout << "Informe o número do mês escolhido: ";
        cin >> numero;
        fflush(stdin);

        testedata(mes, numero);

        if (testedata(mes,numero) == 1)
        {
            system("cls");
            cout << "Quantidade de dias é inválida! Tente novamente.";
            getchar();
            system("cls");
        }

    }while (testedata(mes,numero) == 1);
}

int testedata(data &mes, int &numero)
{
     if (mes.n_mes == 2)
         {
             if (numero < 1 or numero > 28)
             {
                 return 1;
             }
         }
         else if (mes.n_mes == 4 or mes.n_mes == 6 or mes.n_mes == 9 or mes.n_mes == 11)
         {
             if (numero < 1 or numero > 30 )
             {
                return 1;
             }
         } else if (numero < 1 or numero > 31 )
         {
                return 1;
         } else
         {
             return 0;
         }
}

void validacao (data &mes, int &numero)
{
    system("cls");

    if (mes.n_mes == 1)
    {
        data mes = {01, "Janeiro", "JAN", 31};

        cout << endl << "Mês número: " << mes.n_mes << endl;
        cout << "Nome: " << mes.nomemes << endl;
        cout << "Abreviação: " << mes.abrmes << endl;
        cout << "Quantidade de dias: " << mes.diasmes << endl;

        cout << "\nNo dia " << numero << " do mês de " << mes.nomemes << " já transcorreram " << numero << " dias do ano.\n";

    } else if (mes.n_mes == 2)
    {
         data mes = {02, "Fevereiro", "FEV", 28};

        cout << endl << "Mês número: " << mes.n_mes << endl;
        cout << "Nome: " << mes.nomemes << endl;
        cout << "Abreviação: " << mes.abrmes << endl;
        cout << "Quantidade de dias: " << mes.diasmes << endl;

        cout << "\nNo dia " << numero << " do mês de " << mes.nomemes << " já transcorreram " << 31 + numero << " dias do ano.\n";

    } else if (mes.n_mes == 3)
    {
         data mes = {03, "Março", "MAR", 31};

        cout << endl << "Mês número: " << mes.n_mes << endl;
        cout << "Nome: " << mes.nomemes << endl;
        cout << "Abreviação: " << mes.abrmes << endl;
        cout << "Quantidade de dias: " << mes.diasmes << endl;

        cout << "\nNo dia " << numero << " do mês de " << mes.nomemes << " já transcorreram " << 28 + 31 + numero << " dias do ano.\n";

    } else if (mes.n_mes == 4)
    {
         data mes = {04, "Abril", "ABR", 30};

        cout << endl << "Mês número: " << mes.n_mes << endl;
        cout << "Nome: " << mes.nomemes << endl;
        cout << "Abreviação: " << mes.abrmes << endl;
        cout << "Quantidade de dias: " << mes.diasmes << endl;

        cout << "\nNo dia " << numero << " do mês de " << mes.nomemes << " já transcorreram " << 28 + (31 * 2) + numero << " dias do ano.\n";

    } else if (mes.n_mes == 5)
    {
         data mes = {05, "Maio", "MAI", 31};

        cout << endl << "Mês número: " << mes.n_mes << endl;
        cout << "Nome: " << mes.nomemes << endl;
        cout << "Abreviação: " << mes.abrmes << endl;
        cout << "Quantidade de dias: " << mes.diasmes << endl;

        cout << "\nNo dia " << numero << " do mês de " << mes.nomemes << " já transcorreram " << 28 + 30 + (31 * 2) + numero << " dias do ano.\n";

    } else if (mes.n_mes == 6)
    {
         data mes = {06, "Junho", "JUN", 30};

        cout << endl << "Mês número: " << mes.n_mes << endl;
        cout << "Nome: " << mes.nomemes << endl;
        cout << "Abreviação: " << mes.abrmes << endl;
        cout << "Quantidade de dias: " << mes.diasmes << endl;

        cout << "\nNo dia " << numero << " do mês de " << mes.nomemes << " já transcorreram " << 28 + 30 + (31 * 3) + numero << " dias do ano.\n";

    } else if (mes.n_mes == 7)
    {
         data mes = {03, "Julho", "JUL", 31};

        cout << endl << "Mês número: " << mes.n_mes << endl;
        cout << "Nome: " << mes.nomemes << endl;
        cout << "Abreviação: " << mes.abrmes << endl;
        cout << "Quantidade de dias: " << mes.diasmes << endl;

         cout << "\nNo dia " << numero << " do mês de " << mes.nomemes << " já transcorreram " << 28 + (30 * 2) + (31 * 3) + numero << " dias do ano.\n";

    } else if (mes.n_mes == 8)
    {
         data mes = {8, "Agosto", "AGO", 31};

        cout << endl << "Mês número: " << mes.n_mes << endl;
        cout << "Nome: " << mes.nomemes << endl;
        cout << "Abreviação: " << mes.abrmes << endl;
        cout << "Quantidade de dias: " << mes.diasmes << endl;

        cout << "\nNo dia " << numero << " do mês de " << mes.nomemes << " já transcorreram " << 28 + (30 * 2) + (31 * 4) + numero << " dias do ano.\n";

    } else if (mes.n_mes == 9)
    {
         data mes = {9, "Setembro", "SET", 30};

        cout << endl << "Mês número: " << mes.n_mes << endl;
        cout << "Nome: " << mes.nomemes << endl;
        cout << "Abreviação: " << mes.abrmes << endl;
        cout << "Quantidade de dias: " << mes.diasmes << endl;

        cout << "\nNo dia " << numero << " do mês de " << mes.nomemes << " já transcorreram " << 28 + (30 * 2) + (31 * 5) + numero << " dias do ano.\n";

    } else if (mes.n_mes == 10)
    {
         data mes = {10, "Outubro", "OUT", 31};

        cout << endl << "Mês número: " << mes.n_mes << endl;
        cout << "Nome: " << mes.nomemes << endl;
        cout << "Abreviação: " << mes.abrmes << endl;
        cout << "Quantidade de dias: " << mes.diasmes << endl;

        cout << "\nNo dia " << numero << " do mês de " << mes.nomemes << " já transcorreram " << 28 + (30 * 3) + (31 * 5) + numero << " dias do ano.\n";

    } else if (mes.n_mes == 11)
    {
         data mes = {11, "Novembro", "NOV", 30};

        cout << endl << "Mês número: " << mes.n_mes << endl;
        cout << "Nome: " << mes.nomemes << endl;
        cout << "Abreviação: " << mes.abrmes << endl;
        cout << "Quantidade de dias: " << mes.diasmes << endl;

        cout << "\nNo dia " << numero << " do mês de " << mes.nomemes << " já transcorreram " << 28 + (30 * 3) + (31 * 6) + numero << " dias do ano.\n";

    } else if (mes.n_mes == 12)
    {
         data mes = {12, "Dezembro", "DEZ", 31};

        cout << endl << "Mês número: " << mes.n_mes << endl;
        cout << "Nome: " << mes.nomemes << endl;
        cout << "Abreviação: " << mes.abrmes << endl;
        cout << "Quantidade de dias: " << mes.diasmes << endl;

        cout << "\nNo dia " << numero << " do mês de " << mes.nomemes << " já transcorreram " << 28 + (30 * 4) + (31 * 6) + numero << " dias do ano.\n";
    }

}
