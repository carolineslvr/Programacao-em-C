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
        cout << "Informe um n�mero menor do que 999: ";
        cin >> num;
        fflush (stdin);

        if(num >= 999)
        {
            system("cls");
            cout << "O n�mero deve ser menor que 999! Digite novamente.";
            getchar();
            system("cls");
        }
    } while (num >= 999);

    cout << "Soma dos digitos do n�mero " << num << ": " << soma(num);
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
