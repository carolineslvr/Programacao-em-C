#include<iostream>
#include<cstdlib>
#include<cstdio>

using namespace std;
struct notas
{
    float n1;
    float n2;
    float n3;
};
struct cadastro
{
    notas valores;
    int matricula;
};

void leitura(int **n);
void cadastrar(cadastro *alunos, int **i);
void mostrar(cadastro *alunos, int **i);
void maiormenor(cadastro *alunos, int **i);
void aprovacao(cadastro *alunos, int **i);
void consulta(cadastro *alunos, int **i);

main()
{
    setlocale(LC_ALL, "Portuguese");
    int *linhas = new int, *menu = new int, *qtd = new int(-1);
    leitura(&linhas);
    cadastro *alunos = new cadastro[*linhas];
    do
    {
        system("cls");
        cout << "*******MENU DE OPÇÕES*******" << endl;
        cout << "*0- Sair                   *" << endl;
        cout << "*1- Cadastrar aluno        *" << endl;
        cout << "*2- Alunos cadastrados     *" << endl;
        cout << "*3- Maior e menor média    *" << endl;
        cout << "*4- Alunos c média 6(+,-,=)*" << endl;
        cout << "*5- Aluno pela matrícula   *" << endl;
        cout << "****************************" << endl;
        cout << "SUA ESCOLHA: ";
        cin >> *menu;
        fflush(stdin);

        system("cls");
       if (menu == 0)
       {

            cout << "\nPROGRAMA ENCERRADO COM SUCESSO!\n";

       } else if (*menu == 1)
       {
            cadastrar(alunos, &qtd);

       } else if (*menu == 2)
       {
            mostrar(alunos, &qtd);
            getchar();

       } else if (*menu == 3)
       {
            maiormenor(alunos, &qtd);
            getchar();

       } else if (*menu == 4)
       {
              aprovacao(alunos, &qtd);
              getchar();

       } else if (*menu == 5)
       {
           consulta(alunos, &qtd);
           getchar();

       } else
       {
           cout << "\nOpção inválida. Tente novamente!";
       }
    }
    while(*menu != 0);
}

void leitura(int **n)
{
    cout << "Informe a quantidade de alunos que serão registrados: ";
    cin >> (**n);
    fflush(stdin);
}

void cadastrar(cadastro *alunos, int **i)
{
    (**i)++;
    cout << "\nInforme o número da matrícula: ";
    cin >> alunos[**i].matricula;
    fflush(stdin);

    do
    {
        cout << "Informe a primeira nota: ";
        cin >> alunos[**i].valores.n1;
        fflush(stdin);
        if(alunos[**i].valores.n1 > 10 or alunos[**i].valores.n1 < 0)
        {
             cout << "Valor inválido! Tente novamente.\n\n";
        }

    }
    while(alunos[**i].valores.n1 > 10 or alunos[**i].valores.n1 < 0);
    do
    {
        cout << "Informe a segunda nota: ";
        cin >> alunos[**i].valores.n2;
        fflush(stdin);
        if(alunos[**i].valores.n2 > 10 or alunos[**i].valores.n2 < 0)
           {
                cout << "Valor inválido! Tente novamente.\n\n";
           }

    } while(alunos[**i].valores.n2 > 10 or alunos[**i].valores.n2 < 0);
    do
    {
        cout << "NOTA 3: ";
        cin >> alunos[**i].valores.n3;
        fflush(stdin);
        if(alunos[**i].valores.n3 > 10 or alunos[**i].valores.n3 < 0)
            {
                 cout << "Valor inválido! Tente novamente.\n\n";
            }
    } while(alunos[**i].valores.n3 > 10 or alunos[**i].valores.n3 < 0);

    cout << "\nAluno cadastrado com sucesso!";


}
void mostrar(cadastro *alunos, int **i)
{
    int *x = new int;
    for (*x = 0; *x <= **i; (*x)++)
    {
        cout << "\nMatrícula: " << alunos[*x].matricula << endl;
        cout << "Média do aluno: " << (((alunos[*x].valores.n1) * 3.0) +  ((alunos[*x].valores.n2) * 4.0) + ((alunos[*x].valores.n3) * 3.0)) / 10.0 << endl;
        cout << "-------------------------------------------------------------";
    }
}

