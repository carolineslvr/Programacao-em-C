#include <iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<cmath>
#include<cstring>

using namespace std;

void leitura (int **pn);
void escrita(int **pn);

main()
{
    setlocale(LC_ALL, "Portuguese");

    int *n = new int;
    leitura(&n);
    escrita(&n);

}
void leitura (int **pn)
{
    cout << "Informe um número: ";
    cin >> **pn;
}

void escrita(int **pn)
{
    int *l = new int;
    int *c = new int;

    for(*l = 0; *l < **pn; (*l)++)
    {
        for(*c = 0; *c < **pn; (*c)++)
        {
            if (*l == *c or *l == 0 or *c == 0 or *l == (**pn)-1 or *c == (**pn)-1 or *l + *c == (**pn)-1)
                cout << "* ";

            else
                cout << "  ";
        }
        cout << "\n";
    }

}
