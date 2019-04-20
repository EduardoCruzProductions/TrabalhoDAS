
#ifndef LOCACAO_H
#define LOCACAO_H

#include "clientes.h"
#include "acervo.h"

typedef struct locacao
{
  int codigo;
  Cliente *cliente;
  Acervo *item;
  double valorLocacao;
} Locacao;

void printMenuLocacao(char *op);

#endif
