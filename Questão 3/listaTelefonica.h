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
