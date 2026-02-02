//Calculo de consumo de carro.

#include <iostream>
using namespace std;
int main()
{
    float valorCombustivel, kmPercorridos, consumoCarro, gastoDinheiro;
    
    cout << "Insira o valor do combustivel em R$ ";
    cin >> valorCombustivel;
    
    cout << "Insira a quantidade de kilometros a serem percorridos ";
    cin >> kmPercorridos;
    
    cout << "Insira o valor do cosumo do carro em Km/L ";
    cin >> consumoCarro;
    
    gastoDinheiro = (kmPercorridos/consumoCarro) * valorCombustivel;
    
    cout << "Valor a ser gasto em R$ é: " << gastoDinheiro;
    
    return 0;
}