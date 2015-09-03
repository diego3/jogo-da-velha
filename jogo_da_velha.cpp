#include <iostream>
#include <cstdio>
#include <string.h>

#define MAX 3
#define MENU_JOGAR  1
#define MENU_SAIR   2
#define MENU_PLACAR 3

using namespace std;

int main() {
    int  vetor[MAX][MAX]  = {0};//vetor utilizado para marcar as posicoes escolhidas
    char grafic[MAX][MAX] = {' '};//vetor utilizado para pintar os simbolos
    int pos = 1;//contador de posicoes utilizado para preencher a matriz da legenda
    int posicaoEscolhida = 0;//Guarda a posicão que o jogador da vez escolheu
    bool running = false;//utilizada para marcar quando o jogo está ativo ou não
    int p1 = 1, p2 = 0;//utilizados para verificar qual jogador está jogando (1 para ativo e 0 para desativado)
    bool jogou = false; // variavel utilizada para controlar quando um jogador fez a jogado ou nao
    bool todosEscolhidos = true;//utilizada para vericar quando todas as posicoes já estiverem escolhidas
    char p1S = 'X', p2S = 'O'; //p1 e p2 simbolo
    string s = "P1";

    bool menu = true;
    int menu_opcao = 0;

    while(menu) {
        cout << "1 - jogar;\n";
        cout << "2 - placares;\n";
        cout << "-1 para sair\n";
        cout << "escolha uma opcao: \n";
        cin >> menu_opcao;
        if(menu_opcao > 0 || menu_opcao == -1) {
            menu = false;
        }
    }

    switch(menu_opcao) {
        case MENU_JOGAR:
            running = true;
        break;
        case MENU_PLACAR:
            //carregar o arquivo de pontuacao e exibir a lista na tela
            //fstream file = open("placar.txt", ios::);

        break;

        case MENU_SAIR:
            return 0;
        break;
    }


    while(running) {
        if(jogou) {
            jogou = false;
        }

        while(!jogou) {
            for(int i=0; i< MAX; i++) {
                for(int j=0; j< MAX; j++) {
                    cout << pos;
                    if(j < 3) {
                        cout << " | ";
                    }
                    pos++;
                }
                cout << "\n";
            }
            cout << "\n\n";
            pos = 1;

            cout << s << " escolha uma posicao: ";
            cin >> posicaoEscolhida;

            for(int i=0; i< MAX; i++) {
                for(int j=0; j< MAX; j++) {
                    if(vetor[i][j] == 0) {
                        todosEscolhidos = false;
                        break;
                    }
                }
            }

            if(todosEscolhidos) {
                running = false;
                break;
            }

            bool posicaoLivre = true;//flag utilizada para marcar quando a posicao escolhida esta disponivel ou não
            //verificando se a posicao escolhida esta livre ou ocupada
            switch(posicaoEscolhida) {
                case 1:
                    if(vetor[0][0] > 0) {
                        posicaoLivre = false;
                    }
                    break;
                case 2:
                    if(vetor[0][1] > 0) {
                        posicaoLivre = false;
                    }
                    break;
                case 3:
                    if(vetor[0][2] > 0) {
                        posicaoLivre = false;
                    }
                    break;
                case 4:
                    if(vetor[1][0] > 0) {
                        posicaoLivre = false;
                    }
                    break;
                case 5:
                    if(vetor[1][1] > 0) {
                        posicaoLivre = false;
                    }
                    break;
                case 6:
                    if(vetor[1][2] > 0) {
                        posicaoLivre = false;
                    }
                    break;
                case 7:
                    if(vetor[2][0] > 0) {
                        posicaoLivre = false;
                    }
                    break;
                case 8:
                    if(vetor[2][1] > 0) {
                        posicaoLivre = false;
                    }
                    break;
                case 9:
                    if(vetor[2][2] > 0) {
                        posicaoLivre = false;
                    }
                    break;
            }

            //debug temporário utilizado para verificar se a verificação das posicoes esta ok
            //cout << "a posicao esta ";
            //string a = posicaoLivre ? " livre " : " ocupada ";
            //cout << a << "\n\n";

            if(posicaoLivre) {
                //@todo fazer a jogada, ou seja, marcar a posicao do vetor com O ou X dependendo do player
                switch(posicaoEscolhida) {
                    case 1:
                        //marca a posicao como opcupada e pinta o quadro do jogo
                        vetor[0][0]  = 1;
                        grafic[0][0] = (p1 == 1) ?  p1S : p2S;//marca a posicao de acordo com o simbolo do jogador
                        break;
                    case 2:
                        vetor[0][1]  = 1;
                        grafic[0][1] = (p1 == 1) ?  p1S : p2S;
                        break;
                    case 3:
                        vetor[0][2]  = 1;
                        grafic[0][2] = (p1 == 1) ?  p1S : p2S;
                        break;
                    case 4:
                        vetor[1][0]  = 1;
                        grafic[1][0] = (p1 == 1) ?  p1S : p2S;
                        break;
                    case 5:
                        vetor[1][1]  = 1;
                        grafic[1][1] = (p1 == 1) ?  p1S : p2S;
                        break;
                    case 6:
                        vetor[1][2]  = 1;
                        grafic[1][2] = (p1 == 1) ?  p1S : p2S;
                        break;
                    case 7:
                        vetor[2][0]  = 1;
                        grafic[2][0] = (p1 == 1) ?  p1S : p2S;
                        break;
                    case 8:
                        vetor[2][1]  = 1;
                        grafic[2][1] = (p1 == 1) ?  p1S : p2S;
                        break;
                    case 9:
                        vetor[2][2]  = 1;
                        grafic[2][2] = (p1 == 1) ?  p1S : p2S;
                        break;
                }

                //@todo verificar se existe algum ganhador, ou seja, verificar todas as possibilidades de vitoria
                // ou se deu empate, no fim desse processo marcar running como falso para sair do jogo

                //alterna os jogadores mudando o label do player
                if(p1 == 1) {
                    p1 = 0;
                    p2 = 1;
                    s  = "P1";
                }
                else if(p2 == 1) {
                    p2 = 0;
                    p1 = 1;
                    s  = "P2";
                }
                jogou = true;
            }
            else {
                jogou = false;
                //o jogador escolheu uma posicao ocupada, ele devera escolher a posicao novamente
                cout << "a posicao '" << posicaoEscolhida << "' esta ocupada, escolha outra!\n";
                continue;
            }
            cout << "\n\n";
            for(int i=0; i< MAX; i++) {
                for(int j=0; j< MAX; j++) {
                    cout << grafic[i][j] << " | ";
                }
                cout << endl;
            }
        }

    }

    cout << " o jogo terminou!!\n\n";
    return 0;
}

