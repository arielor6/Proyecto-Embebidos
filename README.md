Proyecto-Embebidos
==================

Linea para compilarlo

g++ -ggdb `pkg-config --cflags opencv` -o `basename Detection.cpp .cpp` Detection.cpp `pkg-config --libs opencv`
