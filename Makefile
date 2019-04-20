CPP=g++
CPPSRC=main.cpp clientes.cpp acervo.cpp locacao.cpp
HSRC=clientes.h acervo.h locacao.h

all: $(CPPSRC) $(HSRC)
	$(CPP) -o ex $(CPPSRC)
