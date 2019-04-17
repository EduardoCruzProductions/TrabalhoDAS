#include <iostream>
#include <string>
#include <list>
#include "clientes.h"
#include "acervo.h"

using namespace std;

list<Cliente> clientes;
list<Acervo> listAcervo;

void showMenu()
{
  int cont = 1;
  char op;

  while(cont){

    op = 'e';

    while(op != '1' &&
     op != '2' &&
     op != '3' &&
     op != '0'){
      cout << "" << endl;
      cout << "Selecione uma opção de menu: " << endl;
      cout << "0 - Sair" << endl;
      cout << "1 - Locação" << endl;
      cout << "2 - Clientes" << endl;
      cout << "3 - Acervo" << endl;
      cin >> op;
    }

    if(op == '1'){ // Opcao da Locacao

    }else if(op == '2'){ // Opcao dos clientes

      op = printMenuCliente();

      if(op == '1'){ // Adicionar cliente
        adicionarCliente(clientes);
      }else if (op == '2'){ // Alterar cliente
        alterarCliente(clientes);
      }else if (op == '3'){ // Remover cliente
        excluirCliente(clientes);
      }else if (op == '4'){ // Visualizar cliente
        visualizarCliente(clientes);
      }else if (op == '5'){ // Listar cliente
        listarCliente(clientes);
      }

    }else if(op == '3'){ // Opcao do acervo
      op = printMenuAcervo();

      if(op == '1'){ // Adicionar acervo
        adicionarAcervo(listAcervo);
      }else if (op == '2'){ // Alterar acervo

      }else if (op == '3'){ // Remover acervo

      }else if (op == '4'){ // Visualizar acervo

      }else if (op == '5'){ // Listar acervo
        listarAcervo(listAcervo);
      }

    }else if(op == '0'){ // encerrar programa
      cont = 0;
    }

  }

}

int main()
{
  showMenu();
  cout << "Programa finalizado." << endl;
  return 0;
}
