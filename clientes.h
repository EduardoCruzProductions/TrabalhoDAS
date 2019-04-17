
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
int gerarCodigo(list<Cliente>& listCliente);
void adicionarCliente(list<Cliente>& listCliente);
void listarCliente(list<Cliente>& listCliente);
void alterarCliente(list<Cliente>& listCliente);
void excluirCliente(list<Cliente>& listCliente);
void visualizarCliente(list<Cliente>& listCliente);

#endif
