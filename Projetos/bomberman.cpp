// Jogo inspirado em Bomberman, desenvolvido para a disciplina de Programação 2

#include <iostream>
#include <windows.h>
#include <conio.h>
#include <ctime>
#define TAM 21
using namespace std;

void exibirTelaVitoria() {
    system("cls");
    cout<< "-------------------------------" << endl;
    cout << "         VOCE VENCEU!!        " << endl;
    cout << "------------------------------" << endl;
    system("pause");
}

void exibirTelaDerrota() {
    system("cls");
    cout<< "-------------------------------" << endl;
    cout << "           GAME OVER!!        " << endl;
    cout << "------------------------------" << endl;
    system("pause");
}

bool verificarVitoria(int inimigoX, int inimigoY, int inimigo2X, int inimigo2Y, int inimigo3X, int inimigo3Y) {
    //Checa se todos os inimigos estão mortos (coordenadas -1, -1)
    if(inimigoX == -1 && inimigoY == -1 && inimigo2X == -1 && inimigo2Y == -1 && inimigo3X == -1 && inimigo3Y == -1) {
        return true; // O jogador venceu se todos os inimigos estiverem mortos
    }else {
        return false; // O jogo continua se ainda houver inimigos vivos
    }

}

void verificarContato(int personagemX, int personagemY, int inimigoX, int inimigoY, bool &jogoAtivo) {

    if (personagemX == inimigoX && personagemY == inimigoY) {
        jogoAtivo = false; // Encerra o jogo se o personagem encontrar um inimigo
    }
}

void limparExplosao(int m[TAM][TAM], int fogoX, int fogoY) {

    // Limpa a explosão
   if(fogoX >= 0 && fogoX < TAM && fogoY >= 0 && fogoY < TAM) {
        if(m[fogoX][fogoY] == 4) {
            m[fogoX][fogoY] = 0; // Centro da explosão
        }
    }

    if(fogoX - 1 >= 0) {
        if(m[fogoX-1][fogoY] == 4) {
        m[fogoX-1][fogoY] = 0; // Cima
        }
    }

    if(fogoX + 1 < TAM) {
        if(m[fogoX+1][fogoY] == 4) {
            m[fogoX+1][fogoY] = 0; // Baixo
        }
    }
    if(fogoY - 1 >= 0) {
        if(m[fogoX][fogoY-1] == 4) {
            m[fogoX][fogoY-1] = 0; // Esquerda
        }
    }
    if(fogoY + 1 < TAM) {
        if(m[fogoX][fogoY+1] == 4) {
            m[fogoX][fogoY+1] = 0; // Direita
        }
    }
}


void desenharExplosao(int m[TAM][TAM], int fogoX, int fogoY){

    //Desenha a explosão
    if(m[fogoX][fogoY] == 0) {
        m[fogoX][fogoY] = 4; // Centro da explosão
    }

    if(m[fogoX-1][fogoY] != 1) {
     m[fogoX-1][fogoY] = 4; // Cima
    }

    if(m[fogoX+1][fogoY] != 1) {
        m[fogoX+1][fogoY] = 4; // Baixo
    }

    if(m[fogoX][fogoY-1] != 1) {
        m[fogoX][fogoY-1] = 4; // Esquerda
    }

    if(m[fogoX][fogoY+1] != 1) {
        m[fogoX][fogoY+1] = 4; // Direita
    }

}

void colocarBomba (int x, int y, int &bombaX, int &bombaY, DWORD &tempobomba, bool &bombaAtiva) {
    if (!bombaAtiva) {
        tempobomba = GetTickCount();
        bombaAtiva = true;
        bombaX = x;
        bombaY = y;
    }
}

bool raioExplosao(int alvoX, int alvoY, int bombaX, int bombaY) {
    // Verifica se o alvo está na mesma posição da bomba
    if (alvoX == bombaX && alvoY == bombaY) {
        return true;
    }

    // Verifica se o alvo está na mesma linha ou coluna e a uma distância de 1
    if (alvoX == bombaX - 1 && alvoY == bombaY) {
        return true; // Cima
    }
    if (alvoX == bombaX + 1 && alvoY == bombaY) {
        return true; // Baixo
    }
    if (alvoX == bombaX && alvoY == bombaY - 1) {
        return true; // Esquerda
    }
    if (alvoX == bombaX && alvoY == bombaY + 1) {
        return true; // Direita
    }

    // Se não estiver no raio de explosão
    return false;
}

