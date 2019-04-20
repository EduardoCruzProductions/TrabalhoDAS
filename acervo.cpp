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
  if(listAcervo.size() == 0) return 1;
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
    getline(cin,ac.genero);

    cout << "Valor de Locação: ";
    cin >> ac.valorLocacao;

    ac.status = 0;
    ac.codigo = gerarCodigo(listAcervo);
    listAcervo.push_back(ac);

    cout << "" << endl;
    cout << "Deseja continuar adicionando? (s/n) ";
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

void visualizarAcervo(list<Acervo>& listAcervo)
{
  int codigo;
  list<Acervo>::iterator it;

  cout << "Informe o código do item: ";
  cin >> codigo;
  cout << endl;

  for(it = listAcervo.begin(); it != listAcervo.end(); it++){
    if(it->codigo == codigo){
      cout << it->codigo << " - "
      << it->titulo << " - "
      << it->genero << " - "
      << it->valorLocacao << " - "
      << (it->status ? "Alugado" : "Disponível")
      << endl;
      break;
    }
  }

}

void excluirAcervo(list<Acervo>& listAcervo)
{
  int codigo;
  list<Acervo>::iterator it;

  cout << "Informe o código do item: ";
  cin >> codigo;
  cout << endl;

  for(it = listAcervo.begin(); it != listAcervo.end(); it++){
    if(it->codigo == codigo){
      listAcervo.erase(it);
      break;
    }
  }

  cout << "Item removido!" << endl;

}

void alterarAcervo(list<Acervo>& listAcervo)
{

  int codigo;
  char op;
  list<Acervo>::iterator it;

  cout << "Informe o código do item: ";
  cin >> codigo;
  cout << endl;

  for(it = listAcervo.begin(); it != listAcervo.end(); it++){

    if(it->codigo == codigo){

      cout << it->codigo << " - "
      << it->titulo << " - "
      << it->genero << " - "
      << it->valorLocacao << " - "
      << (it->status ? "Alugado" : "Disponível")
      << endl;

      while(op != '0'){
        cout << " -> Menu de alterações" << endl;
        cout << "Selecione uma das opções abaixo:" << endl;
        cout << "1 - Alterar título" << endl;
        cout << "2 - Alterar gênero" << endl;
        cout << "3 - Alterar valor de locação" << endl;
        cout << "0 - Finalizar alteração" << endl;
        cin >> op;

        if(op == '1'){

          cout << "Novo título: ";
          cin.ignore();
          getline(cin,it->titulo);

        }else if(op == '2'){

          cout << "Novo gênero: ";
          cin.ignore();
          getline(cin, it->genero);

        }else if(op == '3'){

          cout << "Novo valor de locação: ";
          cin.ignore();
          cin >> it->valorLocacao;

        }else if(op == '0'){
          cout << "Alteração concluída!" << endl;
          cout << it->codigo << " - "
          << it->titulo << " - "
          << it->genero << " - "
          << it->valorLocacao << " - "
          << (it->status ? "Alugado" : "Disponível")
          << endl;
        }

      }

    }

  }

}
