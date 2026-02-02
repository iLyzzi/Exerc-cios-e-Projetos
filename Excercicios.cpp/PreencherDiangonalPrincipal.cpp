//Preenchar a diagonal principal 

#include <iostream>
using namespace std;

#define TAM 5

int main()
{
    int matriz[TAM][TAM], linha, coluna;

    for(linha=0; linha<TAM; linha++){
        for(coluna=0; coluna<TAM; coluna++){
            
            if(linha==coluna){
                matriz[linha][coluna] = 1;
                
            }else{
                matriz[linha][coluna] = 0;
            }
        }
    
    }
    for(linha=0; linha<TAM; linha++){
        for(coluna=0; coluna<TAM; coluna++){
            cout<<matriz[linha][coluna]<<"\t";
            
        }
        cout<<endl;
    }

    return 0;
}