#ifndef BANCO_H
#define BANCO_H

#include "Conta.h"
#include <iostream>
#include <string>
#include <cstdio>

class Banco{
private:
	Conta *cabeca = nullptr;
	Conta *cauda = nullptr;

public:
	bool vazia();
	void cadastrarConta();
	void consultarSaldo();
	void funcaoCredito();
	void funcaoDebito();
	void transferencia();
};

#endif