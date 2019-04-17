CPP=g++
CPPSRC=main.cpp clientes.cpp acervo.cpp
HSRC=clientes.h acervo.h

all: $(CPPSRC) $(HSRC)
	$(CPP) -o ex $(CPPSRC)
