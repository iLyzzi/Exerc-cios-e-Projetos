//Cálculo de média, aprovação e melhor aluno da turma.

#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <limits> 

using namespace std;

int main() {
    const int maxAlunos = 5;
    const int numNotas = 3;

    int numAlunos = 0;

    do {
        cout << "Quantos alunos deseja inserir? (1 a " << maxAlunos << "): ";
        if (!(cin >> numAlunos)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Entrada inválida. Digite um número inteiro.\n";
            numAlunos = 0; 
            continue;
        }
        if (numAlunos < 1 || numAlunos > maxAlunos) {
            cout << "Número fora do intervalo. Tente novamente.\n";
        }
    } while (numAlunos < 1 || numAlunos > maxAlunos);

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<string> nomes(numAlunos);
    vector<vector<float>> notas(numAlunos, vector<float>(numNotas));
    vector<float> medias(numAlunos);

    float somaNotas;
    float maiorMedia = -1.0f;
    string nomeMaiorMedia;

    cout << "\n--- Coleta de dados dos alunos ---\n";
    for (int indiceAluno = 0; indiceAluno < numAlunos; ++indiceAluno) {
        cout << "\nDigite o nome do aluno " << indiceAluno + 1 << ": ";
        getline(cin, nomes[indiceAluno]);

        somaNotas = 0.0f;
        cout << "Digite as " << numNotas << " notas de " << nomes[indiceAluno] << " (0 a 10):\n";

        for (int indiceNota = 0; indiceNota < numNotas; ++indiceNota) {
            float nota;
            while (true) {
                cout << "Nota " << indiceNota + 1 << ": ";
                if (!(cin >> nota)) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Entrada inválida. Digite um número (0 a 10).\n";
                    continue;
                }
                if (nota < 0.0f || nota > 10.0f) {
                    cout << "Valor inválido! Digite uma nota entre 0 e 10.\n";
                    continue;
                }
                break;
            }

            notas[indiceAluno][indiceNota] = nota;
            somaNotas += nota;
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        medias[indiceAluno] = somaNotas / numNotas;
    }

    cout << "\nALUNO" << setw(8) << "N1" << setw(6) << "N2" << setw(6) << "N3"
         << setw(8) << "MÉDIA" << setw(12) << "SITUAÇÃO\n";
    cout << "---------------------------------------------\n";

    cout << fixed << setprecision(1);
    for (int indiceAluno = 0; indiceAluno < numAlunos; ++indiceAluno) {
        cout << left << setw(10) << nomes[indiceAluno];
        for (int indiceNota = 0; indiceNota < numNotas; ++indiceNota) {
            cout << setw(6) << notas[indiceAluno][indiceNota];
        }
        cout << setw(8) << medias[indiceAluno];
        cout << setw(12) << (medias[indiceAluno] >= 7.0f ? "Aprovado" : "Reprovado") << "\n";

        if (medias[indiceAluno] > maiorMedia) {
            maiorMedia = medias[indiceAluno];
            nomeMaiorMedia = nomes[indiceAluno];
        }
    }

    cout << "\nAluno com maior média: " << nomeMaiorMedia
         << " (" << setprecision(1) << maiorMedia << ")\n";

    return 0;
}