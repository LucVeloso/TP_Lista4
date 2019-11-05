#include <iostream>
#include <fstream>
#include <map>
#define MAXW 20

using namespace std;

int main(){

    ifstream ent;

    string palavra;
    map<string, int> freq;

    ent.open("Palavras.txt");

    while(ent >> palavra){

        ++freq[palavra];
    }

    cout.width(MAXW);
    cout << left << "Palavra";
    cout << "Frequência" << endl;

    for(auto show : freq){

        cout.width(MAXW);
        cout << left << show.first;
        cout << show.second << endl;;
    }

    return 0;
}