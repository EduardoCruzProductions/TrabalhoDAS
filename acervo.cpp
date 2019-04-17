#include <iostream>
#include "acervo.h"

using namespace std;

char printMenuAcervo()
{
  char op;
  while(op != '0' &&
    op != '1' &&
    op != '2' &&
    op != '3' &&
    op != '4' &&
    op != '5'){
    cout << "" << endl;
    cout << " -> Menu acervo" << endl;
    cout << "0 - Voltar" << endl;
    cout << "1 - Adicionar acervo" << endl;
    cout << "2 - Alterar acervo" << endl;
    cout << "3 - Remover acervo" << endl;
    cout << "4 - Visualizar acervo" << endl;
    cout << "5 - Listar acervo" << endl;
    cin >> op;
  }
  return op;
}

int gerarCodigo(list<Acervo>& listAcervo)
{
  if(listAcervo.size() == 1) return 1;
  list<Acervo>::iterator it;
  int maior = 0;
  for(it = listAcervo.begin(); it != listAcervo.end(); it++){
    if(it->codigo > maior)maior = it->codigo;
  }
  return maior+1;
}

void adicionarAcervo(list<Acervo>& listAcervo)
{

  char op;

  cout << "Cadastro de Acervo" << endl;

  do{
    Acervo ac;

    cout << "Título: ";
    cin.ignore();
    getline(cin,ac.titulo);

    cout << "Gênero: ";
    cin.ignore();
    getline(cin,ac.genero); // aqui tem um bug q come a primeira letra

    cout << "Valor de Locação: ";
    cin >> ac.valorLocacao;

    ac.status = 0;
    ac.codigo = gerarCodigo(listAcervo);
    listAcervo.push_back(ac);

    cout << "" << endl;
    cout << "Deseja continuar adicionando? (s/n)";
    cin >> op;

  }while(op != 'n');

}

void listarAcervo(list<Acervo>& listAcervo)
{
  list<Acervo>::iterator it;

  cout << "--------------- Acervo cadastrado ---------------" << endl;

  for(it = listAcervo.begin(); it != listAcervo.end(); it++)
    cout << it->codigo << " - "
    << it->titulo << " - "
    << it->genero << " - "
    << it->valorLocacao << " - "
    << (it->status ? "Alugado" : "Disponível")
    << endl;

}