void verificarMorte(int &coordenadaX, int &coordenadaY, int &bombaX, int &bombaY){

    if(coordenadaX == -1 && coordenadaY == -1) {
        return; // Já está morto, não precisa verificar
    }

    if(raioExplosao(coordenadaX, coordenadaY, bombaX, bombaY)) {

        //Morte personagem ou inimigo
        coordenadaX = -1;
        coordenadaY = -1;
    }
}


void gerenciarBomba(
    int m[TAM][TAM],
    int &bombaX,
    int &bombaY,
    bool &bombaAtiva,
    DWORD &tempobomba,
    bool &explodindo,
    DWORD &tempoExplodindo,
    int &fogoX,
    int &fogoY,
    int &personagemX,
    int &personagemY,
    int &inimigoX,
    int &inimigoY,
    int &inimigo2X,
    int &inimigo2Y,
    int &inimigo3X,
    int &inimigo3Y,
    bool &jogoAtivo) {

    // 1. Se o interruptor está desligado, não faz nada
    if (!bombaAtiva && !explodindo) {
        return;
    }

    // 2. Olha o relógio agora
    DWORD agora = GetTickCount();

    // 3. Verifica se já se passaram 3 segundos
    if (bombaAtiva && (agora - tempobomba > 3000)) {

        bombaAtiva = false; // Desliga a bomba
        explodindo = true; // Ativa a explosão
        tempoExplodindo = agora; // Marca o tempo que a explosão começou
        fogoX = bombaX; // Marca a posição do fogo para limpar depois
        fogoY = bombaY;

        desenharExplosao(m, fogoX, fogoY); // Desenha a explosão no mapa


        verificarMorte(personagemX, personagemY, bombaX, bombaY);
        verificarMorte(inimigoX, inimigoY, bombaX, bombaY);
        verificarMorte(inimigo2X, inimigo2Y, bombaX, bombaY);
        verificarMorte(inimigo3X, inimigo3Y, bombaX, bombaY);

        if(personagemX == -1 && personagemY == -1) {
            jogoAtivo = false; // Encerra o jogo se o personagem morrer
        }
    }

    if (explodindo) {
        //checa se morreu ao entrar no fogo
        if (m[personagemX][personagemY] == 4) {
            personagemX = -1;
            personagemY = -1;
            jogoAtivo = false;
        }

        //check para ver se ja passou o tempo pra apagar o fogo
        if (agora - tempoExplodindo > 500) {
            limparExplosao(m, fogoX, fogoY);
            explodindo = false;
        }
    }
}

bool verificaCaminho(int m[TAM][TAM], int x, int y, int bombaX, int bombaY, bool bombaAtiva) {
    // Verifica se a posição é chão ou raio de explosão
    if (m[x][y] != 0 && m[x][y] != 4) {
        return false;
    }

    // Verifica se a posição é uma bomba ativa
    if (bombaAtiva && x == bombaX && y == bombaY) {
        return false;
    }

    // Se passou por todas as verificações, o caminho é válido
    return true;
}


void moverInimigo(int m[TAM][TAM], int &inimigoX, int &inimigoY, int &inimigoDirecao, int bombaX, int bombaY, bool bombaAtiva, DWORD &tempoMoverInimigo) {

    if(inimigoX ==-1 && inimigoY == -1){
        return;
    }

    //intervalo de tempo movimentação
    if (GetTickCount() - tempoMoverInimigo > 1000) {

        //70% de ele decidir mudar de direção do nada
        if (rand() % 100 < 70) {
            inimigoDirecao = rand() % 4;
        }

        int novoXinimigo = inimigoX;
        int novoYinimigo = inimigoY;

        // Tenta mover na direção atual (seja a antiga ou a nova sorteada acima)
        switch (inimigoDirecao) {
            case 0: novoXinimigo--; break;
            case 1: novoXinimigo++; break;
            case 2: novoYinimigo--; break;
            case 3: novoYinimigo++; break;
                default: break;
        }

        // Se o caminho estiver livre, ele move
        if (verificaCaminho(m, novoXinimigo, novoYinimigo, bombaX, bombaY, bombaAtiva)) {
            inimigoX = novoXinimigo;
            inimigoY = novoYinimigo;
        } else {
            // Se bater na parede, ele muda de direção
            inimigoDirecao = rand() % 4;
        }

        tempoMoverInimigo = GetTickCount();
    }
}

