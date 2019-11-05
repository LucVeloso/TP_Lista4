#include <iostream>
#include <map>
#include <algorithm>
#define MAXW 15
#define START 0
#define SAIR 0
#define CADASTRO 1
#define MOSTRAR 2
#define ALTERAR 3
#define APAGAR 4

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

    cout.width(MAXW);
    cout << left << "Nome";
    cout << left << "Endereço de e-mail" << endl;

    for(auto show : catalogo){

        cout.width(MAXW);
        cout << left << show.first;
        cout <<left << show.second << endl;
    }
}

void alterarEnd(map<string, string> &catalogo){

    map<string, string>::iterator it;
    string resp, chave, nemail;
    int op = START;

    cout << "Informe o endereço a ser alterado no catálogo: ";
    cin >> resp;

    do{
        it = catalogo.find(resp);
        if(it != catalogo.end()){
            chave = it -> first;

            cout << "Informe o novo e-mail: ";
            cin >> nemail;
            catalogo[chave] = nemail;
            op++;
            break;
        }

        it = find_if(catalogo.begin(), catalogo.end(), [resp] (pair <string, string> proc) {return proc.second == resp;});
        if(it != catalogo.end()){ 
            chave = it -> first;

            cout << "Informe o novo e-mail: ";
            cin >> nemail;
            catalogo[chave] = nemail;
            op++;
            break;
        }
        
        else{

            cout << "Nome não encontrado! Infome Novamente: ";
            cin >> resp;
        }
    }while(op == START);

    cout << "Endereço alterado!" << endl;
}

void apagarEnd(map<string, string> &catalogo){

    map<string, string>::iterator it;
    string resp;
    int op = START;

    cout << "Informe o nome a ser removido do catálogo: ";
    cin >> resp;

    do{
        it = catalogo.find(resp);
        if(it != catalogo.end()){ catalogo.erase(it); op++; break;}

        it = find_if(catalogo.begin(), catalogo.end(), [resp] (pair <string, string> proc) {return proc.second == resp;});
        if(it != catalogo.end()){ catalogo.erase(it); op++; break;}
        
        else{

            cout << "Nome não encontrado! Infome Novamente: ";
            cin >> resp;
        }
    }while(op == START);

    cout << "Endereço apagado!" << endl;
}

void operacoes(map<string, string> &catalogo){

    int resp = START;

    do{
        system("clear");
        cout << "0 - Sair" << endl;
        cout << "1 - Cadastrar novo endereço" << endl;
        cout << "2 - Consultar endereço" << endl;
        cout << "3 - Alterar endereço" << endl;
        cout << "4 - Apagar endereço" << endl;

        cout << "\ninforme a operação a realizar: ";
        cin >>  resp;

        while(resp < SAIR or resp > APAGAR){

            cout << "operação errada! Tente novamente: ";
            cin >> resp;
        }

        switch(resp){

            case SAIR:
            break;

            case CADASTRO:
                cadastro(catalogo);
            break;

            case MOSTRAR:
                mostrarEnd(catalogo);
            break;

            case ALTERAR:
                mostrarEnd(catalogo);
                alterarEnd(catalogo);
            break;

            case APAGAR: 
                mostrarEnd(catalogo);
                apagarEnd(catalogo);
            break;
        }
    }while(resp != SAIR);
}

int main(){

    map<string, string> catalogo;

    operacoes(catalogo);

    return 0;
}