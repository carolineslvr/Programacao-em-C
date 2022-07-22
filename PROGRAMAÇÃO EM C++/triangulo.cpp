#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>

using namespace std;

main()
{
	setlocale (LC_ALL , "Portuguese");

	int linha, altura, coluna;

	do{
        cout << "Informe a altura do triângulo:";
        cin >> altura;
        fflush(stdin);

    }while(altura < 3 or altura > 20);

    for (linha = 1; linha <= altura; linha++)
    {
        for (coluna = 1; coluna <= linha; coluna++)
        {

            cout << '*' << ' ';
        }
            cout << endl;

    }
}
