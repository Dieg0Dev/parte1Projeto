#include "Conta.h"
#include "Banco.h"
#include <iostream>
#include <string>
#include <cstdio>

void Banco::setCabeca(Conta *cabeca){
	this->cabeca = cabeca;
}

Conta *Banco::getCabeca(){
	return this->cabeca;
}

void Banco::setCauda(Conta *cauda){
	this->cauda = cauda;
}

Conta *Banco::getCauda(){
	return this->cauda;
}

bool Banco::vazia(){
	return (cabeca == nullptr);
}

void Banco::cadastrarConta(int opcao){
	std::string numero;
	std::cout << "Digite o numero da conta: ";
	std::cin >> numero;
	

	if(vazia()){
		Conta *novaConta = new Conta(numero);
		setCabeca(novaConta);
		setCauda(novaConta);

		if(novaConta->getBonificacao()){
			std::cout << "Conta cadastrada com sucesso!" << std::endl;
		}
		std::cout << "Digite o saldo inicial da conta: ";
		float saldo;
		std::cin >> saldo;
		novaConta->setSaldo(saldo);
		std::cout << "Conta cadastrada com sucesso!" << std::endl;
	} else {
		Conta *contaAuxiliar = getCabeca();
		while(contaAuxiliar){
			if(numero == contaAuxiliar->getNumero()){
				std::cout << "Numero de conta indisponivel. Tente outro." << std::endl;
				return;
			}

			if(contaAuxiliar->getProximo() == nullptr) break;
			contaAuxiliar = contaAuxiliar->getProximo();
		}
		Conta *novaConta = new Conta(numero);
		
		contaAuxiliar = getCauda();
		novaConta->setAnterior(getCauda());
		contaAuxiliar->setProximo(novaConta);
		setCauda(novaConta);

		if(opcao == 2){
			novaConta->setPontuacao(10);
			novaConta->setBonificacao(true);
			std::cout << "Conta cadastrada com sucesso!" << std::endl;
			return;
		}

		if(opcao == 3){
			novaConta->setPoupanca(true);
			std::cout << "Digite o saldo inicial da conta: ";
			float saldo;
			std::cin >> saldo;
			novaConta->setSaldo(saldo);
			std::cout << "Conta cadastrada com sucesso!" << std::endl;
			return;
		}

		std::cout << "Digite o saldo inicial da conta: ";
		float saldo;
		std::cin >> saldo;
		novaConta->setSaldo(saldo);
		std::cout << "Conta cadastrada com sucesso!" << std::endl;
	}
}

void Banco::consultarSaldo(){
	std::string aux;
	std::cout << "Digite o numero da conta: " << std::endl;
	std::cin >> aux;
	Conta *contaAuxiliar = getCabeca();
	while(contaAuxiliar){
		if(aux == contaAuxiliar->getNumero()){
			std::cout << "Numero da conta: " << contaAuxiliar->getNumero() << std::endl;
			std::cout << "Saldo da conta: " << contaAuxiliar->getSaldo() << std::endl;
			return;
		}
		if(contaAuxiliar->getProximo() == nullptr) break;
		contaAuxiliar = contaAuxiliar->getProximo();
	}
	std::cout << "Conta nao encontrada" << std::endl;
	return;
}

void Banco::funcaoCredito(){
	std::string aux;
	float valor;
	std::cout << "Digite o numero da conta para adicionar o credito" << std::endl;
	std::cin >> aux;
	Conta* contaAuxiliar = getCabeca();
	while(contaAuxiliar){
		if(aux == contaAuxiliar->getNumero()){
			std::cout << "Digite o valor a ser creditado: ";
			std::cin >> valor;
			if(valor < 0){
				std::cout << "Valor invalido" << std::endl;
				return;
			}
			contaAuxiliar->aumentarSaldo(valor);
			if(contaAuxiliar->getBonificacao()){
				int aux = contaAuxiliar->getPontuacao();
				aux = aux + (valor / 100);
				contaAuxiliar->setPontuacao(aux);
			}
			std::cout << "Operacao realizada com sucesso!" << std::endl;
            return;
		}
		if(contaAuxiliar->getProximo() == nullptr) break;
		contaAuxiliar = contaAuxiliar->getProximo();
	}
	std::cout << "Conta nao encontrada" << std::endl;
	return;
}

