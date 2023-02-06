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

	cout << "Informe o nome do arquivo com extens�o .txt: ";
	getline(cin, nomedoc);

	leitura.open(nomedoc, ios::in);

	if(leitura.is_open())
    {
        cout << "\nConte�do no arquivo:\n\n";

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

        cout << "\n\nN�mero de caracteres no arquivo: " << cont;
        cout << "\n\nN�mero de vogais no arquivo: " << vogais;
        cout << "\n\nN�mero de espa�os no arquivo: " << esp;
        cout << "\n\nN�mero de caracteres especiais no arquivo: " << carac << endl;


    } else
    {
        cout << "Erro ao abrir o arquivo!";
    }

      leitura.close();
}


