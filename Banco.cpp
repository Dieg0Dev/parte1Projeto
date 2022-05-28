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