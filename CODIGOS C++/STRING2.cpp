#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<cmath>
#include<cstring>

using namespace std;

main()
{
	setlocale (LC_ALL , "Portuguese");

	int i, cont = 0, erro = 0;
	string chave;
	string texto;
	string menu;

       do{
            cout << "Informe a palavra chave: ";
            getline (cin, chave);

            for (i = 0; i <= chave.size(); i++)
            {
                if (chave[i] == '�' or chave[i] == '�')
                {
                    erro++;
                    break;
                }
            }

            if ((chave == "fim") or (chave == "FIM") or (erro > 0 ))
            {
                system("cls");
                cout << "Chave digitada � inv�lida! Tente novamente. ";

            }

        } while ((chave == "fim") or (chave == "FIM")or (erro > 0));

      for (i = 0; i <= chave.size(); i++)
      {
          chave[i] = tolower(chave[i]);
      }

      system ("cls");

      do{
        cout << "Informe palavras quaisquer: ";
        getline (cin, texto);

        for (i = 0; i <=texto.size(); i++)
        {
            texto[i] = tolower(texto[i]);
        }

        if(texto != chave)
        {
            cont++;
            system ("cls");

            cout << "Palavra chave errada! Para tentar novamente, aperte ENTER." << endl << "Para encerrar, digite FIM.";
            getline (cin, menu);
            fflush(stdin);

             if (menu == "fim" or menu == "FIM")
                {
                    system("cls");
                    cout << "Programa encerrado com sucesso!";

                    break;
                }
        }

            if(texto == chave)
            {
                system ("cls");
                cout << "Palavra chave correta!" << endl;
                cout << "Tentativas necess�rias: " << cont + 1;

                break;
            }



	} while (texto != chave or menu != "fim" or menu != "FIM");
}
