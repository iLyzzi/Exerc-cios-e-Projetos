//Calculo de média por peso.

#include <iostream>
#include <locale.h>
using namespace std;

int main (){
    
    float prova1, prova2, prova3, valorMedia;
    
    cout << "Insira o valor da prova 1, prova 2 e prova 3:  ";
    cin >> prova1 >> prova2 >> prova3;
    
    valorMedia = (prova1*2+prova2*4+prova3*6)/12;
    
    cout << "O valor da sua média é: " << valorMedia;
    
    return 0;
}