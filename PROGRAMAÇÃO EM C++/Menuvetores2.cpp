#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>

using namespace std;

main()
{
	setlocale (LC_ALL , "Portuguese");
	srand(time(NULL));

	int i, x, menu = 0, multiplos = -1, gerou = 0, vetorV[15], vetorK[15];

	do{

        system("cls");

       cout << ">>>>>>>>>> MENU DE OPÇÕES: <<<<<<<<<   " << endl << endl;
       cout << "           1 - Gerar vetor             " << endl << endl;
       cout << "           2 - Mostrar vetor           " << endl << endl;
       cout << "           3 - Vetor K (múltiplos de 5)" << endl << endl;
       cout << "           4 - Sair                    " << endl << endl;
       cin >> menu;
       fflush(stdin);

       system("cls");

       if (menu == 1)

       {
           for (i = 0; i < 15; i++)
           {
               vetorV[i] = rand() % 51 + 30;

               if(vetorV[i] % 5 == 0)
               {
                   multiplos++;

                   vetorK[multiplos] = vetorV[i];
               }
           }
           cout << "Vetor gerado com sucesso!";

           getchar();

           gerou++;

       } else if (menu == 2)
       {
           if(gerou != 0)
           {
                cout << "Vetor formado pelos elementos:" << endl;

                for (i = 0; i < 15; i++)
                {
                    cout << vetorV[i] << ", ";
                }
                getchar();
           } else
           {
               system("cls");
               cout << "Primeiro é necessário gerar o vetor! Tente novamente.";
               getchar();
           }

       } else if (menu == 3)
       {
           if(gerou != 0)
           {
             cout << "Vetor K formado por valores múltiplos de 5:" << endl;

             for(i = 0; i <= multiplos; i++)
             {
                 cout << vetorK[i] << ", ";
             }
             getchar();
           } else
           {
               system("cls");
               cout << "Primeiro é necessário gerar o vetor! Tente novamente.";
               getchar();
           }
       } else if (menu == 4)
       {
           cout << "Programa encerrado com sucesso!";
           getchar();
       } else
       {
           cout << "Opção inválida! Tente novamente!";
           getchar();
       }


	}while(menu != 4);
}