void renderizarJogo(int m[TAM][TAM], int personagemX, int personagemY, int inimigoX, int inimigoY, int inimigo2X, int inimigo2Y, int inimigo3X, int inimigo3Y, int bombaX, int bombaY, bool bombaAtiva, COORD coord) {
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {

            //renderiza o personagem
            if (i == personagemX && j == personagemY) {
                cout << ("🤠");
            }
            //desenha inimigos vivos
            else if ((i == inimigoX && j == inimigoY && inimigoX != -1) ||
                     (i == inimigo2X && j == inimigo2Y && inimigo2X != -1) ||
                     (i == inimigo3X && j == inimigo3Y && inimigo3X != -1)) {
                cout << ("👻");
                     }
            //desenha a Bomba
            else if (bombaAtiva && i == bombaX && j == bombaY) {
                cout << ("💣");
            }
            // mapa
            else {
                switch (m[i][j]) {
                    case 0: cout << "  "; break; // vazio
                    case 1: cout << ("🧱"); break; //🧱 indestrutível
                    case 2: cout << ("📦"); break; //📦 destrutível
                    case 4: cout << ("🔥"); break;  //🔥 explosão
                        default: break;
                }
            }
        }
        cout << "\n";
    }
}

void processarEntrada(int m[TAM][TAM], int &personagemX, int &personagemY, int &bombaX, int &bombaY, bool &bombaAtiva, DWORD &tempobomba) {
    if (_kbhit()) {
        char tecla = getch();
        switch (tecla) {
            case 72: case 'w': // cima
                if (verificaCaminho(m, personagemX - 1, personagemY, bombaX, bombaY, bombaAtiva)) {
                    personagemX--;
                }
                break;
            case 80: case 's': // baixo
                if (verificaCaminho(m, personagemX + 1, personagemY, bombaX, bombaY, bombaAtiva)) {
                    personagemX++;
                }
                break;
            case 75: case 'a': // esquerda
                if (verificaCaminho(m, personagemX, personagemY - 1, bombaX, bombaY, bombaAtiva)) {
                    personagemY--;
                }
                break;
            case 77: case 'd': // direita
                if (verificaCaminho(m, personagemX, personagemY + 1, bombaX, bombaY, bombaAtiva)) {
                    personagemY++;
                }
                break;
            case ' ': //colocar bomba
                colocarBomba(personagemX, personagemY, bombaX, bombaY, tempobomba, bombaAtiva);
                break;
            default: break;
        }
    }
}

void verificarEstadoJogo(bool &jogoAtivo, int personagemX, int personagemY, int inimigoX, int inimigoY, int inimigo2X, int inimigo2Y, int inimigo3X, int inimigo3Y) {

    //verifica se personagem ta morto
    if (personagemX == -1 && personagemY == -1 || !jogoAtivo) {
        exibirTelaDerrota();
        jogoAtivo = false;
    }
    //verifica se todos os inimigos morreram
    else if (verificarVitoria(inimigoX, inimigoY, inimigo2X, inimigo2Y, inimigo3X, inimigo3Y)) {
        exibirTelaVitoria();
        jogoAtivo = false;
    }
}


