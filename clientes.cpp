#include "clientes.h"
#include <iostream>
#include <string>
#include <list>

using namespace std;

struct cliente
{
  int codigo;
  string nome;
  int idade;
};

//o ideal seria tulizar uma lista de ponteiros

void adicionarCliente(list<cliente> list)
{
  // cliente cli;
  //
  // cout << "Cadastro de Cliente" << endl;
  //
  // cout << "Nome: ";
  // cin >> cli.nome;
  // cout << endl;
  //
  // cout << "Idade: ";
  // cin >> cli.idade;
  // cout << endl;
  //
  // cliente.push_back(c);
  cout << "Chego";

}
