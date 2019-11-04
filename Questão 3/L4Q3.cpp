#include <iostream>
#include <map>
#include "listaTelefonica.h"

using namespace std;

int main(){
    
    map<string, string> telefones;
    string nome, telefone;
    bool proc;

    while(nome != "sair"){

        cout << "Informe o nome: ";
        cin >> nome;

        if(nome == "sair") break;

        proc = procurarNome(telefones, nome);

        if(!proc) cadastro(telefones, nome);
        else cout << nome << ": " << telefones[nome] << endl;
    }

    return 0;
}