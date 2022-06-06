#include "Conta.h"
#include "Banco.h"
#include <iostream>
#include <string>
#include <cstdio>

bool Banco::vazia(){
	return (cabeca == nullptr);
}

void Banco::cadastrarConta(){
	std::string numero;
	std::cout << "Digite o numero da conta: ";
	std::cin >> numero;

	if(vazia()){
		Conta *novaConta = new Conta(numero);
		cabeca = novaConta;
		cauda = novaConta;
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
			contaAuxiliar->aumentarSaldo(valor);
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
			if(valor > contaAuxiliar->getSaldo()){
				std::cout << "Saldo insuficiente" << std::endl;
				return;
			}
			contaAuxiliar->diminuirSaldo(valor);
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
	if(transferencia > contaAuxiliar1->getSaldo()){
		std::cout << "Conta origem sem saldo para operacao" << std::endl;
		return;
	}
	contaAuxiliar1->diminuirSaldo(transferencia);
	contaAuxiliar2->aumentarSaldo(transferencia);
}