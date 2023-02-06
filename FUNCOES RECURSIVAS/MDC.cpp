#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<cmath>
#include<cstring>

using namespace std;

int mdc (int num, int num2);

main()
{
	setlocale (LC_ALL , "Portuguese");

	int n1, n2;

	cout << "Informe o primeiro n�mero: ";
	cin >> n1;
	fflush(stdin);

	cout << "Informe o segundo n�mero: ";
	cin >> n2;
	fflush(stdin);

	cout << "\nO MDC dos n�meros " << n1 << " e " << n2 << " �: " << mdc(n1, n2);
}

int mdc (int num, int num2)
{

    if (num % num2 == 0)
    {
        return num2;

    } else
    {
        return mdc(num2, (num%num2));
    }
}

