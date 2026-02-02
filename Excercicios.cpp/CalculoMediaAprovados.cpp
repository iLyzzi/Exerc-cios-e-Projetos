//Calculo de média e número de aprovados

#include <iostream>
using namespace std;

#define TAM 10

int main()
{
    
    float notas[TAM], soma=0, media;
    int passaram=0, i;
    
    for (i=0; i<TAM; i++){
        cout<<"digite as notas dos alunos: ";
        cin>>notas[i];
        
        soma=soma+notas[i];
    }
    
    media = (float) soma/TAM;
    
    for(i=0; i<TAM; i++){
        
        if(notas[i]>media){
            passaram+=1;
        }
    }
    
    cout<<"\nEsta é a media da sala: "<<media;
    cout<<"\nEste é  número de alunos que passara: "<<passaram;
    
    return 0;
}