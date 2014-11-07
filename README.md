Proyecto-Embebidos
==================

Linea para compilarlo
  g++ -ggdb `pkg-config --cflags opencv` -o `basename deteccion.cpp .cpp` deteccion.cpp `pkg-config --libs opencv`
