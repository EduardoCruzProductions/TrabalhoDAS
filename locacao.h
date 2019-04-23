
#ifndef LOCACAO_H
#define LOCACAO_H

#include "clientes.h"
#include "acervo.h"

typedef struct locacao
{
  int codigo;
  Cliente *cliente;
  std::list<Acervo*> itens;
  double valorLocacao;
} Locacao;

void printMenuLocacao(char *op);
int gerarCodigoLocacao(std::list<Locacao>& listLocacao);
void realizarLocacao(std::list<Locacao>& listLocacao, std::list<Acervo>& listAcervo, std::list<Cliente>& clientes);
void listarLocacoes(std::list<Locacao>& listLocacao);
void realizarDevolucao(std::list<Locacao>& listLocacao);
void listarClientesLocacao(std::list<Locacao>& listLocacao);
void mostrarFaturamento();

#endif
