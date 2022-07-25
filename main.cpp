

#include <iostream>
#include <string.h>
#include "Conta.h"
#include "Banco.h"
#include <cstdio>
//
int main(int argc, char* argv[]){


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
		std::cout << "6. Criar Conta Bonus" << std::endl;
		std::cout << "7. Criar Conta Poupanca" << std::endl;
		std::cout << "8. Render Juros" << std::endl;
		std::cout << "9. Sair" << std::endl;
		std::cout << std::endl;
		std::cin >> op;
		system("clear||cls");

		std::string numeroDaConta1;
		std::string numeroDaConta2;
		Conta *contaAuxiliar;
		float valor;

		switch(op){
			case 1:
				std::cout << "Digite o numero da conta: ";
				std::cin >> numeroDaConta1;
				if(banco.verificarExistencia(numeroDaConta1)){
					std::cout << "numero de conta ja utilizado" << std::endl;
					break;
				} else {
					contaAuxiliar = banco.cadastrarConta(1, numeroDaConta1);
					banco.adicionandoConta(contaAuxiliar);
					std::cout << "Conta " << numeroDaConta1 << " Cadastrada com sucesso!"<< std::endl;
				} break;

            case 2:
				std::cout << "Digite o numero da conta: ";
				std::cin >> numeroDaConta1;
				if(!banco.verificarExistencia(numeroDaConta1)){
					std::cout << "Conta nao encontrada" << std::endl;
					break;
				} else {
					contaAuxiliar = banco.dadosConta(numeroDaConta1);
					std::cout << "Saldo da conta "<< numeroDaConta1 << ": " << contaAuxiliar->getSaldo() << std::endl; 
					break;
				}

            case 3:
				std::cout << "Digite o numero da conta: ";
				std::cin >> numeroDaConta1;
				if(!banco.verificarExistencia(numeroDaConta1)){
					std::cout << "Conta nao encontrada" << std::endl;
					break;
				} else { 
					std::cout << "Digite o valor a ser creditado na conta: ";
					std::cin >> valor;
					if(valor <= 0){
						std::cout << "Valor invalido" << std::endl;
						break;
					}
					contaAuxiliar = banco.dadosConta(numeroDaConta1);
					contaAuxiliar->aumentarSaldo(valor);
					if(contaAuxiliar->getBonificacao()){
						int novaPontuacao = contaAuxiliar->getPontuacao();
						novaPontuacao = novaPontuacao + (valor / 100);
						contaAuxiliar->setPontuacao(novaPontuacao);
					}
					std::cout << "Operacao realizada com sucesso!" << std::endl;
					break;
				}
				

            case 4:
                std::cout << "Digite o numero da conta: ";
				std::cin >> numeroDaConta1;
				if(!banco.verificarExistencia(numeroDaConta1)){
					std::cout << "Conta nao encontrada" << std::endl;
					break;
				} else {
					std::cout << "Digite o valor a ser debitado da conta: ";
					std::cin >> valor;
					if(valor <= 0){
						std::cout << "Valor invalido" << std::endl;
						break;
					}
					contaAuxiliar = banco.dadosConta(numeroDaConta1);
					if((!contaAuxiliar->getBonificacao() && !contaAuxiliar->getPoupanca()) || contaAuxiliar->getBonificacao()){
						float aux;
						aux = contaAuxiliar->getSaldo() - valor;
						if(aux < -1000){
							std::cout << "Operacao nao realizada. Limite de 1000 reais de saldo negativo." << std::endl;
							break;
						}
					}
					contaAuxiliar->diminuirSaldo(valor);
					std::cout << "Operacao realizada com sucesso!" << std::endl;
					break;
				}

            case 5:
				std::cout << "Digite o numero da conta de origem: ";
				std::cin >> numeroDaConta1;
				if(!banco.verificarExistencia(numeroDaConta1)){
					std::cout << "Conta origem nao encontrada" << std::endl;
					break;
				}
				std::cout << "Digite o numero da conta de destino: ";
				std::cin >> numeroDaConta2;
				if(!banco.verificarExistencia(numeroDaConta2)){
					std::cout << "Conta destino nao encontrada" << std::endl;
					break;
				}
				std::cout << "Digite o valor da transferencia: ";
				std::cin >> valor;
				if(valor < 0){
					std::cout << "Valor invalido" << std::endl;
					break;
				}
				contaAuxiliar = banco.dadosConta(numeroDaConta1);

				if((!contaAuxiliar->getBonificacao() && !contaAuxiliar->getPoupanca()) || contaAuxiliar->getBonificacao()){
					float aux;
					aux = contaAuxiliar->getSaldo() - valor;
					if(aux < -1000){
						std::cout << "Operacao nao realizada. Limite de 1000 reais de saldo negativo." << std::endl;
						break;
					}
				}

				if(contaAuxiliar->getPoupanca()){
					if(valor > contaAuxiliar->getSaldo()){
						std::cout << "Conta origem sem saldo para operacao" << std::endl;
						break;
					}
				}

				contaAuxiliar->diminuirSaldo(valor);
				contaAuxiliar = banco.dadosConta(numeroDaConta2);
				contaAuxiliar->aumentarSaldo(valor);
				if(contaAuxiliar->getBonificacao()){
					int aux = contaAuxiliar->getPontuacao();
					aux = aux + (valor / 200);
					contaAuxiliar->setPontuacao(aux);
				}
				std::cout << "Operacao realizada com sucesso!" << std::endl;
				break;

			case 6:
				std::cout << "Digite o numero da conta: ";
				std::cin >> numeroDaConta1;
				if(banco.verificarExistencia(numeroDaConta1)){
					std::cout << "numero de conta ja utilizado" << std::endl;
					break;
				} else {
					contaAuxiliar = banco.cadastrarConta(2, numeroDaConta1);
					banco.adicionandoConta(contaAuxiliar);
					std::cout << "Conta " << numeroDaConta1 << " Cadastrada com sucesso!"<< std::endl;
				} break;

			case 7:
				std::cout << "Digite o numero da conta: ";
				std::cin >> numeroDaConta1;
				if(banco.verificarExistencia(numeroDaConta1)){
					std::cout << "numero de conta ja utilizado" << std::endl;
					break;
				} else {
					contaAuxiliar = banco.cadastrarConta(3, numeroDaConta1);
					banco.adicionandoConta(contaAuxiliar);
					std::cout << "Conta " << numeroDaConta1 << " Cadastrada com sucesso!"<< std::endl;
				} break;

			case 8:
				std::cout << "Digite o numero da conta: ";
				std::cin >> numeroDaConta1;
				if(!banco.verificarExistencia(numeroDaConta1)){
					std::cout << "Conta nao encontrada" << std::endl;
					break;
				} else {
					if(!contaAuxiliar->getPoupanca()){
						std::cout << "Conta nao esta na categoria Poupanca" << std::endl;
						break;
					}
					std::cout << "Digite a taxa de juros a ser calculada (apenas valores):";
					std::cin >> valor;
					if(valor <= 0){
						std::cout << "Valor de juros invalido" << std::endl;
						break;
					}
					contaAuxiliar->setSaldo(contaAuxiliar->getSaldo() * (1+(valor/100)));
            		break;
				}

			case 9:
				break;
			default:
				std::cout << "Opção invalida, digite novamente." << std::endl;
		}

	} while (op != 9);

    return 0;
}