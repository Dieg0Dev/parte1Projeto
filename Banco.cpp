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

	Conta *novaConta = new Conta(numero);

	if(vazia()){
		cabeca = novaConta;
		cauda = novaConta;
	} else {
		novaConta->setAnterior(cauda);
		cauda->setProximo(novaConta);
		cauda = novaConta;
	}
}

void Banco::consultarSaldo(){
	std::string aux;
	std::cout << "Digite o numero da conta: " << std::endl;
	std::cin >> aux;
	Conta* contaAuxiliar = cabeca;
	while(contaAuxiliar){
		if(aux == contaAuxiliar->getNumero()){
			std::cout << "Numero da conta: " << contaAuxiliar->getNumero() << std::endl;
			std::cout << "Saldo da conta: " << contaAuxiliar->getSaldo() << std::endl;
			return;
		}
		contaAuxiliar = contaAuxiliar->getProximo();
	}
	return;
}

void Banco::funcaoCredito(){
	std::string aux;
	float valor;
	std::cout << "Digite o numero da conta para adicionar o credito" << std::endl;
	std::cin >> aux;
	Conta* contaAuxiliar = cabeca;
	while(contaAuxiliar){
		if(aux == contaAuxiliar->getNumero()){
			std::cout << "Digite o valor a ser creditado: ";
			std::cin >> valor;
			contaAuxiliar->aumentarSaldo(valor);
            return;
		}
		contaAuxiliar = contaAuxiliar->getProximo();
	}
	return;
}

void Banco::funcaoDebito(){
	std::string aux;
	float valor;
	std::cout << "Digite o numero da conta para debitar um valor" << std::endl;
	std::cin >> aux;
	Conta* contaAuxiliar = cabeca;
	while(contaAuxiliar){
		if(aux == contaAuxiliar->getNumero()){
			std::cout << "Digite o valor a ser debitado: ";
			std::cin >> valor;
			contaAuxiliar->diminuirSaldo(valor);
            return;
		}
		contaAuxiliar = contaAuxiliar->getProximo();
	}
	return;
}

void Banco::transferencia(){
	std::string aux, aux2;
	float transferencia;
	Conta *contaAuxiliar = cabeca;
	Conta *contaAuxiliar2 = cabeca;
	std::cout << "Digite o numero da conta origem" << std::endl;
	std::cin >> aux;

	while(contaAuxiliar){
		if(aux == contaAuxiliar->getNumero()){
			break;
		}
		contaAuxiliar = contaAuxiliar->getProximo();
	}

	std::cout << "Digite o numero da conta destino" << std::endl;
	std::cin >> aux2;

	while(contaAuxiliar2){
		if(aux2 == contaAuxiliar2->getNumero()){
			break;
		}
	contaAuxiliar2 = contaAuxiliar2->getProximo();
	}

	std::cout << "Digite o valor da transferencia" << std::endl;
	std::cin >> transferencia;

		contaAuxiliar->diminuirSaldo(transferencia);
		contaAuxiliar2->aumentarSaldo(transferencia);
	return;
}