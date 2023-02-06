#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<cmath>
#include<cstring>
#include<fstream>

using namespace std;

void leitura(char cid[], int &cont, string &busca);
void adicionar(char cid[], string busca);

main()
{
	setlocale (LC_ALL , "Portuguese");

	char city[100];
	int c = 0;
	string b;

	leitura(&city[0], c, b);

	if (c == 0)
    {
        adicionar(&city[0], b);
    }
}

void leitura(char cid[], int &cont, string &busca)
{
    ifstream ler("cidade.txt", ios::in);

     int i, linha = 0, j;

    cout << "Informe uma cidade para busca: ";
    getline(cin, busca);

    for (j = 0; j <= busca.size(); j++)
    {
        busca[j] = tolower(busca[j]);
    }

    if (ler.is_open())
    {
        while (!ler.eof())
        {
            ler.getline(cid, 100);

            for (i = 0; i < 100; i++)
            {
                cid[i] = tolower(cid[i]);
            }

            linha++;

            if (cid == busca)
            {
                cout << "\nCidade " << busca << " encontrada na linha " << linha << endl;
                cont++;
                return;

            } else
            {
                cont = 0;
            }
        }
    } else
    {
        cout << "\nErro ao abrir o arquivo!\n";
    }

    ler.close();
}

void adicionar(char cid[], string busca)
{
    ofstream escrita("cidade.txt", ios::app);

    if (escrita.is_open())
        {
            escrita << busca << endl;

            cout << "\nCidade gravada com sucesso no arquivo!\n";

        } else
        {
            cout << "\nErro ao abrir o arquivo!\n";
        }

}

