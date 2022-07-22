#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>

using namespace std;

main()
{
	setlocale (LC_ALL , "Portuguese");

	int i, x, num, quant, ocupado, menu=0, hospedes, vetor[12];
	char flag;

	for(i=0; i <12; i++)
        {
            vetor[i] = 0;
        }

	do
    {
        system ("cls");
        cout << "          MENU DE OPÇÕES:  "  << endl << endl;
        cout << " 1 - EFETUAR RESERVA       " << endl;
        cout << " 2 - LISTAR TODOS OS QUARTOS        " << endl;
        cout << " 3 - LISTAR QUARTOS VAGOS  " << endl;
        cout << " 4 - TOTAL DE HOSPEDES NO HOTEL " <<endl;
        cout << " 5 - EFETUAR SAÍDA         " << endl;
        cout << " 6 - QUARTOS OCUPADOS      " << endl;
        cin >> menu;
        fflush(stdin);

        system("cls");




        if (menu == 1 )
        {
            do
            {
                cout << "Informe o número do quarto: ";
                cin >> num;

                if (num < 1 or num > 12)
                {
                    system ("cls");
                    cout << "Quarto inexistente! Digite novamente: " << endl;
                }

            } while(num < 1 or num > 12);

            do
            {
                ocupado=0;
                if (vetor[num - 1] != 0)
                {
                    cout << "O quarto escolhido já estpa ocupado! Por favor, escolha outro quarto.";
                    ocupado = 1;
                    cout << endl << "Informe o número do quarto: ";
                    cin >> num;
                }

            } while (ocupado != 0);

           cout << "Informe a quantidade de hospedes: ";
           cin >> quant;

           //cout << num << ", " << quant << endl;

           //getchar();

           vetor[num - 1] = quant;
           }


       else if (menu == 2)
        {
            cout << "Situação dos quartos:" << endl;
            for (i = 0; i < 12; i++)
            {
                cout << "Quarto " << i + 1 << ": " << vetor[i] << endl;
            }
            getchar();
        }
        else if (menu == 3)
        {
            cout << "Quartos vagos: " << endl;
            for (i = 0; i < 12; i++)
            {
                if (vetor[i] == 0)
                {
                    cout << "O quarto " << i + 1 << " está vago." << endl;
                }
            }
        } else if (menu == 4)
        {
            hospedes=0;
            for (i = 0; i < 12; i++)
            {
                hospedes= vetor[i] + hospedes;
            }
            cout << "Há um total de " << hospedes << " pessoas hospedadas neste momento no hotel.";

        } else if (menu == 5)
        {
            cout << "Por favor, informe o número do quarto onde esteve hospedado:";
            cin >> num;

            vetor[num - 1] = 0;
        } else if (menu == 6)
        {
            cout << "Quartos ocupados: " << endl;
            for (i = 0; i < 12; i++)
            {
                if (vetor[i] > 0)
                {
                    cout << "O quarto " << i + 1 << " está ocupado no momento." << endl;
                }
            }
        } else
        {
            cout << "Opção inválida!";
        }
    cout << "Deseja encerrar o programa? ";
    cin >> flag;
	}while (flag == 'n');
}
