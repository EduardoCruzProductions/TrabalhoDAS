
#ifndef CLIENTES_H
#define CLIENTES_H

typedef struct cliente
{
  int codigo;
  std::string nome;
  int idade;
} Cliente;

void adicionarCliente(Cliente& cli);
void modificar(Cliente& cli);
void excluir(Cliente& cli);
void visualizar(Cliente& cli);

#endif
