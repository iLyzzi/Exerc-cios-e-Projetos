//Leitor de código de barras EAN-13

#include <iostream>
using namespace std;

int main()
{
    int D12, D11, D10, D9, D8, D7, D6, D5, D4, D3, D2, D1, D0, op1, op2, resultado;
    
    //long long para podermos inserir códigos de até 8 bytes
    long long codigoBarra;
    
    cout<< "Digite o código de barras: ";
    cin>> codigoBarra;
    
    // validação entre 10 à 13 dígitos
    if (codigoBarra >= 1000000000 && codigoBarra <= 9999999999999){
      
      //Calculo dos número para inserir nas variáveis  
       D0  = codigoBarra % 10;
       codigoBarra /= 10;
       D1  = codigoBarra % 10;
       codigoBarra /= 10;
       D2  = codigoBarra % 10;
       codigoBarra /= 10;
       D3  = codigoBarra % 10;
       codigoBarra /= 10;
       D4  = codigoBarra % 10;
       codigoBarra /= 10;
       D5  = codigoBarra % 10;
       codigoBarra /= 10;
       D6  = codigoBarra % 10;
       codigoBarra /= 10;
       D7  = codigoBarra % 10;
       codigoBarra /= 10;
       D8  = codigoBarra % 10;
       codigoBarra /= 10;
       D9  = codigoBarra % 10;
       codigoBarra /= 10;
       D10 = codigoBarra % 10;
       codigoBarra /= 10;
       D11 = codigoBarra % 10;
       codigoBarra /= 10;
       D12 = codigoBarra % 10;
        
        
        // Operação 1 de soma de todas as variáveis, variáveis impares multiplicadas por 3
        op1 = D12 + D11*3 + D10 + D9*3 + D8 + D7*3 + D6 + D5*3 + D4 + D3*3 + D2 + D1*3;

        // Calculo final
        op2 = ((op1 / 10) + 1) * 10;
        resultado = op2 - op1;
        
        // Se o resultado der 10 ou múltiplo de 10, Resultado = 0
        if (resultado % 10 == 0){
            resultado = 0;
        }

        // Compara com o ultimo digito (D0)
        if (resultado == D0) {
            cout << "Código de barras valido\n";
        } else {
            cout << "Código de barras invalido\n";
        }

    //caso o número não seja entre 10 à 13 dígitos
    } else {
        cout << "Número de digitos invalido\n";
    }

    return 0;
}