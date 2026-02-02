//Calculo de potencia.

#include <iostream>
using namespace std;

int main()
{
    int base, expoente, contador=1, multiplicacao=1;
    
    cout<<"digite o valor da base: ";
    cin>>base;
    
    cout<<"digite o valor do expoente: ";
    cin>>expoente;
    
    while(contador <= expoente){
    multiplicacao=multiplicacao*base;
    contador++;
    }
    
    cout<<"esse é o valor da potencia: "<<multiplicacao<<endl;

    return 0;
}