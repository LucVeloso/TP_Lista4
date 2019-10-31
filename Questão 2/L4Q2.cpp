#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

int main(){

    string entrada;
    map<char, int> contador;

    cout << "Informe a sentença: ";
    getline(cin, entrada);


    for(int procurar = 0; procurar < entrada.size(); procurar++){

        if(entrada[procurar] != ' ') contador[entrada[procurar]] = count(entrada.begin(), entrada.end(), entrada[procurar]);
    }
    
    for(auto show : contador){

        cout << show.first << ": " << show.second << ", ";
    }
    return 0;
}