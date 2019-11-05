#include <iostream>
#include <map>
#include <vector>

using namespace std;

void coletarInfo(vector <map<string, map<string, string>>> &vetor){

    string local, priori, resp;

    do{
    
    cout << "\nInforme o local [sair para cancelar]: ";
    cin >> local;

    if(local == "sair") break;

    cout << "Informe a prioridade: ";
    cin >> priori;

    cout << "Informe o responsável: ";
    cin >> resp;

    map<string, map<string, string>> temp;

    temp[local][priori] = resp;

    vetor.push_back(temp);
    
    }while(local != "sair");
    
}

void mostrarDados(vector <map<string, map<string, string>>> &vetor){

    cout.width(15);
    cout << left << "Local";
    cout.width(15);
    cout << left << "Prioridade";
    cout << left << "Responsável" << endl;
    
    for(auto elemento : vetor){
        for(auto loc : elemento){
            for(auto prioriResp : loc.second){

            cout.width(15);
            cout << left << loc.first;
            cout.width(15);
            cout << left << prioriResp.first;
            cout << left << prioriResp.second << endl;

            }
        }
    }
}

int main(){

    vector <map<string, map<string, string>>> lpr;

    coletarInfo(lpr);

    mostrarDados(lpr);

    return 0;
}