int main() {
    //INÍCIO CONFIGURAÇÕES DE CONSOLE (NÃO MEXER)
    SetConsoleOutputCP(CP_UTF8);

    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO     cursorInfo;
    GetConsoleCursorInfo(out, &cursorInfo);
    cursorInfo.bVisible = false; // set the cursor visibility
    SetConsoleCursorInfo(out, &cursorInfo);
    short int CX=0, CY=0;
    COORD coord;
    coord.X = CX;
    coord.Y = CY;
    //FIM: CONFIGURAÇÕES DE CONSOLE

    //mapa
    int m[TAM][TAM]={1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
                    1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
                    1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,
                    1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
                    1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,2,1,0,1,0,1,
                    1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
                    1,0,1,0,1,0,1,0,1,0,1,2,1,2,1,2,1,0,1,0,1,
                    1,0,0,2,2,2,2,2,0,0,2,0,2,0,0,0,0,0,0,0,1,
                    1,0,1,2,1,0,1,0,1,2,1,2,1,2,1,2,1,0,1,0,1,
                    1,0,0,0,2,0,0,0,0,0,0,2,0,2,2,0,0,0,0,0,1,
                    1,0,1,0,1,0,1,2,1,2,1,2,1,2,1,0,1,0,1,0,1,
                    1,0,2,2,2,2,0,0,0,2,2,2,2,2,0,0,0,0,0,0,1,
                    1,0,1,2,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,
                    1,0,0,2,0,0,0,0,2,0,2,0,2,0,0,0,0,0,0,0,1,
                    1,0,1,0,1,2,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,
                    1,0,0,0,0,2,2,2,0,0,0,0,2,0,0,0,0,0,0,0,1,
                    1,0,1,0,1,0,1,0,1,0,1,2,1,2,1,0,1,0,1,0,1,
                    1,0,0,0,2,0,0,2,0,0,0,2,0,2,0,0,0,0,0,0,1,
                    1,0,1,0,1,0,1,2,1,0,1,0,1,2,1,0,1,0,1,0,1,
                    1,0,0,0,0,0,2,2,2,2,0,2,0,0,2,0,0,0,0,0,1,
                    1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};

    srand(time(NULL)); //inicializa a semente do gerador de numeros aleatorios
    bool jogoAtivo = true;

    //variaveis bomba
    bool explodindo = false;
    DWORD tempoExplosao=0;
    int fogoX, fogoY;
    int bombaX, bombaY;
    DWORD tempobomba; // 3 segundos
    bool bombaAtiva = false;

    //Posicao inicial do personagem
    int personagemX=1, personagemY=1;

    //posicao inicial inimigos
    int inimigoX = 19, inimigoY = 19, inimigoDirecao=0;
    DWORD tempoMoverInimigo1 = GetTickCount();

    int inimigo2X = 19, inimigo2Y = 1, inimigo2Direcao=0;
    DWORD tempoMoverInimigo2 = GetTickCount();

    int inimigo3X = 10, inimigo3Y = 19, inimigo3Direcao=0;
    DWORD tempoMoverInimigo3 = GetTickCount();
    // fim inimigos

    while(jogoAtivo){
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);

        renderizarJogo(m, personagemX, personagemY, inimigoX, inimigoY, inimigo2X, inimigo2Y, inimigo3X, inimigo3Y, bombaX, bombaY, bombaAtiva, coord);

        processarEntrada(m, personagemX, personagemY, bombaX, bombaY, bombaAtiva, tempobomba);
        gerenciarBomba(m, bombaX, bombaY, bombaAtiva, tempobomba, explodindo, tempoExplosao, fogoX, fogoY, personagemX, personagemY, inimigoX, inimigoY, inimigo2X, inimigo2Y, inimigo3X, inimigo3Y , jogoAtivo);

        moverInimigo(m, inimigoX, inimigoY, inimigoDirecao, bombaX, bombaY, bombaAtiva, tempoMoverInimigo1); //movimentacao inimigo (1)
        moverInimigo(m, inimigo2X, inimigo2Y, inimigo2Direcao, bombaX, bombaY, bombaAtiva, tempoMoverInimigo2); //movimentacao inimigo (2)
        moverInimigo(m, inimigo3X, inimigo3Y, inimigo3Direcao, bombaX, bombaY, bombaAtiva, tempoMoverInimigo3); //movimentacao inimigo (3)

        verificarContato(personagemX, personagemY, inimigoX, inimigoY, jogoAtivo);
        verificarContato(personagemX, personagemY, inimigo2X, inimigo2Y, jogoAtivo);
        verificarContato(personagemX, personagemY, inimigo3X, inimigo3Y, jogoAtivo);

        verificarEstadoJogo(jogoAtivo, personagemX, personagemY, inimigoX, inimigoY, inimigo2X, inimigo2Y, inimigo3X, inimigo3Y);
    }
    return 0;
}
