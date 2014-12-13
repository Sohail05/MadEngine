# I am a comment, and I want to say that the variable CC will be
# the compiler to use.
CC=g++
# Hey!, I am comment number 2. I want to say that CFLAGS will be the
# options I'll pass to the compiler.
CFLAGS= -std=c++11
#-w -Wall

SOURCES = src/main.cpp src/Input.cpp src/Camera.cpp src/shader.cpp

LIBRARIES = -lGL -lGLEW -lGLU -lglfw3 -lawesomium-1-7 -lXext -lXmu -lX11 -lm -lglfw3 -lGL -lm -lXrandr -lXi -lX11 -lXxf86vm -lpthread

INCLUDES = -I/usr/include

all:
	$(CC) $(INCUDES) $(CFLAGS) $(SOURCES) -o bin/MadEngine.out $(LIBRARIES)

clean: rm -rf *o MadEngine
