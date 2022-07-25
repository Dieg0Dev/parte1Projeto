	#include "Conta.h"
#include <iostream>
#include <string>
#include <cstdio>

Conta::Conta(std::string numero, float saldo){
	this->numero = numero;
	this->saldo = saldo;
	this->proximo = nullptr;
	this->anterior = nullptr;
}

Conta::Conta(std::string numero, float saldo, bool bonus, int pontuacao){
	this->numero = numero;
	this->saldo = saldo;
	this->bonus = bonus;
	this->pontuacao = pontuacao;
	this->proximo = nullptr;
	this->anterior = nullptr;
}

Conta::Conta(std::string numero, float saldo, bool poupanca){
	this->numero = numero;
	this->saldo = saldo;
	this->poupanca = poupanca;
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

void Conta::setPoupanca(bool poupanca){
	this->poupanca = poupanca;
}

bool Conta::getPoupanca(){
	return this->poupanca;
}

float Conta::aumentarSaldo(float valor){
	return this->saldo += valor;
}

float Conta::diminuirSaldo(float valor){
	return this->saldo -= valor;
}

/////////////////////////