#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<cmath>
#include<cstring>

using namespace std;

void leitura (int *n);
int testar (int *n);

main()
{
	setlocale (LC_ALL , "Portuguese");

	int num;

	leitura(&num);
	testar (&num);

	if (testar(&num) == 0)
    {
        cout << "\nN�mero � um quadrado perfeito!\n";

    } else
    {
        cout << "\nN�mero n�o � um quadrado perfeito!\n";
    }

}

void leitura (int *n)
{
    cout << "Informe um valor qualquer: ";
    cin >> *n;
}

int testar (int *n)
{
   int i, j, *pi = &i, *pj = &j;;

   *pi = sqrt(*n);
   *pj = pow(*pi,2);

   if (*pj == *n)
   {
       return 0;

   } else
   {
       return 1;
   }
}


