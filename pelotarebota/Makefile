SFML_path= /home/student/jcampos/librerias/SFML
LD_flasgs= -lsfml-graphics -lsfml-window -lsfml-system

all:  pelota.o
	@echo
	g++ pelota.o -o pelota -L$(SFML_path)/lib $(LD_flasgs)

pelota.o: pelota.cpp
	g++ -c pelota.cpp -I$(SFML_path)/include -o pelota.o

clean:
	$(RM) pelota.o pelota
