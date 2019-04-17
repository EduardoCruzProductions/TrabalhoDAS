#include <iostream>
#include "clientes.h"

using namespace std;
//o ideal seria tulizar uma lista de ponteiros

char printMenuCliente(){
  char op;
  while(op != '0' &&
    op != '1' &&
    op != '2' &&
    op != '3' &&
    op != '4' &&
    op != '5'){
    cout << "" << endl;
    cout << " -> Menu clientes" << endl;
    cout << "0 - Voltar" << endl;
    cout << "1 - Adicionar cliente" << endl;
    cout << "2 - Alterar cliente" << endl;
    cout << "3 - Remover cliente" << endl;
    cout << "4 - Visualizar clientes" << endl;
    cout << "5 - Listar clientes" << endl;
    cin >> op;
  }
  return op;
}

int gerarCodigo(list<Cliente>& listCliente)
{
  if(listCliente.size() == 0) return 1;
  list<Cliente>::iterator it;
  int maior = 0;
  for(it = listCliente.begin(); it != listCliente.end(); it++){
    if(it->codigo > maior)maior = it->codigo;
  }
  return maior+1;
}

void adicionarCliente(list<Cliente>& listCliente)
{

  Cliente cli;

  cout << "Cadastro de Cliente" << endl;

  cout << "Nome: ";
  cin >> cli.nome;

  cout << "Idade: ";
  cin >> cli.idade;

  cli.codigo = gerarCodigo(listCliente);

  listCliente.push_back(cli);

}

void listarCliente(list<Cliente>& listCliente)
{

  list<Cliente>::iterator it;

  cout << "--------------- Clientes cadastrados ---------------" << endl;

  for(it = listCliente.begin(); it != listCliente.end(); it++)
    cout << it->codigo << " - "
    << it->nome << " - "
    << it->idade
    << endl;

}

void visualizarCliente(list<Cliente>& listCliente)
{
  int codigo;
  list<Cliente>::iterator it;

  cout << "Informe o código do cliente: ";
  cin >> codigo;
  cout << endl;

  for(it = listCliente.begin(); it != listCliente.end(); it++){
    if(it->codigo == codigo){
      cout << it->codigo << " - "
           << it->nome << " - "
           << it->idade << endl;
      break;
    }
  }

}

//g++ -o ex clientes.cpp main.cpp
//buscar por makefile implicit roles
