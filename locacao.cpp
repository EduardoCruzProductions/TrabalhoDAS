#include <iostream>
#include "locacao.h"

using namespace std;

double faturamento = 0;

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

void mostrarFaturamento(){
  cout << "Faturamento atual: " << faturamento << "R$" << endl;
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
  char op, op2 = 'e';
  Acervo *item = 0x00;
  list<Acervo*>::iterator it;

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

  do{

    do{

      codigo = 0;
      pass = 0;

      cout << "Informe o código do item: ";
      cin >> codigo;

      item = buscarItemDisponivel(listAcervo, codigo);

      if(item == 0x00){
        do{
          cout << "Item do acervo não encontrado ou não disponível! Deseja os itens disponíveis registrados? (s/n) ";
          cin >> op;
        }while(op != 's' && op != 'n');
        if(op == 's'){
          listarAcervoDisponivel(listAcervo);
          cout << "" << endl;
        }
      }else{
        locacao.valorLocacao += item->valorLocacao;
        item->status = 1;
        locacao.itens.push_back(item);
        pass = 1;
      }

    }while(!pass);

    cout << "Deseja adicionar mais um item? (s/n) ";
    cin >> op2;

  }while(op2 == 's');

  cout << "Itens selecionados --> " << endl;

  for(it = locacao.itens.begin(); it != locacao.itens.end(); it++){
    cout << "   "
    << (*it)->codigo << " - "
    << (*it)->titulo << " - "
    << (*it)->genero << " - "
    << (*it)->valorLocacao
    << endl;
  }

  cout << "" << endl;

  locacao.codigo = gerarCodigoLocacao(listLocacao);
  listLocacao.push_back(locacao);

  cout << "Locação concluída! Total: " << locacao.valorLocacao << endl;

}

void listarLocacoes(list<Locacao>& listLocacao)
{
  list<Locacao>::iterator it;
  list<Acervo*>::iterator itItem;

  cout << "--------------- Locações realizadas ---------------" << endl;

  for(it = listLocacao.begin(); it != listLocacao.end(); it++){
    cout << it->codigo << " - "
    << it->cliente->nome << " - "
    << it->valorLocacao
    << endl;
    for(itItem = it->itens.begin(); itItem != it->itens.end(); itItem++){
      cout << "   "
      << (*itItem)->codigo << " - "
      << (*itItem)->titulo << " - "
      << (*itItem)->genero << " - "
      << (*itItem)->valorLocacao
      << endl;
    }
  }
}

void listarClientesLocacao(list<Locacao>& listLocacao)
{
  list<Locacao>::iterator it;
  cout << "--------------- Clientes que realizaram locações ---------------" << endl;
  for(it = listLocacao.begin(); it != listLocacao.end(); it++)
    cout << it->cliente->codigo << " - "
    << it->cliente->nome << " - "
    << it->cliente->idade
    << endl;
}

void realizarDevolucao(list<Locacao>& listLocacao)
{

  int runcount = 0, pass = 0, codigo = 0, codigoLocacao = 0;
  list<Locacao>::iterator it;
  list<Acervo*>::iterator itItem;
  char op = 'e';
  Locacao *locacao;

  //Exibindo usuários possiveis
  do{

    cout << "Informe o código do cliente: ";
    cin >> codigo;

    cout << "--------------- Locações realizadas pelo cliente ---------------" << endl;
    for(it = listLocacao.begin(); it != listLocacao.end(); it++){
      if(it->cliente->codigo == codigo){

          cout << it->codigo << " - "
          << it->cliente->nome << " - "
          << it->valorLocacao
          << endl;

          for(itItem = it->itens.begin(); itItem != it->itens.end(); itItem++){
            cout << "   "
            << (*itItem)->codigo << " - "
            << (*itItem)->titulo << " - "
            << (*itItem)->genero << " - "
            << (*itItem)->valorLocacao
            << endl;
          }
          runcount++;
      }
    }

    if(runcount == 0){
      cout << "Este cliente não possui locações ou este código não existe!" << endl;
      do{
        cout << "Deseja listar os clientes que realizaram locações? (s/n) ";
        cin >> op;
      }while(op != 's' && op != 'n');
      if(op == 's'){
        listarClientesLocacao(listLocacao);
        cout << "" << endl;
      }
    }else{
      pass = 1;
    }

  }while(!pass);

  //definindo a locacao usada para a devolucao
  if(runcount == 1){
    for(it = listLocacao.begin(); it != listLocacao.end(); it++){
      if(it->cliente->codigo == codigo){
        locacao = &(*it);
      }
    }
  }else{

    pass = 0;

    do{
      runcount = 0;
      op = 'e';
      cout << "Informe o código da locação: ";
      cin >> codigoLocacao;

      for(it = listLocacao.begin(); it != listLocacao.end(); it++){
        if(it->codigo == codigo){
            locacao = &(*it);
            runcount++;
        }
      }

      if(runcount != 1){
        do{
          cout << "Código não encontrado! Deseja listar as locações disponíveis? (s/n) ";
          cin >> op;
        }while(op != 's' && op != 'n');
        if(op == 's'){
          cout << "--------------- Locações realizadas pelo cliente ---------------" << endl;
          for(it = listLocacao.begin(); it != listLocacao.end(); it++){
            if(it->cliente->codigo == codigo){

                cout << it->codigo << " - "
                << it->cliente->nome << " - "
                << it->valorLocacao
                << endl;

                for(itItem = it->itens.begin(); itItem != it->itens.end(); itItem++){
                  cout << "   "
                  << (*itItem)->codigo << " - "
                  << (*itItem)->titulo << " - "
                  << (*itItem)->genero << " - "
                  << (*itItem)->valorLocacao
                  << endl;
                }
                runcount++;
            }
          }
          cout << "" << endl;
        }
      }else{
          pass = 1;
      }

    }while(!pass);

  }

  cout << "" << endl;

  //devolvendo itens
  cout << "Locação selecionada -->" << endl;

  cout << locacao->codigo << " - "
  << locacao->cliente->nome << " - "
  << locacao->valorLocacao
  << endl;

  for(itItem = locacao->itens.begin(); itItem != locacao->itens.begin(); itItem++){
    cout << "   "
    << (*itItem)->codigo << " - "
    << (*itItem)->titulo << " - "
    << (*itItem)->genero << " - "
    << (*itItem)->valorLocacao
    << endl;
  }

  codigo = 0;
  pass = 0;
  op = 'e';

  do{

    cout << "Informe o código do item para devolver: ";
    cin >> codigo;

    for(itItem = locacao->itens.begin(); itItem != locacao->itens.end(); itItem++){
      if((*itItem)->codigo == codigo){
        (*itItem)->status = 0;
        faturamento += (*itItem)->valorLocacao;
        locacao->itens.erase(itItem);
        break;
      }
    }

    cout << "Deseja devolver mais um item? (s/n) ";
    cin >> op;

    if(op != 's'){
      pass = 1;
    }

  }while(!pass);

  //Verificacao de finalizacao da devolucao

  if(locacao->itens.size() == 0){
    for(it = listLocacao.begin(); it != listLocacao.end(); it++){
      if(it->codigo == locacao->codigo){
        listLocacao.erase(it);
        break;
      }
    }
  }

  cout << "" << endl;
  cout << "Devolução concluída! ";

}
