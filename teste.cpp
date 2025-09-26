#include <iostream>

using namespace std;

/*
Exercicio:
    - Cria uma struct ao teu critério com 2 valores(global) 
    - Cria uma instância da tua struct com valores
    - Cria uma função <void> que aceita como parâmetro a struct
    - A função deve imprimir no ecrã os valores instânciados na struct.
*/
struct Carro{
    string marca;
    int ano;
};

Carro c1 = {"BMW",2021};

void mostraCarro(Carro x){
    cout << x.marca << endl;
    cout << x.ano << endl;
}

int main(){
    mostraCarro(c1);
}

/* solução mais harmoniosa
    struct comando{
        string marca;
        int numBotao;
        }
    
    comando c1 = {"Promethean",10}
    void mostraComando(comando &c1){
        cout << c1.marca << endl;
        cout << c1.numBotao << endl;
    }
*/