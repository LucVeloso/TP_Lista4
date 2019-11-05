#include <iostream>
#include <map>

using namespace std;

int main(){

    int maior = 0;
    int inicio = 1;
    map<int, int> num;

    cout << "Informe o maior número: ";
    cin >> maior;

    while(inicio <= maior){

        num[inicio] = inicio * inicio;
        inicio++;
    }

    cout << "{";

    for(auto show : num){

        cout << show.first << ": " << show.second << ", ";
    }

    cout << "}" << endl;

    return 0;
}