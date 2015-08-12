

COMPILER=g++
FLAGS=-std=c++11 -Wall -Werror
LIBS=$(shell pkg-config --libs "allegro-5.0 allegro_font-5.0 allegro_image-5.0 allegro_primitives-5.0")

LIBSRAW=-L/usr/lib -lallegro_main -lallegro_acodec  -lallegro_audio \
		 -lallegro_color  -lallegro_dialog  -lallegro_image\
		 -lallegro_memfile -lallegro_physfs -lallegro_primitives -lallegro_ttf

INCLUDE=-I/usr/include/allegro5

main: clean build

optimize: FLAGS+=-O2
optimize: clean build

build: src/main.o src/level.o src/gui.o src/game.o src/gameevent.o src/entity.o  src/elements.o
	$(COMPILER) $^ $(FLAGS) $(LIBS) $(INCLUDE)

%.o: %.cpp
	$(COMPILER) -c $< -o $@ $(FLAGS) $(LIBS) $(INCLUDE)

clean:
	rm -f src/*.o