void Banco::funcaoDebito(){
	std::string aux;
	float valor;
	std::cout << "Digite o numero da conta para debitar um valor" << std::endl;
	std::cin >> aux;
	Conta* contaAuxiliar = getCabeca();
	while(contaAuxiliar){
		if(aux == contaAuxiliar->getNumero()){
			std::cout << "Digite o valor a ser debitado: ";
			std::cin >> valor;
			if(valor < 0){
				std::cout << "Valor invalido" << std::endl;
				return;
			}
			if((!contaAuxiliar->getBonificacao() && !contaAuxiliar->getPoupanca()) || contaAuxiliar->getBonificacao()){
				float aux;
				aux = contaAuxiliar->getSaldo() - valor;
				if(aux < -1000){
					std::cout << "Operacao nao realizada. Limite de 1000 reais de saldo negativo." << std::endl;
					return;
				}
			}
			contaAuxiliar->diminuirSaldo(valor);
			std::cout << "Operacao realizada com sucesso!" << std::endl;
            return;
		}
		if(contaAuxiliar->getProximo() == nullptr) break;
		contaAuxiliar = contaAuxiliar->getProximo();
	}
	std::cout << "Conta nao encontrada" << std::endl;
	return;
}

void Banco::transferencia(){
	std::string aux, aux2;
	float transferencia;
	Conta *contaAuxiliar1 = getCabeca();
	Conta *contaAuxiliar2 = getCabeca();
	std::cout << "Digite o numero da conta origem" << std::endl;
	std::cin >> aux;

	while(contaAuxiliar1){
		if(aux == contaAuxiliar1->getNumero()) break;
		if(contaAuxiliar1->getProximo() == nullptr){
			std::cout << "Conta origem não encontrada" << std::endl;
			return;
		}
		contaAuxiliar1 = contaAuxiliar1->getProximo();
	}

	std::cout << "Digite o numero da conta destino" << std::endl;
	std::cin >> aux2;

	while(contaAuxiliar2){
		if(aux2 == contaAuxiliar2->getNumero()) break;
		if(contaAuxiliar2->getProximo() == nullptr){
			std::cout << "Conta destino não encontrada" << std::endl;
			return;
		}
		contaAuxiliar2 = contaAuxiliar2->getProximo();
	}

	std::cout << "Digite o valor da transferencia" << std::endl;
	std::cin >> transferencia;
	if(transferencia < 0){
		std::cout << "Valor invalido" << std::endl;
		return;
	}

	if((!contaAuxiliar1->getBonificacao() && !contaAuxiliar1->getPoupanca()) || contaAuxiliar1->getBonificacao()){
		float aux;
		aux = contaAuxiliar1->getSaldo() - transferencia;
		if(aux < -1000){
			std::cout << "Operacao nao realizada. Limite de 1000 reais de saldo negativo na conta origem." << std::endl;
			return;
		}
	}

	if(contaAuxiliar1->getPoupanca()){
		if(transferencia > contaAuxiliar1->getSaldo()){
			std::cout << "Conta origem sem saldo para operacao" << std::endl;
			return;
		}
	}

	contaAuxiliar1->diminuirSaldo(transferencia);
	contaAuxiliar2->aumentarSaldo(transferencia);
	if(contaAuxiliar2->getBonificacao()){
		int aux = contaAuxiliar2->getPontuacao();
		aux = aux + (transferencia / 150);
		contaAuxiliar2->setPontuacao(aux);
	}
	std::cout << "Operacao realizada com sucesso!" << std::endl;
}

void Banco::renderJuros(){
	std::string aux;
	float valor;
	std::cout << "Digite o numero da conta onde será calculado o rendimento de juros" << std::endl;
	std::cin >> aux;
	Conta* contaAuxiliar = getCabeca();
	while(contaAuxiliar){
		if(aux == contaAuxiliar->getNumero()){
			if(!contaAuxiliar->getPoupanca()){
				std::cout << "Conta nao esta na categoria Poupanca" << std::endl;
				return;
			}
			std::cout << "Digite a taxa de juros a ser calculada (apenas valores):";
			std::cin >> valor;
			if(valor < 0){
				std::cout << "Valor de juros invalido" << std::endl;
				return;
			}
			contaAuxiliar->setSaldo(contaAuxiliar->getSaldo() * (1+(valor/100)));
            return;
		}
		if(contaAuxiliar->getProximo() == nullptr) break;
		contaAuxiliar = contaAuxiliar->getProximo();
	}
	std::cout << "Conta nao encontrada" << std::endl;
	return;
}