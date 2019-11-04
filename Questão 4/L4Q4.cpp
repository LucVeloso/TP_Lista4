#include <iostream>
#include <map>

using namespace std;

int main(){

    string local, priori, resp;
    map<string, map<string, string>> lpr;

    cout << "Informe o local: ";
    cin >> local;

    cout << "Informe a prioridade: ";
    cin >> priori;

    cout << "Informe o responsável: ";
    cin >> resp;

    lpr[local][priori] = resp;

    cout.width(15);
    cout << left << "Local";
    cout.width(15);
    cout << left << "Prioridade";
    cout << left << "Responsável" << endl;
    
    for(auto loc : lpr){
        for(auto prioriResp : loc.second){

            cout.width(15);
            cout << left << loc.first;
            cout.width(15);
            cout << left << prioriResp.first;
            cout << left << prioriResp.second << endl;
        }
    }

    return 0;
}