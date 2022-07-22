#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>

using namespace std;

main()
{
	setlocale (LC_ALL , "Portuguese");

	int lin, col, num;

	do{
	cout << "Informe um número: ";
	cin >> num;

	if (num < 3 or num > 7)
    {
        system("cls");
        cout << "Número informado deve ser maior que 3 e menor que 7. Tente novamente." << endl;
        getchar();
    }

	} while (num < 3 or num > 7);

	char matriz[num][num];

	for (lin = 0; lin < num; lin++)
    {
        for (col = 0; col < num; col++)
        {
            if (lin == col)
            {
                matriz[lin][col] = 'X';

            } else if (lin < col)
            {
                matriz[lin][col] =  'A';

            } else if (lin > col)
            {
                matriz[lin][col] = 'B';
            }
        }
    }
    for (lin = 0; lin < num; lin++)
    {
        for (col = 0; col < num; col++)
        {
            cout << matriz[lin][col] << "\t";
        }
        cout << endl;
    }
}
