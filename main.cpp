#include <iostream>
#include "Conta.h"
#include "Banco.h"
#include <cstdio>

int main(){

    Banco banco;
    int op;

	do{
		std::cout << std::endl;
		std::cout << "Selecione uma operacao:" << std::endl;
		std::cout << "1. Criar Conta" << std::endl;
        std::cout << "2. Consultar Saldo" << std::endl;
        std::cout << "3. Funcao Credito" << std::endl;
		std::cout << "4. Funcao Debito" << std::endl;
        std::cout << "5. Transferencia" << std::endl;
		std::cout << "6. Criar Conta com Bonus" << std::endl;
		std::cout << "7. Criar Conta Poupanca" << std::endl;
		std::cout << "8. Render Juros" << std::endl;
		std::cout << "9. Sair" << std::endl;
		std::cout << std::endl;
		std::cin >> op;
		system("clear||cls");

		switch(op){
			case 1:
				banco.cadastrarConta(1); break;
            case 2:
                banco.consultarSaldo(); break;
            case 3:
                banco.funcaoCredito(); break;
            case 4:
                banco.funcaoDebito(); break;
            case 5:
				banco.transferencia(); break;
			case 6:
				banco.cadastrarConta(2); break;
			case 7:
				banco.cadastrarConta(3); break;
			case 8:
				banco.renderJuros(); break;
			case 9:
				break;
			default:
				std::cout << "Opção invalida, digite novamente." << std::endl;
		}

	} while (op != 9);

    return 0;
}