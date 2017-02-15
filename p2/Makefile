# Change the following values to suit your system.

CFLAGS=`sdl2-config --cflags` -W -Wall -Weffc++ -Wextra -pedantic -O0 -I `sdl2-config --prefix`/include/ 
SDL_LIB=`sdl2-config --libs` -lSDL2_image
CCC=g++

OBJECTS = frameGenerator.o background.o clock.o football.o referee.o banner.o

run: main.o $(OBJECTS)
	$(CCC) $(CFLAGS) main.cpp -o run $(OBJECTS) $(SDL_LIB)

main.o: main.cpp frameGenerator.h background.h clock.h football.h referee.h banner.h
	$(CCC) $(CFLAGS) -c main.cpp

frameGenerator.o: frameGenerator.cpp frameGenerator.h
	$(CCC) $(CFLAGS) -c frameGenerator.cpp

background.o: background.cpp background.h
	$(CCC) $(CFLAGS) -c background.cpp

clock.o: clock.cpp clock.h
	$(CCC) $(CFLAGS) -c clock.cpp

football.o: football.cpp football.h clock.h
	$(CCC) $(CFLAGS) -c football.cpp

referee.o: referee.cpp referee.h
	$(CCC) $(CFLAGS) -c referee.cpp

banner.o: banner.cpp banner.h clock.h
	$(CCC) $(CFLAGS) -c banner.cpp

clean:
	rm -f run *.o
	rm -f *~
	rm -f frames/*.bmp
