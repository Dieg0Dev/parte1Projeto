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

void Banco::adicionandoConta(Conta *novaConta){
	if(vazia()){
		setCabeca(novaConta);
		setCauda(novaConta);
		return;
	}
	Conta *contaAuxiliar = getCauda();
	novaConta->setAnterior(getCauda());
	contaAuxiliar->setProximo(novaConta);
	setCauda(novaConta);
}

bool Banco::verificarExistencia(std::string numero){
	if(vazia()){
		return false;
	} else {
		Conta *contaAuxiliar = getCabeca();
		while(contaAuxiliar){
			if(numero == contaAuxiliar->getNumero()){
				return true;
			}
			if(contaAuxiliar->getProximo() == nullptr) break;
			contaAuxiliar = contaAuxiliar->getProximo();
		}
		return false;
	}
}

Conta* Banco::dadosConta(std::string numero){
	Conta *contaAuxiliar = getCabeca();
	while(contaAuxiliar){
		if(numero == contaAuxiliar->getNumero()){
			return contaAuxiliar;
		}
		if(contaAuxiliar->getProximo() == nullptr) break;
		contaAuxiliar = contaAuxiliar->getProximo();
	}
	return contaAuxiliar;
}

Conta* Banco::cadastrarConta(int opcao, std::string numero){
	Conta *novaConta;
	if(opcao == 1){
		novaConta = new Conta(numero, 0);
	} else if (opcao == 2){
		novaConta = new Conta(numero, 0, true, 10);
	} else {
		novaConta = new Conta(numero, 0, true);
	}
	return novaConta;
}
