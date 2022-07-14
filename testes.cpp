#define CATCH_CONFIG_MAIN

#include <string>
#include <cstdio>
#include "catch.hpp"
#include "Banco.h"
#include "Conta.h"


TEST_CASE("Testando Conta"){
    SECTION("Testando Construtor e GETs"){
        Conta *conta = new Conta("1000", 10);
        Conta *contaBonus = new Conta("2000", 20, true, 10);
        Conta *contaPoupanca = new Conta("3000", 30, true);

        REQUIRE(conta->getNumero() == "1000");

        REQUIRE(conta->getSaldo() == 10);

        REQUIRE(conta->getBonificacao() == false);
        REQUIRE(conta->getPoupanca() == false);

        REQUIRE(contaBonus->getBonificacao() == true);
        REQUIRE(contaBonus->getPoupanca() == false);

        REQUIRE(contaPoupanca->getBonificacao() == false);
        REQUIRE(contaPoupanca->getPoupanca() == true);

        REQUIRE(conta->getPontuacao() == 0);
        REQUIRE(contaBonus->getPontuacao() == 10);
        REQUIRE(contaPoupanca->getPontuacao() == 0);

        delete conta;
        delete contaBonus;
        delete contaPoupanca;
    }

    SECTION("Testando aumentarSaldo() e DiminuirDiminuir()"){
        Conta *conta = new Conta("1000", 10);

        float primeiroMembro = conta->getSaldo() - 10.0f;
        float segundoMembro = conta->diminuirSaldo(10);
        REQUIRE(primeiroMembro == segundoMembro);

        primeiroMembro = conta->getSaldo() + 10.0f;
        segundoMembro = conta->aumentarSaldo(10);
        REQUIRE(primeiroMembro == segundoMembro);

        delete conta;
    }
}

TEST_CASE("Testando Banco"){
    Banco banco;
    Conta *conta = new Conta("1000", 10);
    Conta *contaBonus = new Conta("2000", 20, true, 10);
    Conta *contaPoupanca = new Conta("3000", 30, true);

    SECTION("Testando vazia()"){
        REQUIRE(banco.vazia() == true);
    }

    SECTION("Testando adicionandoConta() e verificarExistencia()"){
        banco.adicionandoConta(conta);
        banco.adicionandoConta(contaBonus);
        banco.adicionandoConta(contaPoupanca);

        REQUIRE(banco.verificarExistencia("1000") == true);
        REQUIRE(banco.verificarExistencia("2000") == true);
        REQUIRE(banco.verificarExistencia("3000") == true);
    }

    SECTION("Testando dadosConta()"){
        banco.adicionandoConta(conta);
        REQUIRE(banco.dadosConta("1000") == conta);
    }
    delete conta;
    delete contaBonus;
    delete contaPoupanca;

}