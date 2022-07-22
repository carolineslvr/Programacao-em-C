#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>

using namespace std;

char classificarVeiculo(int anoFabricacao);

float calcValorVenda(float preco, char classificacao);

int main()
{
setlocale(LC_ALL,"Portuguese");

int anoFab;
float preco, valorVenda;
char classificacaoVel;

cout << "Informe o ano de fabricação do veículo: ";
cin >> anoFab;

cout << "Informe o preço do veículo: ";
cin >> preco;

classificacaoVel = classificarVeiculo(anoFab);
valorVenda = calcValorVenda(preco, classificacaoVel);

cout << "O veículo foi classificado como [" << classificacaoVel << "] e seu valor de revenda é: " << valorVenda << endl;
}

char classificarVeiculo(int anoFabricacao)
{
int anoAtual = 2022;
char classificacao = ' ';

if(anoFabricacao == anoAtual)
classificacao = 'N';

else if(anoFabricacao >= anoAtual-3)
classificacao = 'S';

else if(anoFabricacao < anoAtual-3)
classificacao = 'U';

return classificacao;
}
float calcValorVenda(float preco, char classificacao)
{
float precoVenda = 0;

if(classificacao == 'N')
precoVenda = preco + ((5/100.0) * preco );

else if(classificacao == 'S')
precoVenda = preco + ((15/100.0) * preco );

else if(classificacao == 'U')
precoVenda = preco + ((25/100.0) * preco );

return precoVenda;
}
