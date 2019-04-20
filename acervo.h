
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

void printMenuAcervo(char *op);
int gerarCodigo(std::list<Acervo>& listAcervo);
void adicionarAcervo(std::list<Acervo>& listAcervo);
void listarAcervo(std::list<Acervo>& listAcervo);
void visualizarAcervo(std::list<Acervo>& listAcervo);
void excluirAcervo(std::list<Acervo>& listAcervo);
void alterarAcervo(std::list<Acervo>& listAcervo);
Acervo* buscarItemDisponivel(std::list<Acervo>& listAcervo, int& codigo);
void listarAcervoDisponivel(std::list<Acervo>& listAcervo);

#endif
