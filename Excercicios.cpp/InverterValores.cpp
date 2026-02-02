//Inverter o valor das Variavies.

#include <iostream>
using namespace std;
int main()
{
    float valorA, valorB, temporaria;
    
    cout << "Insira o valor de A: ";
    cin >> valorA;
    
    cout << "Insira o valor de B: ";
    cin >> valorB;
    
    temporaria = valorA;
    valorA = valorB;
    valorB = temporaria;
    
    cout << "\n Este são os valores inseridos trocados: ";
    cout << "\n Valor B: " << valorB;
    cout << "\n valor A: " << valorA;
    return 0;
}