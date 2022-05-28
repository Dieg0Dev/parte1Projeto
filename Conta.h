#ifndef CONTA_H
#define CONTA_H

#include <iostream>
#include <string>
#include <cstdio>

class Conta{
private:
	std::string numero;
	float saldo;
	Conta *proximo;
	Conta *anterior;

public:
	//construtor
	Conta(std::string numero); 

	//gets e sets
	void setNumero(std::string numero); 
	std::string getNumero();
	void setSaldo(float saldo);
	float getSaldo();
	void setProximo(Conta *proximo);
	Conta *getProximo();
	void setAnterior(Conta *anterior);
	Conta *getAnterior();

	//outros métodos
	float aumentarSaldo(float valor);
	float diminuirSaldo(float valor);
};

#endif