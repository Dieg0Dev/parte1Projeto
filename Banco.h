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
	bool verificarExistencia(std::string numero);
	void adicionandoConta(Conta *novaConta);
	Conta* dadosConta(std::string numero);
	bool vazia();

	Conta* cadastrarConta(int opcao, std::string numero);
	void funcaoCredito();
	void funcaoDebito();
	void transferencia();
	void renderJuros();
};

#endif