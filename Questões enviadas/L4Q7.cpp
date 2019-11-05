#include <iostream>
#include <map>
#include <iomanip>
#define MAXW 15
#define PRECISAO 2
#define START 0

using namespace std;

float calcTotal(map <string, map <int, float>>& feira){

    float total = START;

    for(auto item : feira){
        for(auto quantVal : item.second){

            total += quantVal.first * quantVal.second;
        }
    }

    return total;
}

pair <string, float> pegarMaior(map <string, map <int, float>> feira){

    float maior = START;
    string prod;
    pair <string, float> result;

    for(auto item : feira){
        for(auto quantVal : item.second){
            if(maior <= quantVal.first * quantVal.second){

                maior = quantVal.first * quantVal.second;
                prod = item.first;
            }
        }
    }

    result = make_pair(prod, maior);

    return result;
}

pair <string, float> pegarMenor(map <string, map <int, float>> feira){

    float menor = START;
    string prod;
    pair <string, float> result;
    map <int, float> valores;
    
    prod = feira.begin() -> first;
    valores = feira.begin() -> second;
    menor = valores.begin() -> first * valores.begin() -> second;

    for(auto item : feira){
        for(auto quantVal : item.second){
            if(menor > quantVal.first * quantVal.second){

                menor = quantVal.first * quantVal.second;
                prod = item.first;
            }
        }
    }

    result = make_pair(prod, menor);

    return result;
}

int main(){

    string item;
    int quant = START;
    float valor = START, total = START, media = START;
    pair <string, float> maior, menor;
    map <string, map <int, float>> feira;

    while(item != "sair"){

        cout << "\nInforme o produto: ";
        getline(cin, item);

        if(item == "sair") break;

        cout << "Informe a quantidade: ";
        cin >> quant;
        
        cout << "Informe o preço: ";
        cin >> valor;

        feira[item][quant] = valor;
        cin.ignore();
    }  

    total = calcTotal(feira);
    media = total / feira.size();

    maior = pegarMaior(feira);
    menor = pegarMenor(feira);

    cout << "\nTotal: " << total << endl;
    cout << "Média: " << media << endl;
    cout << "Maior valor: R$ " << maior.first << ", R$ " << fixed << setprecision(PRECISAO) << maior.second << endl;
    cout << "Menor valor: R$ " << menor.first << ", R$ " << fixed << setprecision(PRECISAO) << menor.second << endl;

    cout.width(MAXW);
    cout << left << "Produto";
    cout.width(MAXW);
    cout << left << "Quantidade";
    cout << "Preço" << endl;

    for(auto item : feira){
        for(auto quantVal : item.second){

            cout.width(MAXW);
            cout << left << item.first;
            cout.width(MAXW);
            cout << left << quantVal.first;
            cout << "R$ " << fixed << setprecision(PRECISAO) << quantVal.second << endl;
        }
    }

    return 0;
}
