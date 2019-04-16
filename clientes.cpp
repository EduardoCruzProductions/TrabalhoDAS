#include <iostream>
#include <string>
#include "clientes.h"

using namespace std;
//o ideal seria tulizar uma lista de ponteiros

void adicionarCliente(Cliente& cli)
{

  cout << "Cadastro de Cliente" << endl;

  cout << "Nome: ";
  cin >> cli.nome;

  cout << "Idade: ";
  cin >> cli.idade;

}

//g++ -o ex clientes.cpp main.cpp
