//Disvio dimencional execercicio 1.


#include <iostream>
using namespace std;
int main()
{
    int numero, inversaoNumero;

    cout<<"insira um número interio: ";
    cin>>numero;

    if (numero <= -1){
        inversaoNumero = numero * (-1);
        
        cout<<endl<<"este é o equivalente positivo do número digitado: "<<inversaoNumero;
        
    }else{
        cout<<endl<<"este é o número digitado: "<<numero;
    }
    
    return 0;
}