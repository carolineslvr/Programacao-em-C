#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<cmath>
#include<cstring>

using namespace std;

int soma(int n);

main()
{
	setlocale (LC_ALL , "Portuguese");


	int num;

	do
    {
        cout << "Informe um número menor do que 999: ";
        cin >> num;
        fflush (stdin);

        if(num >= 999)
        {
            system("cls");
            cout << "O número deve ser menor que 999! Digite novamente.";
            getchar();
            system("cls");
        }
    } while (num >= 999);

    cout << "Soma dos digitos do número " << num << ": " << soma(num);
}

int soma(int n)
{
    if (n % 10 == n)
    {
        return n;

    } else
    {
        return (soma(n % 10) + soma(n / 10));
    }
}
