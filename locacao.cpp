#include <iostream>
#include "locacao.h"

using namespace std;

void printMenuLocacao(char *op)
{
  while(*op != '0' &&
    *op != '1' &&
    *op != '2' &&
    *op != '3' &&
    *op != '4' &&
    *op != '5'){
    cout << "" << endl;
    cout << " -> Menu locação" << endl;
    cout << "0 - Voltar" << endl;
    cout << "1 - Realizar locação" << endl;
    cout << "2 - Realizar devolução" << endl;
    cout << "3 - Listar locações" << endl;
    cout << "4 - Listar midias disponíveis" << endl;
    cout << "5 - Mostrar faturamento" << endl;
    cin >> *op;
  }
}

int gerarCodigoLocacao(list<Locacao>& listLocacao)
{
  if(listLocacao.size() == 0) return 1;
  list<Locacao>::iterator it;
  int maior = 0;
  for(it = listLocacao.begin(); it != listLocacao.end(); it++){
    if(it->codigo > maior)maior = it->codigo;
  }
  return maior+1;
}

void realizarLocacao(list<Locacao>& listLocacao, list<Acervo>& listAcervo, list<Cliente>& clientes)
{

  int codigo, pass = 0;
  char op;

  Locacao locacao;

  cout << "Iniciando locação" << endl;

  do{

    cout << "Informe o código do cliente: ";
    cin >> codigo;

    locacao.cliente = buscarCliente(clientes, codigo);
    if(locacao.cliente == 0x00){
      do{
        cout << "Cliente não encontrado! Deseja listar os clientes registrados? (s/n) ";
        cin >> op;
      }while(op != 's' && op != 'n');
      if(op == 's'){
        listarCliente(clientes);
        cout << "" << endl;
      }
    }else{
      pass = 1;
    }

  }while(!pass);

  cout << "Cliente selecionado --> "
  << locacao.cliente->codigo << " - "
  << locacao.cliente->nome << " - "
  << locacao.cliente->idade
  << endl;
  cout << "" << endl;

  codigo = 0;
  pass = 0;

  do{

    cout << "Informe o código do item: ";
    cin >> codigo;

     locacao.item = buscarItemDisponivel(listAcervo, codigo);

    if(locacao.item == 0x00){
      do{
        cout << "Item do acervo não encontrado ou não disponível! Deseja os itens disponíveis registrados? (s/n) ";
        cin >> op;
      }while(op != 's' && op != 'n');
      if(op == 's'){
        listarAcervoDisponivel(listAcervo);
        cout << "" << endl;
      }
    }else{
      pass = 1;
    }

  }while(!pass);

  cout << "Item selecionado --> "
  << locacao.item->codigo << " - "
  << locacao.item->titulo << " - "
  << locacao.item->genero << " - "
  << locacao.item->valorLocacao << " - "
  << endl;
  cout << "" << endl;

  locacao.valorLocacao = locacao.item->valorLocacao;
  locacao.item->status = 1;

  locacao.codigo = gerarCodigoLocacao(listLocacao);
  listLocacao.push_back(locacao);

  cout << "Locação concluída!" << endl;

}

void listarLocacoes(list<Locacao>& listLocacao)
{
  list<Locacao>::iterator it;

  cout << "--------------- Locações realizadas ---------------" << endl;

  for(it = listLocacao.begin(); it != listLocacao.end(); it++)
    cout << it->codigo << " - "
    << it->cliente->nome << " - "
    << it->item->titulo
    << endl;
}
