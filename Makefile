
CC=g++

CFLAGS= -std=c++11

SOURCES = src/main.cpp src/Input.cpp src/Camera.cpp src/shader.cpp

LIBRARIES = -lGL -lGLEW -lGLU -lglfw3 -lawesomium-1-7 -lXext -lXmu -lX11 -lm -lglfw3 -lGL -lm -lXrandr -lXi -lX11 -lXxf86vm -lpthread

INCLUDES = -I/usr/include

all:
	$(CC) $(INCUDES) $(CFLAGS) $(SOURCES) -o bin/MadEngine.out $(LIBRARIES)

clean: rm -rf *o MadEngine
