#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<cmath>

using namespace std;

main()
{
	setlocale (LC_ALL , "Portuguese");

	int i, num, quant[15], menu = 0, codigo = 0;
	float total = 0.00;


	for (i = 0; i < 15; i++)
    {
        quant[i] = 0;
    }

    do{
        do {
            system("cls");

            cout << ">>>>> CARDÁPIO <<<<<" << endl;
            cout << "10 > Cachorro-quente  > R$ 15,00" << endl;
            cout << "11 > Bauru simples    > R$ 18,50" << endl;
            cout << "12 > Bauru com ovo    > R$ 22,50" << endl;
            cout << "13 > Hamburguer       > R$ 26,00" << endl;
            cout << "14 > Cheeseburguer    > R$ 22,00" << endl;
            cout << "15 > Torrada          > R$ 10,00" << endl;
            cout << "1  > Refrigerante     > R$ 7,50 " << endl;
            cout << "2  > Suco natural     > R$ 10,00" << endl;
            cout << "3  > Água             > R$ 5,00 " << endl;
            cout << endl << "Digite o código do produto: ";
            cin >> codigo;
            fflush(stdin);

            system("cls");

            if ((codigo < 1) or (codigo > 3 && codigo < 10) or (codigo > 15))
            {
                cout <<  endl << "Código digitado é inválido, digite novamente!";
                getchar();
                system("cls");
            }
        } while((codigo < 1) or (codigo > 3 && codigo < 10) or (codigo > 15));

        cout << "Informe a quantidade: ";
        cin >> num;
        fflush(stdin);
        quant[codigo] = num;

        do{
            cout << "Pedido realizado com sucesso!" << endl << " Para escolher mais um item digite 1." << endl << " Para encerrar o pedido digite 2.";
            cin >> menu;
            fflush(stdin);

            if (menu != 1 && menu != 2)
            {
                cout << "Opção inválida! Por favor digite novamente: ";
                getchar();
            }
            system ("cls");

        } while (menu > 2 or menu < 1);
         if (menu == 2)
         {
            cout.width(25);
            cout << left << "Descrição";

            cout.width(20);
            cout << "Quantidade";

            cout << "Valor R$";

            for (i = 1; i <= 3; i++)
            {
                if (i == 1)
                {
                    if (quant[i] > 0)
                    {
                        cout.width(27);
                        cout << left << endl << "Refrigerante";
                        cout << quant[i];

                        cout << fixed;
                        cout.precision(2);
                        cout.width(20);
                        cout << right << "R$" << (float)quant[i] * 7.50;
                        total += (float)quant[i] * 7.50;
                    }
                }
            else if (i == 2)
            {
                if (quant[i] > 0)
                {
                    cout.width(27);
                    cout << left << endl << "Suco Natural";
                    cout << quant[i];

                    cout << fixed;
                    cout.precision(2);
                    cout.width(20);
                    cout << right << "R$" << (float)quant[i] * 10.00;
                    total += (float)quant[i] * 10.00;
                }

            }
            else if (i == 3)
            {
                if (quant[i] > 0)
                {
                    cout.width(27);
                    cout << left << endl << "Água";
                    cout << quant[i];

                    cout << fixed;
                    cout.precision(2);
                    cout.width(20);
                    cout << right << "R$" << (float)quant[i] * 5.00;
                    total += (float)quant[i] * 5.00;
                }
            }
        }
        for (i = 10; i <= 15; i++)
        {
            if (i == 10)
            {
                if (quant[i] > 0)
                {
                    cout.width(27);
                    cout << left << endl << "Cachorro-quente";
                    cout << quant[i];

                    cout << fixed;
                    cout.precision(2);
                    cout.width(20);
                    cout << right << "R$" << (float)quant[i] * 15.00;
                    total += (float)quant[i] * 15.00;
                }
            }
            else if (i == 11)
            {
                if (quant[i] > 0)
                {
                    cout.width(27);
                    cout << left << endl << "Bauru Simples";
                    cout << quant[i];

                    cout << fixed;
                    cout.precision(2);
                    cout.width(20);
                    cout << right << "R$" << (float)quant[i] * 18.50;
                    total += (float)quant[i] * 18.50;
                }
            }
            else if (i == 12)
            {
                if (quant[i] > 0)
                {
                    cout.width(27);
                    cout << left << endl << "Bauru com Ovo";
                    cout << quant[i];

                    cout << fixed;
                    cout.precision(2);
                    cout.width(20);
                    cout << right << "R$" << (float)quant[i] * 22.00;
                    total += (float)quant[i] * 22.00;
                }
            }
            else if (i == 13)
            {
                if (quant[i] > 0)
                {
                    cout.width(27);
                    cout << left << endl << "Hambúrguer";
                    cout << quant[i];

                    cout << fixed;
                    cout.precision(2);
                    cout.width(20);
                    cout << right << "R$" << (float)quant[i] * 26.00;
                    total += (float)quant[i] * 26.00;
                }
            }
            else if (i == 14)
            {
                if (quant[i] > 0)
                {
                    cout.width(27);
                    cout << left << endl << "Cheeseburguer";
                    cout << quant[i];

                    cout << fixed;
                    cout.precision(2);
                    cout.width(20);
                    cout << right << "R$" << (float)quant[i] * 22.00;
                    total += (float)quant[i] * 22.00;
                }
            }
            else if (i == 15)
            {
                if (quant[i] > 0)
                {
                    cout.width(27);
                    cout << left << endl << "Torrada";
                    cout << quant[i];

                    cout << fixed;
                    cout.precision(2);
                    cout.width(20);
                    cout << right << "R$" << (float)quant[i] * 10.00;
                    total += (float)quant[i] * 10.00;
                }
            }
        }
        cout << endl << endl;
        cout.width(50);
        cout.fill('.');
        cout << left << "Total do Pedido:" << "R$" << total;
    }

    } while (menu != 2);

}

