#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <windows.h>

using namespace std;

// --- SUB-ROTINAS ---

// 1. Procedimento para limpar a tela
void limparTela() {
    system("cls");
}

// 2. Procedimento clássico para desenho da matriz
void exibirTabuleiro(int tabuleiro[10][10], bool revelado[10][10], int linhas, int colunas, string nomeJogador, int paresEncontrados, int totalPares) {
    limparTela();
    cout << "================================================" << endl;
    cout << "   JOGO DA MEMORIA - Vez de: " << nomeJogador << endl;
    cout << "   Pares encontrados: " << paresEncontrados << " / " << totalPares << endl;
    cout << "================================================" << endl;

    cout << "    ";
    for (int c = 1; c <= colunas; c++) {
        cout << c << "  ";
    }
    cout << endl;

    cout << "    ";
    for (int i = 0; i < colunas * 3; i++) {
        cout << "-";
    }
    cout << endl;

    for (int l = 1; l <= linhas; l++) {
        cout << l << " | ";
        for (int c = 1; c <= colunas; c++) {
            if (revelado[l][c] == true) {
                cout << tabuleiro[l][c] << "  ";
            } else {
                cout << "*  ";
            }
        }
        cout << endl;
    }
    cout << "================================================" << endl;
}

// 3. Função clássica para verificação de acerto
bool verificarPar(int tabuleiro[10][10], int l1, int c1, int l2, int c2) {
    if (tabuleiro[l1][c1] == tabuleiro[l2][c2]) {
        return true;
    } else {
        return false;
    }
}

// 4. Procedimento com parâmetro por referência (exigência do professor)
void lerPosicao(int &l, int &c, int linhas, int colunas, bool revelado[10][10], string msg) {
    while (true) {
        cout << msg << " (linha coluna): ";
        cin >> l >> c;

        if (l < 1 || l > linhas || c < 1 || c > colunas) {
            cout << "ERRO: Posicao invalida! Use Linha (1-" << linhas << ") e Coluna (1-" << colunas << ").\n";
        } else if (revelado[l][c] == true) {
            cout << "Esta carta ja foi descoberta! Escolha outra.\n";
        } else {
            break;
        }
    }
}

// 5. Procedimento para inicializar e embaralhar o tabuleiro
void inicializarJogo(int tabuleiro[10][10], bool revelado[10][10], int modo, int &linhas, int &colunas, int &totalPares) {
    int numPares;
    if (modo == 1) {
        totalPares = 9;
        linhas = 3;
        colunas = 6;
        numPares = 9;
    } else {
        totalPares = 12;
        linhas = 4;
        colunas = 6;
        numPares = 12;
    }

    int cartas[24];
    for (int i = 0; i < numPares; i++) {
        cartas[i * 2] = i + 1;
        cartas[i * 2 + 1] = i + 1;
    }

    srand(time(NULL));
    int totalCartas = linhas * colunas;
    for (int i = 0; i < totalCartas; i++) {
        int pos = rand() % totalCartas;
        int temp = cartas[i];
        cartas[i] = cartas[pos];
        cartas[pos] = temp;
    }

    int idx = 0;
    for (int l = 1; l <= linhas; l++) {
        for (int c = 1; c <= colunas; c++) {
            tabuleiro[l][c] = cartas[idx];
            revelado[l][c] = false;
            idx++;
        }
    }
}

// 6. Procedimento para ler dados iniciais
void lerDadosIniciais(int &modo, int &numJog, string nomes[]) {
    cout << "=== BEM VINDO AO JOGO DA MEMORIA ===\n";
    cout << "Escolha o modo de jogo:\n1 - Rapido (18 cartas)\n2 - Normal (24 cartas)\nOpcao: ";
    cin >> modo;

    cout << "Quantidade de jogadores (1-2): ";
    cin >> numJog;

    for (int i = 0; i < numJog; i++) {
        cout << "Digite o nome do jogador " << i + 1 << ": ";
        cin >> nomes[i];
    }
}

int main() {
    setlocale(LC_ALL, "Portuguese");

    int modo, numJog;
    string nomes[2];
    int pontos[2] = {0, 0};
    int jogadas[2] = {0, 0};

    int tabuleiro[10][10];
    bool revelado[10][10];
    int linhas, colunas, totalPares;

    lerDadosIniciais(modo, numJog, nomes);
    inicializarJogo(tabuleiro, revelado, modo, linhas, colunas, totalPares);

    // Momento de memorização
    limparTela();
    cout << "PREPARE-SE! O tabuleiro sera exibido por alguns segundos...\n";
    Sleep(1000);

    // Revela tudo temporariamente
    for (int l = 1; l <= linhas; l++) {
        for (int c = 1; c <= colunas; c++) {
            revelado[l][c] = true;
        }
    }

    // Desenha o gabarito para os jogadores
    exibirTabuleiro(tabuleiro, revelado, linhas, colunas, "MEMORIZACAO", 0, totalPares);

    int tempoVisao = (modo == 1) ? 3000 : 5000;
    Sleep(tempoVisao);

    // Esconde as cartas novamente
    for (int l = 1; l <= linhas; l++) {
        for (int c = 1; c <= colunas; c++) {
            revelado[l][c] = false;
        }
    }

    int paresEncontrados = 0;
    int turno = 0;

    while (paresEncontrados < totalPares) {
        int j_atual = turno % numJog;

        exibirTabuleiro(tabuleiro, revelado, linhas, colunas, nomes[j_atual], paresEncontrados, totalPares);

        int l1, c1, l2, c2;
        lerPosicao(l1, c1, linhas, colunas, revelado, "Escolha a PRIMEIRA carta");
        revelado[l1][c1] = true;
        exibirTabuleiro(tabuleiro, revelado, linhas, colunas, nomes[j_atual], paresEncontrados, totalPares);

        lerPosicao(l2, c2, linhas, colunas, revelado, "Escolha a SEGUNDA carta");
        revelado[l2][c2] = true;

        jogadas[j_atual]++;
        exibirTabuleiro(tabuleiro, revelado, linhas, colunas, nomes[j_atual], paresEncontrados, totalPares);

        if (verificarPar(tabuleiro, l1, c1, l2, c2)) {
            cout << "ACERTOU! +1 ponto para o jogador " << nomes[j_atual] << endl;
            pontos[j_atual]++;
            paresEncontrados++;
        } else {
            cout << "ERROU! O jogador " << nomes[j_atual] << " nao pontuou." << endl;
            Sleep(2000);
            revelado[l1][c1] = false;
            revelado[l2][c2] = false;
        }

        cout << "\nPressione ENTER para continuar...";
        cin.ignore();
        cin.get();
        turno++;
    }

    // Fim de jogo
    limparTela();
    cout << "================================================" << endl;
    cout << "                FIM DE JOGO                     " << endl;
    cout << "================================================" << endl;
    for (int i = 0; i < numJog; i++) {
        cout << "Jogador " << nomes[i] << " - Pontos: " << pontos[i]
             << " | Jogadas: " << jogadas[i] << endl;
    }
    cout << "================================================" << endl;

    return 0;
}
