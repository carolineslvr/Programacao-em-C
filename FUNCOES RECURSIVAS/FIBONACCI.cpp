#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<cmath>
#include<cstring>

using namespace std;

void fibonacci (int &n, int x, int y);
main()
{
    setlocale(LC_ALL, "Portuguese");
    int i = 1, t1 = 0, t2 = 1;
    fibonacci(i, t1, t2);
}

void fibonacci(int &n, int x, int y)
{

    if (n >= 20)
        return;
    else
    {
        if (n == 1)
        {
            std::cout << x << ", " << y << ", ";
            n++;
            fibonacci(n, x, y);
        }
        else
        {
            std::cout << x + y << ", ";
            n++;
            fibonacci(n, y, x + y);
        }
    }
}



