//Calculo metade do valor.

#include <iostream>
using namespace std;

int main(){
	setlocale (LC_ALL, "Portuguese");
	
	float valorDigitado, metadeDoValorDigitado;

	cout << "Digite o valor a ser divido: ";
	cin >> valorDigitado ;

	metadeDoValorDigitado = valorDigitado/2.0;

	cout << "A metade do valor digitado é: " << metadeDoValorDigitado;

	return 0;

}