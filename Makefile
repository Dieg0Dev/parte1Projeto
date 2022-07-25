

all: 
	g++ main.cpp Banco.cpp Conta.cpp -o run
	g++ testes.cpp Banco.cpp Conta.cpp -o runtest
clean:
	rm -rf run runtest