void maiormenor(cadastro *alunos, int **i)
{
    int *x = new int, *menormatricula = new int, *maiormatricula = new int;
    float *menornota = new float, *maiornota = new float;
    for (*x = 0; *x <= **i; (*x)++)
    {
        if (*x == 0)
        {
            *menornota = (((alunos[*x].valores.n1) * 3.0) +  (((alunos[*x].valores.n2) * 4.0) + ((alunos[*x].valores.n3) * 3.0)) / 10.0);
            *menormatricula = (alunos)[*x].matricula;
            *maiornota = ((((alunos[*x].valores.n1) * 3.0) +  ((alunos[*x].valores.n2) * 4.0) + ((alunos[*x].valores.n3) * 3.0)) / 10.0);
            *maiormatricula = (alunos)[*x].matricula;
        }
        else if (*menornota > (((alunos[*x].valores.n1) * 3.0) +  ((alunos[*x].valores.n2) * 4.0) + ((alunos[*x].valores.n3) * 3.0)) / 10.0)
        {
            *menornota = ((((alunos[*x].valores.n1) * 3.0) +  ((alunos[*x].valores.n2) * 4.0) + ((alunos[*x].valores.n3) * 3.0)) / 10.0);
            *menormatricula = (alunos)[*x].matricula;
        }
        else if (*maiornota < ((((alunos[*x].valores.n1) * 3.0) +  ((alunos[*x].valores.n2) * 4.0) + ((alunos[*x].valores.n3) * 3.0)) / 10.0))
        {
            *maiornota = ((((alunos[*x].valores.n1) * 3.0) +  ((alunos[*x].valores.n2) * 4.0) + ((alunos[*x].valores.n3) * 3.0)) / 10.0);
            *maiormatricula = (alunos)[*x].matricula;
        }
    }
    cout << endl << "MAIOR MÉDIA: " << *maiornota << " // MATRÍCULA: " << *maiormatricula << endl;
    cout << "MENOR MÉDIA: " << *menornota << " // MATRÍCULA: " << *menormatricula << endl;
    getchar();
}

void aprovacao(cadastro *alunos, int **i)
{
    int *x = new int, *aprovados = new int(0), *reprovados = new int(0);
    for (*x = 0; *x <= **i; (*x)++)
    {
        if ((((alunos[*x].valores.n1) * 3.0) +  ((alunos[*x].valores.n2) * 4.0) + ((alunos[*x].valores.n3) * 3.0)) / 10.0 >= 6.0)
            (*aprovados)++;
        else
            (*reprovados)++;
    }
    cout << endl << "TOTAL DE APROVADOS: " << *aprovados << endl;
    cout << endl << "TOTAL DE REPROVADOS: " << *reprovados;
    getchar();
}

void consulta(cadastro *alunos, int **i)
{
    int *x = new int, *matricula = new int, *matriculados = new int(0);
    cout << endl << "MATRÍCULA: ";
    cin >> *matricula;
    fflush(stdin);
    for (*x = 0; *x <= **i; (*x)++)
    {
        if (*matricula == alunos[*x].matricula)
        {
            (*matriculados)++;
            break;
        }

    }
    if (*matriculados == 0)
        cout << "\nMatrícula não informada!\n";
    else
        cout << endl << "Média alunos informados: " << (((alunos[*x].valores.n1) * 3.0) +  ((alunos[*x].valores.n2) * 4.0) + ((alunos[*x].valores.n3) * 3.0)) / 10.0;
    getchar();
}

