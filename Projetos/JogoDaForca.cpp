//Jogo da Forca

#include <iostream>
#include <cstdlib>   // Biblioteca usada para gerar números aleatórios (rand, srand)
#include <ctime>     // Biblioteca usada para pegar o tempo atual (time)

using namespace std;

int main()
{
    srand(time(NULL)); 
    // Inicializa o gerador de números aleatórios com base no horário atual do sistema

    int palavra = rand() % 10; 
    // Sorteia um número de 0 a 9 que representa a palavra escolhida

    int ultimaPalavra = -1; 
    // Guarda o índice da última palavra para evitar repetições

    int opcao = 0; 
    int tentativas; 
    int erros; 
    int acertos;

    // Letras da palavra sorteada (c1 a c6)
    char c1, c2, c3, c4, c5, c6;

    // Letras digitadas pelo jogador (t1 a t6)
    char t1, t2, t3, t4, t5, t6;

    char letra; // Letra digitada pelo usuário

    do {
        // Exibe o menu principal
        cout << "\n- MENU - \n[1] JOGAR \n[2] SOBRE \n[3] FIM \n";
        cin >> opcao;

        switch(opcao) {

        // ==============================
        // OPÇÃO 1 - INICIAR O JOGO
        // ==============================
        case 1:

            // Sorteia uma nova palavra diferente da anterior
            do {
                palavra = rand() % 10;
            } while (palavra == ultimaPalavra);
            ultimaPalavra = palavra;

            // Reinicia os valores de cada rodada
            tentativas = 10;
            erros = 0;
            acertos = 0;

            // Inicializa os espaços vazios da palavra
            t1 = '_';
            t2 = '_';
            t3 = '_';
            t4 = '_';
            t5 = '_';
            t6 = '_';

            // Define as letras corretas de cada palavra
            switch (palavra) {
            case 0:
                c1 = 'V';
                c2 = 'A';
                c3 = 'R';
                c4 = 'E';
                c5 = 'L';
                c6 = 'A';
                break;
            case 1:
                c1 = 'B';
                c2 = 'A';
                c3 = 'R';
                c4 = 'A'; 
                c5 = 'T';
                c6 = 'A';
                break;
            case 2:
                c1 = 'B';
                c2 = 'A'; 
                c3 = 'T';
                c4 = 'A';
                c5 = 'T';
                c6 = 'A';
                break;
            case 3:
                c1 = 'L';
                c2 = 'I';
                c3 = 'V';
                c4 = 'R';
                c5 = 'O';
                c6 = 'S';
                break;
            case 4:
                c1 = 'F';
                c2 = 'L';
                c3 = 'O';
                c4 = 'R';
                c5 = 'E';
                c6 = 'S';
                break;
            case 5:
                c1 = 'J';
                c2 = 'A';
                c3 = 'N';
                c4 = 'E';
                c5 = 'L';
                c6 = 'A';
                break;
            case 6:
                c1 = 'I';
                c2 = 'T';
                c3 = 'A';
                c4 = 'J';
                c5 = 'A';
                c6 = 'I';
                break;
            case 7:
                c1 = 'J'; 
                c2 = 'A';
                c3 = 'R';
                c4 = 'D';
                c5 = 'I';
                c6 = 'M';
                break;
            case 8:
                c1 = 'A';
                c2 = 'M';
                c3 = 'I';
                c4 = 'G';
                c5 = 'O';
                c6 = 'S';
                break;
            case 9:
                c1 = 'E';
                c2 = 'S';
                c3 = 'T';
                c4 = 'A';
                c5 = 'D';
                c6 = 'O';
                break;
            }

            // Loop principal do jogo — repete até acabar tentativas ou acertar todas as letras
            do {
                // Mostra o progresso atual da palavra
                cout << "\n" << t1 << ' ' << t2 << ' ' << t3 << ' ' << t4 << ' ' << t5 << ' ' << t6 << endl;

                // Mostra quantas tentativas e acertos o jogador tem
                cout << "\nTentativas restantes: " << tentativas << endl;
                cout << "Acertos: " << acertos << endl;

                // Pede uma letra
                cout << "\nEntre com uma letra: ";
                cin >> letra;

                bool acertou = false; // Marca se a letra foi encontrada

                // Verifica cada posição da palavra
                if(letra == c1 && t1 == '_') { t1 = letra; acertos++; acertou = true; }
                if(letra == c2 && t2 == '_') { t2 = letra; acertos++; acertou = true; }
                if(letra == c3 && t3 == '_') { t3 = letra; acertos++; acertou = true; }
                if(letra == c4 && t4 == '_') { t4 = letra; acertos++; acertou = true; }
                if(letra == c5 && t5 == '_') { t5 = letra; acertos++; acertou = true; }
                if(letra == c6 && t6 == '_') { t6 = letra; acertos++; acertou = true; }

                // Se não acertou, perde uma tentativa
                if(!acertou) {
                    erros++;
                    tentativas = tentativas - 1;
                    cout << "\nLetra incorreta! Você errou " << erros << " vez(es).\n";
                } else {
                    cout << "\nBoa! Você acertou uma letra!\n";
                }

                // Desenha o boneco da forca conforme o número de erros
                cout << "\n";
                cout << "------\n";
                cout << "|    |\n";
                if (erros >= 1) cout << "|    O\n"; else cout << "|\n";
                if (erros == 2) cout << "|    |\n";
                if (erros == 3) cout << "|   /|\n";
                if (erros >= 4) cout << "|   /|\\\n";
                if (erros == 5) cout << "|    |\n";
                if (erros == 6) cout << "|   / \n";
                if (erros >= 7) cout << "|   / \\\n";
                if (erros == 8) cout << "|  GAME OVER (quase)\n";
                if (erros == 9) cout << "|  Última chance!\n";
                if (erros >= 10) cout << "|  Fim de jogo!\n";
                cout << "|\n";
                cout << "---------\n";

            } while(tentativas != 0 && acertos != 6);

            // Resultado final da partida
            if(acertos == 6) {
                cout << "\nVitoria!" << endl;
            } else {
                cout << "\nDerrota :(" << endl;
            }

            // Mostra um resumo da rodada
            cout << "\n- RESUMO -" << endl;
            cout << "Numero de acertos: " << acertos << endl;
            cout << "Numero de erros totais: " << erros << endl;
            cout << "Tentativas restantes: " << tentativas << endl;

            break;

        // ==============================
        // OPÇÃO 2 - SOBRE
        // ==============================
        case 2:

            // Mostra informações sobre o jogo e os participantes
            cout << " --------------------------------------" << endl;
            cout << "|| Autor:                             ||" << endl;
            cout << "||  Lucas Souto                       ||" << endl;
            cout << " --------------------------------------" << endl;
            cout << " --------------------------------------" << endl;
            cout << "|| REGRAS:                            ||" << endl;
            cout << "|| - Use apenas letras maiusculas     ||" << endl;
            cout << "|| - Cada palavra contem 6 letras     ||" << endl;
            cout << "|| - Voce tem 10 tentativas           ||" << endl;
            cout << "|| - Tentativas so caem se errar      ||" << endl;
            cout << " --------------------------------------" << endl;
            break;

        // ==============================
        // OPÇÃO 3 - SAIR
        // ==============================
        case 3:
            return 0; // Sai do programa
            break;
        }

    } while(opcao != 3); // Repete o menu até o usuário escolher sair

    return 0;
}
