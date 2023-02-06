#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<cmath>
#include<cstring>

using namespace std;

struct ibge
{
    int idade;
    char sexo;
    float salario;
    int filhos;
};

void cadastrar (ibge cadastro[], int &indice);
float mediamasc (ibge cadastro[], int &indice);
float mediafem (ibge cadastro[], int &indice);
void maioriadade (ibge cadastro[], int &indice);
void menoridade (ibge cadastro[], int &indice);
void maisfilhos (ibge cadastro[], int &indice);

main()
{
	setlocale (LC_ALL , "Portuguese");

	ibge cadastro[50];
	int menu = 0, indice = -1;

	do
    {
        system("cls");

        cout << "******* MENU DE OPÇÕES *******" << endl;
        cout << "* 1 - Cadastrar              *" << endl;
        cout << "* 2 - Média salário homens   *" << endl;
        cout << "* 3 - Média salário mulheres *" << endl;
        cout << "* 4 - Pessoa com maior idade *" << endl;
        cout << "* 5 - Pessoa com menor idade *" << endl;
        cout << "* 6 - Pessoa com mais filhos *" << endl;
        cout << "* 7 - Sair                   *" << endl;
        cout << "******************************" << endl;
        cout << "Sua escolha: ";
        cin >> menu;
        fflush(stdin);

        system("cls");

        if (menu == 1)
        {
            cadastrar(&cadastro[0], indice);

        } else if (menu == 2)
        {
            if (indice < 0)
           {
               cout << "Nenhum participante cadastrado!";
               getchar();

           } else if(mediamasc (&cadastro[0], indice) == 0)
           {
                cout << "Nenhuma pessoa do sexo maculino foi cadastrada!";
                getchar();

           } else
           {
               cout << fixed;
               cout.precision(2);
               cout << "Média de salário das pessoas do sexo masculino: R$" << mediamasc (&cadastro[0], indice);
               getchar();
           }
        } else if (menu == 3)
        {
            if (indice < 0)
           {
               cout << "Nenhum participante cadastrado!";
               getchar();

           } else if (mediafem (&cadastro[0], indice) == 0)
           {
                cout << "Nenhuma pessoa do sexo feminino foi cadastrada!";
                getchar();

           } else
           {
               cout << fixed;
               cout.precision(2);
               cout << "Média de salário das pessoas do sexo feminino: R$" << mediafem (&cadastro[0], indice);
               getchar();
           }
        } else if (menu == 4)
        {
            if (indice < 0)
           {
               cout << "Nenhum participante cadastrado!";
               getchar();

           } else
           {
               maioriadade (&cadastro[0], indice);
               getchar();
           }
        } else if (menu == 5)
        {
            if (indice < 0)
           {
               cout << "Nenhum participante cadastrado!";
               getchar();

           } else
           {
               menoridade (&cadastro[0], indice);
               getchar();
           }
        } else if (menu == 6)
        {
            if (indice < 0)
           {
               cout << "Nenhum participante cadastrado!";
               getchar();

           } else
           {
               maisfilhos (&cadastro[0], indice);
               getchar();
           }
        } else if (menu == 7)
        {
            cout << "\nPrograma encerrado com sucesso!\n\n";

        } else
        {
            cout << "Opção inválida, tente novamente!";
            getchar();
        }

    }while (menu != 7);

}

void cadastrar (ibge cadastro[], int &indice)
{
    indice++;

    int i;

        cout << "Informe a idade do participante " << indice << ": ";
        cin >> cadastro[indice].idade;

        do{
            cout << "Informe o sexo do participante " << indice << " (digite F para feminino ou M para masculino): ";
            cin >> cadastro[indice].sexo;
            cadastro[indice].sexo = tolower(cadastro[indice].sexo);

            if (cadastro[indice].sexo != 'm' && cadastro[indice].sexo != 'f')
            {
                system("cls");
                cout << "Caractere digitado é inválido. Por favor, digite f para feminino ou m para masculino!\n\n";
                getchar();
            }

        }while (cadastro[indice].sexo != 'm' && cadastro[indice].sexo != 'f');

        cout << "Informe o salário do participante " << indice << ": ";
        cin >> cadastro[indice].salario;

        cout << "Informe o número de filhos do participante " << indice << ": ";
        cin >> cadastro[indice].filhos;
}

float mediamasc (ibge cadastro[], int &indice)
{
    int i, totalm = 0;
    float sm = 0;

    for (i = 0; i <= indice; i++)
    {
        if (cadastro[i].sexo == 'm')
        {
            totalm++;
            sm += cadastro[i].salario;
        }
    }

    if (totalm <= 0)
    {

        return 0;

    } else
    {
        return sm / totalm;
    }


}

float mediafem (ibge cadastro[], int &indice)
{
    int i, totalf = 0;
    float sf = 0;

    for (i = 0; i <= indice; i++)
    {
        if (cadastro[i].sexo == 'f')
        {
            totalf++;
            sf += cadastro[i].salario;
        }
    }

    if (totalf <= 0)
    {
        return 0;

    } else
    {
         return sf / totalf;
    }

}

void maioriadade (ibge cadastro[], int &indice)
{
    int maior, i;

    for (i = 0; i <= indice; i++)
    {
        if (i == 0)
        {
           maior = i;

        } else if (cadastro[i].idade > cadastro[maior].idade)
        {
            maior = i;
        }
    }

    cout << "Pessoa com maior idade possui " << cadastro[maior].idade << " anos. ";
    if (cadastro[maior].sexo == 'f' or cadastro[maior].sexo == 'F')
    {
        cout << "É do sexo feminino";

    } else
    {
        cout << "É do sexo masculino";
    }
     cout << " e recebe R$" << cadastro[maior].salario;
}

void menoridade (ibge cadastro[], int &indice)
{
    int menor, i;

    for (i = 0; i <= indice; i++)
    {
        if (i == 0)
        {
           menor = i;

        } else if (cadastro[i].idade < cadastro[menor].idade)
        {
            menor = i;
        }
    }
    cout << "Pessoa com menor idade possui " << cadastro[menor].idade << " anos. ";
    if (cadastro[menor].sexo == 'f' or cadastro[menor].sexo == 'F')
    {
        cout << "É do sexo feminino";

    } else
    {
        cout << "É do sexo masculino";
    }
     cout << " e recebe R$" << cadastro[menor].salario;
}

void maisfilhos (ibge cadastro[], int &indice)
{
    int mais, i;

    for (i = 0; i <= indice; i++)
    {
        if (i == 0)
        {
           mais = i;

        } else if (cadastro[i].filhos > cadastro[mais].filhos)
        {
            mais = i;
        }
    }
    cout << "Pessoa com mais filhos possui " << cadastro[mais].filhos << " fihos e recebe R$" << cadastro[mais].salario;
}
