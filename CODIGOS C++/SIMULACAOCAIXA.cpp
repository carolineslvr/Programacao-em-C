#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<cmath>
#include<cstring>

using namespace std;

void leitura (int &valor);
void notas (int &valor, int &cont);

main()
{
	setlocale (LC_ALL , "Portuguese");

	int valor, cont = 0;

	leitura(valor);
	notas(valor, cont);
	if (cont > 0)
    {
      leitura(valor);
	  notas(valor, cont);
    }
	getchar();

}

void leitura(int &valor)
{
    do{
    cout << "Informe o valor do saque: ";
    cin >> valor;
    fflush(stdin);

     if ((valor < 0))
        {
            system("cls");
            cout << "Não há notas disponíveis para este valor de saque! Digite novamente.\n\n";
            getchar();
            system("cls");
        }

    } while ((valor < 0));
}
  void notas(int &valor, int &cont)
  {
      int quantia, n2 = 0, n5 = 0, n10 = 0, n20 = 0, n50 = 0, n100 = 0;
      quantia = valor;

        system("cls");
        cout << fixed;
        cout.precision(2);
        cout << "Valor do saque: R$ " << valor << endl << endl;


        if (quantia >= 100)
        {
          n100 = quantia / 100;
          quantia = quantia % 100;
          if(quantia % 100 == 1)
          {
              quantia = quantia + 100;
              n100 =  n100 - 1;
          }
          if (n100 > 0)
          {
               cout << "Notas de R$ 100,00: " << n100 << endl;
          }
        }
        if (quantia >= 50)
        {
            n50 = quantia / 50;
            quantia = quantia % 50;

            if(quantia % 50 == 1)
          {
              quantia = quantia + 50;
              n50 =  n50 - 1;
          }

            if (n50 > 0)
          {
               cout << "Notas de R$ 50,00: " << n50 << endl;
          }
        }
        if (quantia >= 20)
        {
            n20 = quantia / 20;
            quantia = quantia % 20;

            if(quantia % 20 == 1)
          {
              quantia = quantia + 20;
              n20 =  n20 - 1;
          }

            if (n20 > 0)
          {
               cout << "Notas de R$ 20,00: " << n20 << endl;
          }
        }
        if (quantia >= 10)
        {
            n10 = quantia / 10;
            quantia = quantia % 10;

            if(quantia % 10 == 1)
          {
              quantia = quantia + 10;
              n10 =  n10 - 1;
          }

            if (n10 > 0)
          {
               cout << "Notas de R$ 10,00: " << n10 << endl;
          }
        }
        if (quantia >= 5)
        {
            n5 = quantia / 5;
            quantia = quantia % 5;

            if(quantia % 5 == 1)
          {
              quantia = quantia + 5;
              n5 =  n5 - 1;
          }

            if (n5 > 0)
          {
               cout << "Notas de R$ 5,00: " << n5 << endl;
          }
        }
        if (quantia >= 2)
        {
            n2 = quantia / 2;
            quantia = quantia % 2;

            if(quantia % 2 == 1)
            {
              cont ++;
              cout << "Não há notas disponíveis para este valor de saque! Digite novamente.\n\n" << endl;
              getchar();
              system ("cls");


            } else if (n2 > 0)
                {
                    cout << "Notas de R$ 2,00: " << n2 << endl;
                }
        }
        if (quantia == 1)
        {
            cont ++;
            cout << "Não há notas disponíveis para este valor de saque! Digite novamente.\n\n" << endl;
            getchar();
            system ("cls");
        }
  }
