#include <iostream>
#define MAX 3

using namespace std;

int main() {
    int  vetor[MAX][MAX]  = {0};
    char grafic[MAX][MAX] = {' '};
    int pos = 1;//contador de posicoes utilizado para preencher a matriz da legenda
    int posicaoEscolhida = 0;//Guarda a posicão que o jogador da vez escolheu
    bool running = true;//utilizada para marcar quando o jogo está ativo ou não
    int p1 = 1, p2 = 0;//utilizados para verificar qual jogador está jogando (1 para ativo e 0 para desativado)
    bool jogou = false; // variavel utilizada para controlar quando um jogador fez a jogado ou nao
    char p1S = 'X', p2S = 'O'; //p1 e p2 simbolo
    string s = "P1";

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
            pos = 1;

            /*if(p1 > 0) {
                p2 = 0;
                cout << "P1 ";
            }
            else if(p2 > 0){
                p1 = 0;
                cout << "P2 ";
            }

            /*
                00 01 02     1 2 3
                10 11 12     4 5 6
                20 21 22     7 8 9
            */

            cout << s << " escolha uma posicao: ";
            cin >> posicaoEscolhida;

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
                cout << "a posicao '" <<posicaoEscolhida<< "' esta ocupada, escolha outra!\n";
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

