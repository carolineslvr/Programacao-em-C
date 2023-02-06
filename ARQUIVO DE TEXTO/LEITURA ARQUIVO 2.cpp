#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<cmath>
#include<cstring>
#include<fstream>

using namespace std;

main()
{
	setlocale (LC_ALL , "Portuguese");

	ifstream leitura;

	string nomedoc;
	char c;
	int cont = 0, vogais = 0, esp = 0, carac = 0;

	cout << "Informe o nome do arquivo com extensão .txt: ";
	getline(cin, nomedoc);

	leitura.open(nomedoc, ios::in);

	if(leitura.is_open())
    {
        cout << "\nConteúdo no arquivo:\n\n";

        while(leitura.get(c))
        {
             cout << c;
             c = tolower(c);

            if(!isspace(c))
            {
                cont++;
            }
            if (c == 'a' or c == 'e' or c == 'i' or c == 'o' or c == 'u')
            {
                vogais++;
            }
            if (isspace(c))
            {
                esp++;
            }
            if (!isalnum(c) && !isspace(c))
            {
                carac++;
            }

        }

        cout << "\n\nNúmero de caracteres no arquivo: " << cont;
        cout << "\n\nNúmero de vogais no arquivo: " << vogais;
        cout << "\n\nNúmero de espaços no arquivo: " << esp;
        cout << "\n\nNúmero de caracteres especiais no arquivo: " << carac << endl;


    } else
    {
        cout << "Erro ao abrir o arquivo!";
    }

      leitura.close();
}


