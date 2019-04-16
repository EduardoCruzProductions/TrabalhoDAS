#include <iostream>
#include <string>
#include <list>
#include "clientes.h"

using namespace std;

int main()
{
  list<Cliente> list;
  Cliente cli;
  adicionarCliente(cli);
  list.push_back(cli);
  return 0;
}
