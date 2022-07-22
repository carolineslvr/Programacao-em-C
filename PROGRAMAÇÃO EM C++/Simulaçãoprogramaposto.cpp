#include<iostream>
#include<cstdio>
#include<cstdlib>

using namespace std;

main()
{
	setlocale (LC_ALL , "Portuguese");
	float litros, vp, pg, pa, desc;
	char tipo;

	cout << "Informe o tipo de combustível: ";
	cin >> tipo;

	if ((tipo == 'a') or (tipo == 'A'))
    {
         cout << "Informe a quantidade de litros abastecidos: ";
         cin >> litros;

         if (litros <= 20.00)
         {
             vp = litros * 1.650;
            desc = vp - (vp * 3/100);
            cout << "Valor a ser pago: " << desc;

         } else if (litros > 20.00)
         {
            vp = litros * 1.650;
            desc = vp - (vp * 5/100);
            cout << "Valor a ser pago: " << desc;
         }

         } else if ((tipo == 'g') or (tipo == 'G'))
         {
             cout << "Informe a quantidade de litros abastecidos: ";
            cin >> litros;

             if (litros <= 15.00)
             {
                 vp = litros * 2.590;
                desc = vp - (vp * 3.5/100);
                cout << "Valor a ser pago: " << desc;

             } else if (litros > 15.00)
             {
                 vp = litros * 2.590;
                desc = vp - (vp * 6/100);
                cout << "Valor a ser pago: " << desc;
             }
         } else cout << "Tipo de combustível inválido.";



}
