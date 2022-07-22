#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>

using namespace std;

main()
{
	setlocale (LC_ALL , "Portuguese");
	srand(time(NULL));

	int i, x, menu = 0, posicao, gerou = 0, intervalo, num1, num2, maior, pares = 0, soma = 0, vetor[5];

	do{
       system("cls");

       cout << ">>>>>>>>>> MENU DE OPÇÕES: <<<<<<<<<  " << endl << endl;
       cout << "           1 - Gerar vetor            " << endl << endl;
       cout << "           2 - Mostrar vetor          " << endl << endl;
       cout << "           3 - Vetor multiplicado     " << endl << endl;
       cout << "           4 - Soma dos valores pares " << endl << endl;
       cout << "           5 - Maior valor do vetor   " << endl << endl;
       cout << "           6 - Sair                   " << endl << endl;
       cin >> menu;
       fflush(stdin);

       system("cls");

       if (menu == 1)
       {
           do{
           cout << "Informe o valor incial do intervalo: ";
           cin >> num1;

           cout << "Informe o valor final do intervalo: ";
           cin >> num2;

            if (num1 > num2)
            {
               system("cls");
               cout << "O valor inicial do intervalo deve ser menor que o final! Tente novamente." << endl;
            }

           }while (num1 > num2);

           intervalo = num2 - num1;

           for (i = 0; i < 5; i++)
           {
               vetor[i] = rand() % intervalo + num1;

               if (vetor[i] % 2 == 0)
               {
                   soma+= vetor[i];
               }
               if (i == 0)
               {
                   maior = vetor[i];
                   posicao = i;

               } else if (vetor[i] > maior)
               {
                   maior = vetor[i];
                   posicao = i;
               }
           }

           gerou ++;

       } else if (menu == 2)
       {
           if(gerou != 0)
           {
               cout << "Vetor formado pelos valores: " << endl;

           for (i = 0; i < 5; i++)
           {
               cout << vetor[i] << ", ";
           }

           getchar();

           } else
           {
               system("cls");
               cout << "Primeiro é necessário gerar o vetor. Tente novamente.";
               getchar();
           }

       } else if (menu == 3)
       {
           if(gerou != 0)
           {
               cout << "Vetor multiplicado pelo número 3:" << endl;

               for (i = 0; i < 5; i++)
               {
                   cout <<vetor[i] << "* 3 = " << vetor[i] * 3 << endl;
               }
               getchar();
           } else
           {
               system("cls");
               cout << "Primeiro é necessário gerar o vetor. Tente novamente.";
               getchar();
           }
       } else if (menu == 4)
       {
           if (gerou != 0)
           {
               cout << "Soma dos valores pares: " << soma;
               getchar();
           } else
           {
               system("cls");
               cout << "Primeiro é necessário gerar o vetor. Tente novamente.";
               getchar();
           }
       } else if (menu == 5)
       {
           if(gerou != 0)
           {
               cout << "Maior valor do vetor: " << maior << ". Encontrado na posição " << posicao;

               getchar();
           } else
           {
               system("cls");
               cout << "Primeiro é necessário gerar o vetor. Tente novamente.";
               getchar();
           }
       } else if (menu == 6)
       {
           cout << "Programa encerrado com sucesso!" << endl;
       } else
       {
           cout << "Opção inválida tente novamente!";
           getchar();
       }
	} while(menu != 6);
}
