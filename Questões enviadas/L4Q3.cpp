#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

void cadastro(map<string, string> &t, string n){

    string numero;

    cout << "Informe o numero de " << n <<": ";
    cin >> t[n];
}

bool procurarNome(map<string, string> t, string n){

    if(t.find(n) != t.end()) return true;
    else return false;
}

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