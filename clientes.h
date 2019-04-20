
#ifndef CLIENTES_H
#define CLIENTES_H

#include <string>
#include <list>

typedef struct cliente
{
  int codigo;
  std::string nome;
  int idade;
} Cliente;

void printMenuCliente(char *op);
int gerarCodigo(std::list<Cliente>& listCliente);
void adicionarCliente(std::list<Cliente>& listCliente);
void listarCliente(std::list<Cliente>& listCliente);
void alterarCliente(std::list<Cliente>& listCliente);
void excluirCliente(std::list<Cliente>& listCliente);
void visualizarCliente(std::list<Cliente>& listCliente);
Cliente* buscarCliente(std::list<Cliente>& listCliente, int& codigo);

#endif
