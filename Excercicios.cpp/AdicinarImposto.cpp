//Adicinar 15% de imposto

#include <iostream>
using namespace std;

int main(){

	float valorProduto, imposto, precoFinal;

	cout << "insira o valor do produto: ";
	cin >> valorProduto;

	precoFinal = (valorProduto*0.15) + valorProduto;

	cout << "valor do produto com imposto é: " << precoFinal;

	return 0;

}