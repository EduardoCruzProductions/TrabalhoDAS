#include <iostream>
#include "locacao.h"

using namespace std;

void printMenuLocacao(char *op)
{
  while(*op != '0' &&
    *op != '1' &&
    *op != '2' &&
    *op != '3' &&
    *op != '4' &&
    *op != '5'){
    cout << "" << endl;
    cout << " -> Menu locação" << endl;
    cout << "0 - Voltar" << endl;
    cout << "1 - Realizar locação" << endl;
    cout << "2 - Realizar devolução" << endl;
    cout << "3 - Listar locações" << endl;
    cout << "4 - Listar midias disponíveis" << endl;
    cout << "5 - Mostrar faturamento" << endl;
    cin >> *op;
  }
}

void realizarLocacao(list<Locacao>& listLocacao){

}
