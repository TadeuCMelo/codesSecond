/*
{
"background.fullscreen": {
    "images": ["https://th.bing.com/th/id/R.45d2f253d7d13f3594167926796f2425?rik=wS%2f5JEJjfDTkDw&riu=http%3a%2f%2fgetwallpapers.com%2fwallpaper%2ffull%2fd%2fc%2f0%2f271697.jpg&ehk=Bxx10ttRR%2fesxhZDszZ5Nx1bL1Zuq4sLSGuNhb40xf8%3d&risl=&pid=ImgRaw&r=0"], // urls of your images
    "opacity": 0.91, // 0.85 ~ 0.95 recommended
    "size": "cover", // also css, `cover` to self-adaption (recommended)，or `contain`、`200px 200px`
    "position": "center", // alias to `background-position`, default `center`
    "interval": 0 // seconds of interval for carousel, default `0` to disabled.
},
"background.editor": {
    

    "useFront": true,
    "style": {
        "background-position": "100% 100%",
        "background-size": "auto",
        "opacity": 0.6
    },
    "styles": [
        {},
        {},
        {}
    ],
    "images": [],
    "interval": 0,
    "random": false
}
}
*/


#include <iostream>

using namespace std;

class Personagem{
    public:
        int hp;
        int xp;
        int attack1;
};

class Inimigos{
    public:
        int hp;
        int RecompensaXP;
        int attack1;
};





Personagem Tadeu{100, 0, 10000};
Inimigos Zell{150, 15, 10};

void dano(){
    //
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
  int opcao;
    cout << "\n=== MENU PRINCIPAL ===\n";
    cout << "1 - Entrar no Mundo\n";
    cout << "2 - Ver estatísticas\n";
    cout << "3 - Sair\n";
    cout << "Escolhe uma opção: ";
    cin >> opcao;

    switch (opcao) {
        case 1:
            dano();
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
