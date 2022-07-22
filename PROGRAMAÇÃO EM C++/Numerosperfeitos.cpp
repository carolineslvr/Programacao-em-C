#include<iostream>
#include<cstdio>
#include<cstdlib>

using namespace std;

main()
{
	setlocale (LC_ALL , "Portuguese");

	int i, num, soma = 0;

	cout << "Infome um número qualquer: ";
	cin >> num;

	for (i = 1 ; i < num; i++)
    {
        if (num % i == 0)
        {
           soma+=i;
        }
    }
    system("cls");

    if (soma == num)
        cout << num << " é um número perfeito.";
    else
        cout << num << " não é um número perfeito.";
}
