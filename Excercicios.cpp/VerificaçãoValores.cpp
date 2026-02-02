//Verificação de maiores de valores.

#include <iostream>
using namespace std;

#define TAM 5 

int main()
{
    int vet[TAM], maior=0, menor=0, igual=0, i=0;
    
    for(i=0; i<TAM; i++){
        cout<<"Insira um valor: ";
        cin>>vet[i];
        
    }
    
    for(i=0; i<TAM; i++){
        
        if(vet[0] == vet[i]){
            igual+=1;
            
        }else{
            if(vet[0]>vet[i]){
                menor+=1;
            }else{
                maior+=1;
            }
        }
    }
    
    cout<<"Este é o número de valores maiores: "<<maior;
    cout<<"Este é o número de valores menores: "<<menor;
    cout<<"Este é o número de valores iguais: "<<igual;
    return 0;
}