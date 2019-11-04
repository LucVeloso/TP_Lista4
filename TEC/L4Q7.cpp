#include <iostream>
#include <map>

using namespace std;

float calcTotal(map <string, map <int, float>>& feira){

    float total = 0;

    for(auto item : feira){
        for(auto quantVal : item.second){

            total += quantVal.first * quantVal.second;
        }
    }

    return total;
}

pair <string, float> pegarMaior(map <string, map <int, float>> feira){

    float maior = 0;
    string prod;
    pair <string, float> result;

    for(auto item : feira){
        for(auto quantVal : item.second){

            if(maior < quantVal.first * quantVal.second){

                maior = quantVal.first * quantVal.second;
                prod = item.first;
            }
        }
    }

    result = make_pair(prod, maior);

    return result;
}

pair <string, float> pegarMenor(map <string, map <int, float>> feira){

    float menor = 0;
    string prod;
    pair <string, float> result;

    prod = ;

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
    int quant = 0;
    float valor = 0, total = 0, media = 0;
    pair <string, float> maior, menor;
    map <string, map <int, float>> feira;

    while(item != "sair"){

        cout << "\nInforme o produto:";
        cin >> item;

        if(item == "sair") break;

        cout << "Informe a quantidade:";
        cin >> quant;
        
        cout << "Informe o preço:";
        cin >> valor;

        feira[item][quant] = valor;
    }  

    total = calcTotal(feira);
    media = total / feira.size();

    maior = pegarMaior(feira);
    menor = pegarMenor(feira);

    cout << "\nTotal: " << total << endl;
    cout << "Média: " << media << endl;
    cout << "Maior valor: " << maior.first << ", " << maior.second << endl;
    cout << "Menor valor: " << menor.first << ", " << menor.second << endl;

    cout.width(15);
    cout << left << "Produto";
    cout.width(15);
    cout << left << "Quantidade";
    cout << "Preço" << endl;

    for(auto item : feira){
        for(auto quantVal : item.second){

            cout.width(15);
            cout << left << item.first;
            cout.width(15);
            cout << left << quantVal.first;
            cout << quantVal.second << endl;
        }
    }

    return 0;
}