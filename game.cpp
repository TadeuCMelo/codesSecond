#include <iostream>

using namespace std;

class Personagem{
    public:
    string nome;
        float hp;
        float xp;
        float attack1;
        string itens;
};

class Inimigos{
    public:
        float hp;
        int RecompensaXP;
        int attack1;
};





Personagem Tadeu{"",100, 0, 10000};
Inimigos Zell{150, 15, 10};
Personagem Personagens{"",100,0,10000};

void world(){

// ataque
    bool win = false;
    char ataque;
        while (true) {
        cout << "Queres atacar? (s/n): ";
        cin >> ataque;
 
    if(ataque == 's' || ataque == 'S'){
        Zell.hp-=Tadeu.attack1;

    //receber recompensas e as mensagens da recompensa ou perder
if(Zell.hp <= 0){
    //Recompensas
    win = true;
    Tadeu.xp+=Zell.RecompensaXP;
    Tadeu.hp = 100;

    //mensagens
    cout << "Ganhaste a primeira luta" << endl;
    cout << "Recebeste " << Zell.RecompensaXP << "XP" << endl;
    cout << "Tens " << Tadeu.xp << "XP\n";
    break;
}else{
    cout << "Continuas a lutar! HP do inimigo: " << Zell.hp  << endl;
}
 }else if(ataque == 'n' || ataque == 'N'){
    cout << "Voltaste atrás. Nenhum ataque foi feito\n";
    break;
 }else{
    cout << "Opção Inválida! Tenta denovo" << endl;
 }
}
}

int main(){
    string x;
    cout << "Escreve um Nome para o seu personagem: ";
    cin >> x;
    Personagens.nome = x;
  int opcao;
    cout << "\n=== MENU PRINCIPAL ===\n";
    cout << "1 - Entrar no Mundo\n";
    cout << "2 - Ver estatísticas\n";
    cout << "3 - Sair\n";
    cout << "Escolhe uma opção: ";
    cin >> opcao;

    switch (opcao) {
        case 1:
            world();
            break;
        case 2:
            cout << "\n--- Estatísticas ---\n";
            cout << "HP: " << Tadeu.hp << endl;
            cout << "XP: " << Tadeu.xp << endl;
            cout << "Ataque: " << Tadeu.attack1 << endl;
            break;
        case 3:
            cout << "A sair do jogo... Até logo!\n";
            break;
        default:
            cout << "Opção inválida!\n";
            break;
    }



}
