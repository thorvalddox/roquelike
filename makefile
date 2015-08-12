

COMPILER=g++
FLAGS=-std=c++11 -Wall -Werror -g
LIBS=$(shell pkg-config --libs allegro-5.0)
LIBSRAW=-L/usr/lib -lallegro_main -lallegro_acodec  -lallegro_audio \
		 -lallegro_color  -lallegro_dialog  -lallegro_image\
		 -lallegro_memfile -lallegro_physfs -lallegro_primitives -lallegro_ttf
INCLUDE=-I/usr/include/allegro5

main: main.cpp level.o
	$(COMPILER) $^ $(FLAGS) $(LIBS) $(INCLUDE)

level.o: level.cpp level.h
	$(COMPILER) -c $< $(FLAGS) $(LIBS) $(INCLUDE)

clean:
	rm *.o
