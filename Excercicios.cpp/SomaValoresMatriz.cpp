//Soma dos números da Matriz.

#include <iostream>
using namespace std;

#define TAM 5

int main()
{
    int mat[TAM][TAM], i=0, j=0;
    
    for(i=0; i<TAM; i++){
        for(j=0; j<TAM; j++){
            cout<<"\ninsira um valor na matriz: ";
            cin>>mat[i][j];
            
        }
    }
    
    int soma=0;
    
    for(i=0; i<TAM; i++){
        for(j=0; j<TAM; j++){
            soma+=mat[i][j];
            
        }
    }
    
    cout<<"\neste é a soma dos valores da matriz: "<<soma;
    
    return 0;
}
