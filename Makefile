CPP=g++
CPPSRC=main.cpp clientes.cpp
HSRC=clientes.h

all: $(CPPSRC) $(HSRC)
	$(CPP) -o ex $(CPPSRC)
