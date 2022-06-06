#include "Conta.h"
#include <iostream>
#include <string>
#include <cstdio>

Conta::Conta(std::string numero){
	this->numero = numero;
	this->saldo = 0;
	this->proximo = nullptr;
	this->anterior = nullptr;
}

void Conta::setNumero(std::string numero){
	this->numero = numero;
}

std::string Conta::getNumero(){
	return this->numero;
}

void Conta::setSaldo(float saldo){
	this->saldo = saldo;
}

float Conta::getSaldo(){
	return this->saldo;
}

void Conta::setProximo(Conta *proximo){
	this->proximo = proximo;
}

Conta *Conta::getProximo(){
	return this->proximo;
}

void Conta::setAnterior(Conta *anterior){
	this->anterior = anterior;
}

Conta *Conta::getAnterior(){
	return this->anterior;
}

void Conta::setPontuacao(int pontuacao){
	this->pontuacao = pontuacao;
}

int Conta::getPontuacao(){
	return this->pontuacao;
}

void Conta::setBonificacao(bool bonus){
	this->bonus = bonus;
}

bool Conta::getBonificacao(){
	return this->bonus;
}

float Conta::aumentarSaldo(float valor){
	return this->saldo += valor;
}

float Conta::diminuirSaldo(float valor){
	return this->saldo -= valor;
}

/////////////////////////