// Calculo de valor por kilo

#include <iostream>
using namespace std;

int main(){

	float valorQuilo, quantidadeQuilo, valorAserPago;

	cout << "Qual o valor por quilo do produto: ";
	cin >> valorQuilo;

	cout << "Quantos quilos foram consumidos: ";
	cin >> quantidadeQuilo;

	valorAserPago = quantidadeQuilo * valorQuilo;

	cout <<"Valor a ser pago R$"<< valorAserPago;

	return 0;

}