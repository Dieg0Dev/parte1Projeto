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
	//gets e sets
	void setCabeca(Conta *cabeca); 
	Conta *getCabeca();
	void setCauda(Conta *cauda); 
	Conta *getCauda();

	//outros metodos
	bool vazia();
	void cadastrarConta(int opcao);
	void consultarSaldo();
	void funcaoCredito();
	void funcaoDebito();
	void transferencia();
};

#endif