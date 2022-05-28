#include <iostream>
#include "Conta.h"
#include "Banco.h"
#include <cstdio>

int main(){

    Banco banco;
    int op;

	do{
		std::cout << std::endl;
		std::cout << "Selecione uma operação:" << std::endl;
		std::cout << "1. Criar Conta" << std::endl;
		std::cout << "6. Sair" << std::endl;
		std::cout << std::endl;
		std::cin >> op;
		system("clear||cls");

		switch(op){
			case 1:
				banco.cadastrarConta(); break;
			case 6:
				break;
			default:
				std::cout << "Opção inválida, digite novamente." << std::endl;
		}

	} while (op != 6);

    return 0;
}