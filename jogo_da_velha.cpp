#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cctype> //isdigit
#include <string>
#include <fstream>

#define MAX 3                //o dimensao das matrizes

#ifndef INT_MAX
    #define INT_MAX 999999
#endif // INT_MAX

#define MENU_SAIR        -1
#define MENU_MULTIPLAYER  1
#define MENU_PLACAR       2
#define MENU_PLAYER_VS_PC 3

using namespace std;

int main() {
    int  vetor[MAX][MAX]  = {0};//vetor utilizado para marcar as posicoes escolhidas
    char grafic[MAX][MAX] = {' '};//vetor utilizado para pintar os simbolos
    int pos = 1;//contador de posicoes utilizado para preencher a matriz da legenda
    int posicaoEscolhida = 0;//Guarda a posicão que o jogador da vez escolheu
    bool running = false;//utilizada para marcar quando o jogo está ativo ou não
    int p1 = 1, p2 = 0;//utilizados para verificar qual jogador está jogando (1 para ativo e 0 para desativado)
    int player1_pontos = 0, player2_pontos = 0, empates = 0;
    int game_mode = 0;
    bool jogou = false; // variavel utilizada para controlar quando um jogador fez a jogado ou nao
    bool todosEscolhidos = true;//utilizada para vericar quando todas as posicoes já estiverem escolhidas
    bool posicaoLivre = true;
    bool proxima_partida = true;
    bool marcou_ponto = false;
    bool vetor_cheio = true;
    char p1S = 'X', p2S = 'O'; //p1 e p2 simbolo
    string s = "P1";
    string player1_name, player2_name;
    bool menu = true;
    int  menu_opcao = 0;

    while(menu) {
        cout << "*************** MENU *********************\n";
        cout << "       Escolha uma opcao: \n";
        cout << "       1 - multiplayer;\n";
        cout << "       2 - placares;\n";
        cout << "       3 - P1 VS PC\n";
        cout << "       Digite -1 para sair!\n";
        cout << "******************************************\n";

        cin >> menu_opcao;
        if(menu_opcao > 0 || menu_opcao == -1) {
            menu = false;
        }
        system("cls");


        switch(menu_opcao) {
            case MENU_MULTIPLAYER:{
                game_mode = MENU_MULTIPLAYER;
                //limpando o buffer do cin antes de usa-lo
                cin.clear();
                cin.ignore(INT_MAX, '\n');

                cout << "qual o nome do jogador 1 ? ";
                getline(cin, player1_name);
                cout << "qual o nome do jogador 2 ? ";
                getline(cin, player2_name);

                s = player1_name;
                running = true;
            }
            break;
            case MENU_PLACAR:{
                game_mode = MENU_PLACAR;
                //carregar o arquivo de pontuacao e exibir a lista na tela
                string linha;
                ifstream placar("placar.txt");
                if(!placar.is_open()) {
                    cout << "nao foi possivel abrir o arquivo placar.txt\n";
                    cout << "verificar se o arquivo existe e se tem permissao de leitura\n";
                }

                while(getline(placar, linha)){
                    cout << linha << "\n";
                }
                placar.close();
            }
            break;
            case MENU_PLAYER_VS_PC:{
                game_mode = MENU_PLAYER_VS_PC;
                running = true;

                return 0;
            }
            break;

            case MENU_SAIR:{
                return 0;
            }
            break;
        }


        while(running) {
            if(jogou) {
                jogou = false;
            }

            while(!jogou && proxima_partida) {
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

                if(posicaoEscolhida < 0) {
                    running = false;
                    break;
                }

                posicaoLivre = true;//flag utilizada para marcar quando a posicao escolhida esta disponivel ou não
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

                    //verificando se existe algum ganhador, ou seja, verificar todas as possibilidades de vitoria
                    int deu_linha = 0;//se deu linha preenchida, isso acontece quando eh igual a 3 [X, O, X] etc...
                    int linha_que_fechou = -1;
                    marcou_ponto = false;
                    for(int i=0; i< MAX; i++) {
                        deu_linha = 0;
                        for(int j=0; j< MAX; j++) {
                            if(vetor[i][j] > 0) {
                                deu_linha++;
                            }
                        }
                        marcou_ponto = false;
                        int simbolos_iguais = 0;
                        if(deu_linha == 3) {//significa qua a linha esta completamente preenchida
                            linha_que_fechou = i;
                            char simbolo_que_fechou = grafic[linha_que_fechou][0];
                            for(int k=0; k< MAX; k++) {
                                //verificando se eh o mesmo simbolo nas tres casas da linha preenchida
                                if(grafic[linha_que_fechou][k] == simbolo_que_fechou) {
                                    simbolos_iguais++;
                                }
                            }
                            if(simbolos_iguais == 3) {//sim eh o mesmo simbolo nas tres casas
                                marcou_ponto = true;
                                break;
                            }
                        }
                    }
                    //cout << "linha que fechou = " << linha_que_fechou << "\n\n";

                    // VERIFICACAO DAS COLUNAS
                    int deu_coluna = 0;
                    int coluna_que_fechou = -1;
                    if(deu_linha < 3) {
                        for(int j=0; j< MAX; j++) {
                            deu_coluna = 0;
                            for(int i=0; i< MAX; i++) {
                                if(vetor[i][j] > 0) {
                                    deu_coluna++;
                                }
                            }
                            marcou_ponto = false;
                            int simbolos_iguais = 0;
                            if(deu_coluna == 3) {//significa qua a coluna esta completamente preenchida
                                coluna_que_fechou = j;
                                char simbolo_que_fechou = grafic[0][coluna_que_fechou];
                                for(int k=0; k< MAX; k++) {
                                    //verificando se eh o mesmo simbolo nas tres casas da coluna preenchida
                                    if(grafic[k][coluna_que_fechou] == simbolo_que_fechou) {
                                        simbolos_iguais++;
                                    }
                                }
                                if(simbolos_iguais == 3) {//sim eh o mesmo simbolo nas tres casas
                                    marcou_ponto = true;
                                    break;
                                }
                            }
                        }
                    }

                    if(deu_coluna < 3) {
                        //VERIFICACAO DAS DIAGONAIS
                        if((grafic[0][0] == 'X' && grafic[1][1] == 'X' && grafic[2][2] == 'X') ||
                           (grafic[0][0] == 'O' && grafic[1][1] == 'O' && grafic[2][2] == 'O')) {
                            marcou_ponto = true;
                        }
                        else if((grafic[0][2] == 'X' && grafic[1][1] == 'X' && grafic[2][0] == 'X') ||
                                (grafic[0][2] == 'O' && grafic[1][1] == 'O' && grafic[2][0] == 'O')) {
                            marcou_ponto = true;
                        }
                    }

                    if(marcou_ponto) {
                        if(p1 == 1) {
                            player1_pontos++;
                        }
                        else if(p2 == 1) {
                            player2_pontos++;
                        }


                        //zerando as matrizes para comecar outra rodada
                        for(int i=0; i< MAX; i++) {
                            for(int j=0; j< MAX; j++) {
                                vetor[i][j]  = 0;
                                grafic[i][j] = ' ';
                            }
                        }
                    }else {
                        vetor_cheio = true;
                        for(int i=0; i< MAX; i++) {
                            for(int j=0; j< MAX; j++) {
                                if(vetor[i][j] == 0) {
                                    vetor_cheio = false;
                                    break;
                                }
                            }
                        }

                        if(vetor_cheio) {
                            empates++;
                            //zerando as matrizes para comecar outra rodada
                            for(int i=0; i< MAX; i++) {
                                for(int j=0; j< MAX; j++) {
                                    vetor[i][j]  = 0;
                                    grafic[i][j] = ' ';
                                }
                            }
                        }
                    }

                    //alterna os jogadores mudando o label do player correspondente
                    if(p1 == 1) {
                        p1 = 0;
                        p2 = 1;
                        s = player2_name;
                    }
                    else if(p2 == 1) {
                        p2 = 0;
                        p1 = 1;
                        if(game_mode == MENU_MULTIPLAYER) {
                            s = player1_name;
                        }
                        else if(game_mode == MENU_PLAYER_VS_PC) {
                            s = "CPU";
                        }
                        else {
                            s = "P2";
                        }
                    }
                    jogou = true;
                }
                else {
                    system("cls");
                    jogou = false;
                    //o jogador escolheu uma posicao ocupada, ele devera escolher a posicao novamente
                    cout << "a posicao '" << posicaoEscolhida << "' esta ocupada, escolha outra!\n";

                    cout << "\n\n";
                    for(int i=0; i< MAX; i++) {
                        for(int j=0; j< MAX; j++) {
                            cout << grafic[i][j] << " | ";
                        }
                        cout << endl;
                    }
                    cout << "\n\n";
                    continue;
                }

                system("cls");
                cout << "\n\n";
                cout << "****** PLACAR ******\n";
                cout << "*      P1 - " << player1_pontos << "      *\n";
                cout << "*      P2 - " << player2_pontos << "      *\n";
                cout << "*      E  - " << empates << "      *\n";
                cout << "********************\n";
                for(int i=0; i< MAX; i++) {
                    for(int j=0; j< MAX; j++) {
                        cout << grafic[i][j] << " | ";
                    }
                    cout << endl;
                }
                cout << "\n\n";
                cout << "posicoes que voce pode escolher!\n";

                if(vetor_cheio || marcou_ponto) {
                    char continua = ' ';
                    cout << "jogar proxima partida?(y/n)";
                    cin >> continua;
                    if(continua == 'y' || continua == 'Y'){
                        proxima_partida = true;
                        running         = true;
                    }else {
                        proxima_partida = false;
                        running         = false;
                    }
                }
            }
        }


        if(player1_pontos > 0 || player2_pontos > 0) {
            ofstream placar("placar.txt", ios::app);
            if(!placar.is_open()) {
                cout << "nao foi possivel gravar o placar!";
            }else {
                placar << player1_name << " , " << player1_pontos << " ";
                placar << player2_name << " , " << player2_pontos << " ";
                placar << endl;
                placar.close();
            }
        }

        cout << "jogou = " << jogou << "\n";
        cout << "proxima_partida = " << proxima_partida << "\n";
        cout << "running = " << running << "\n";
        //voltar ao menu principal,
        char decisao = ' ';
        cout << "deseja continuar no jogo (y/n)";
        cin >> decisao;
        if(decisao == 'y' || decisao == 'Y') {
            menu = true;
            system("cls");
        }
        else {
            menu = false;
            return 0;
        }
    }
    cout << "O JOGO TERMINOU!!\n\n";
    return 0;
}

