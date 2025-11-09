#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

const int TAM = 31;

struct Player {
    string nome;
    int pos;
    bool perdeVez = false;
    bool esperaUltrapassagem = false;
};

Player jogadores[3] = {
    {"António", 1},
    {"Rebeca", 1},
    {"Joaquim", 1}
};


void tabela(Player jogadores[], int numJogadores) {
    cout << "\ntabuleiro\n\n";
    for (int i = 1; i < TAM; i++) {
        bool casaOcupada = false;

        cout << "[";
        if (i < 10) cout << " "; 
        cout << i << "] ";

        for (int j = 0; j < numJogadores; j++) {
            if (jogadores[j].pos == i) {
                cout << jogadores[j].nome[0];
                casaOcupada = true;
            }
        }

        if (!casaOcupada) cout << "_";
        cout << "  ";

        if ((i + 1) % 10 == 0) cout << endl;
    }
    cout << endl;
}


int aplicarEfeitoCasa(Player &p, Player jogadores[], int numJogadores) {
    switch (p.pos) {
        case 5:
            cout << p.nome << " caiste na casa 5,Perdeste a próxima vez!\n";
            p.perdeVez = true;
            break;
        case 10:
            cout << p.nome << " caiste na casa 10,Voltas 3 casas!\n";
            p.pos -= 3;
            if (p.pos < 1) p.pos = 1;
            break;
        case 15:
            cout << p.nome << " caiste na casa 15,Avança 3 casas!\n";
            p.pos += 3;
            if (p.pos > 30) p.pos = 30;
            break;
        case 20:
            cout << p.nome << " caiste na casa 20,Joga novamente!\n";
            return 1; // sinaliza que joga novamente
        case 25:
            cout << p.nome << " caiste na casa 25,Espera que todos te ultrapassem!\n";
            p.esperaUltrapassagem = true;
            break;
        default:
            break;
    }
    return 0;
}


bool podeJogar(Player &p, Player jogadores[], int numJogadores) {
    if (p.perdeVez) {
        cout << p.nome << " perdeste a vez de jogar.\n";
        p.perdeVez = false;
        return false;
    }

    if (p.esperaUltrapassagem) {
        bool todosUltrapassaram = true;
        for (int i = 0; i < numJogadores; i++) {
            if (jogadores[i].nome != p.nome && jogadores[i].pos <= p.pos) {
                todosUltrapassaram = false;
            }
        }
        if (todosUltrapassaram) {
            cout << p.nome << " já foste ultrapassado por todos,podes voltar a jogar!\n";
            p.esperaUltrapassagem = false;
            return true;
        } else {
            cout << p.nome << " ainda não foi ultrapassado por todos, espera a vez.\n";
            return false;
        }
    }

    return true;
}


bool moverJogador(Player &p, Player jogadores[], int numJogadores) {
    cout << "\nToca Enter para jogares (" << p.nome << "): ";
    cin.get();

    int dado = rand() % 6 + 1;
    p.pos += dado;
    if (p.pos > 30) p.pos = 30;

    system("clear"); // limpa terminal
    tabela(jogadores, numJogadores);

    cout << p.nome << " lançou o dado e te mexeste " << dado << " casas  agora tas na posição " << p.pos << "!\n";

    int repetir = aplicarEfeitoCasa(p, jogadores, numJogadores);

    if (repetir == 1 && p.pos < 30) {
        cout << "\n" << p.nome << " joga novamente!\n";
        cout << "(Toca Enter para continuares)\n";
        cin.get();
        system("clear");
        tabela(jogadores, numJogadores);
        return moverJogador(p, jogadores, numJogadores); // joga novamente
    }

    cout << "\n(Toca Enter para continuares)\n";
    cin.get();

    return p.pos == 30;
}


int main() {
    srand(time(0));

    bool jogoAtivo = true;
    int numJogadores = 3;

    system("clear"); // limpa no início
    tabela(jogadores, numJogadores);

    while (jogoAtivo) {
        for (int i = 0; i < numJogadores && jogoAtivo; i++) {

            if (!podeJogar(jogadores[i], jogadores, numJogadores)) {
                cout << "(Toca Enter para continuares)\n";
                cin.get();
                system("clear");
                tabela(jogadores, numJogadores);
                continue;
            }

            bool venceu = moverJogador(jogadores[i], jogadores, numJogadores);

            if (venceu) {
                system("clear");
                tabela(jogadores, numJogadores);
                cout << endl << jogadores[i].nome << " venceste o jogo!\n";
                jogoAtivo = false;
            }
        }
    }

    return 0;
}
