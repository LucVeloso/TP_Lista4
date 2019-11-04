#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

void cadastro(map<string, string> &catalogo){

    string nome, email;

    cout << "Informe o nome: ";
    cin >> nome;

    cout << "Informe o endereço de e-mail: ";
    cin >> email;

    catalogo[nome] = email;
}

void mostrarEnd(map<string, string> catalogo){

    cout.width(15);
    cout << left << "Nome";
    cout << left << "Endereço de e-mail" << endl;

    for(auto show : catalogo){

        cout.width(15);
        cout << left << show.first;
        cout <<left << show.second << endl;
    }
}

void apagarEnd(map<string, string> &catalogo){

    map<string, string>::iterator it;
    string resp;
    int op = 0;

    cout << "Informe o nome a ser removido do catálogo: ";
    cin >> resp;

    do{
        it = catalogo.find(resp);
        if(it != catalogo.end()){ catalogo.erase(it); op++; break;}

        it = find(catalogo.begin(), catalogo.end(), resp);
        if(it != catalogo.end()){ catalogo.erase(it); op++; break;}
        
        else{

            cout << "Nome não encontrado! Infome Novamente: ";
            cin >> resp;
        }
    }while(op == 0);

    cout << "Endereço apagado!" << endl;
}

void operacoes(map<string, string> &catalogo){

    int resp = 0;

    do{
        system("CLS");
        cout << "0 - Sair" << endl;
        cout << "1 - Cadastrar novo endereço" << endl;
        cout << "2 - Consultar endereço" << endl;
        cout << "3 - Apagar endereço" << endl;
        cout << "\ninforme a operação a realizar: ";
        cin >>  resp;

        while(resp < 0 or resp > 3){

            cout << "operação errada! Tente novamente: ";
            cin >> resp;
        }

        switch(resp){

            case 0:
            break;

            case 1:
                cadastro(catalogo);
                system("pause");
            break;

            case 2:
                mostrarEnd(catalogo);
                system("pause");
            break;

            case 3: 
                mostrarEnd(catalogo);
                apagarEnd(catalogo);
                system("pause");
            break;
        }
    }while(resp != 0);
}
