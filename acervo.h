
#ifndef ACERVO_H
#define ACERVO_H

#include <string>
#include <list>

typedef struct acervo
{
  int codigo;
  std::string titulo;
  std::string genero;
  double valorLocacao;
  int status;
} Acervo;

char printMenuAcervo();
int gerarCodigo(std::list<Acervo>& listAcervo);
void adicionarAcervo(std::list<Acervo>& listAcervo);
void listarAcervo(std::list<Acervo>& listAcervo);

#endif
