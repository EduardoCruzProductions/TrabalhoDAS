
#ifndef CLIENTES_H
#define CLIENTES_H

#include <string>
#include <list>

using namespace std; // ranca isso aqui

typedef struct cliente
{
  int codigo;
  std::string nome;
  int idade;
} Cliente;

char printMenuCliente();
void adicionarCliente(list<Cliente>& listCliente);
void listarCliente(list<Cliente>& listCliente);
// void modificar(Cliente& cli);
// void excluir(Cliente& cli);
// void visualizar(Cliente& cli);

#endif
