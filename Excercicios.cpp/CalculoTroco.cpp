//Calculo de troco


#include <iostream>
using namespace std;

int main(){
	setlocale(LC_ALL,"portuguese");

	float valorPago, valorProduto, troco;

	cout << "Digite o valor do produto: ";
	cin >> valorProduto;

	cout << "Digite o valor que irá pagar: ";
	cin >> valorPago;

	troco = valorPago - valorProduto;

	cout << "O troco é: " << troco;

	return 0;

}