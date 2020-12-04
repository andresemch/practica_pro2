OPCIONS = -D_JUDGE_ -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Werror -Wno-sign-compare -std=c++11

program.exe: program.o Contenedor.o Ubicacion.o Segmento.o Terminal.o Conj_contenedor.o Conj_huecos.o Area_espera.o
	g++ -o program.exe program.o Contenedor.o Ubicacion.o Segmento.o Terminal.o Conj_contenedor.o Conj_huecos.o Area_espera.o $(OPCIONS)

program.o: program.cc
	g++ -c program.cc $(OPCIONS)

Contenedor.o: Contenedor.cc
	g++ -c Contenedor.cc $(OPCIONS)

Ubicacion.o: Ubicacion.cc
	g++ -c Ubicacion.cc $(OPCIONS)

Segmento.o: Segmento.cc
	g++ -c Segmento.cc $(OPCIONS)

Terminal.o: Terminal.cc
	g++ -c Terminal.cc $(OPCIONS)

Conj_contenedor.o: Conj_contenedor.cc
	g++ -c Conj_contenedor.cc $(OPCIONS)

Conj_huecos.o: Conj_huecos.cc
	g++ -c Conj_huecos.cc $(OPCIONS)

Area_espera.o: Area_espera.cc
	g++ -c Area_espera.cc $(OPCIONS)

clean:
	rm -f *.o
	rm -f *.exe
