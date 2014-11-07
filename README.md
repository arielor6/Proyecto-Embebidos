Proyecto-Embebidos
==================

Linea para compilarlo
  g++ -ggdb `pkg-config --cflags opencv` -o `basename hough.cpp .cpp` hough.cpp `pkg-config --libs opencv`
