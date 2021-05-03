

CC = g++

COMPILER_FLAGS = -Wfatal-errors -w

SRC_DIR := ./src
OBJ_DIR := ./obj

SRC := $(wildcard $(SRC_DIR)/*.cpp)
OBJ := $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

USER_INCLUDE = -I/usr/include
DEPS_INCLUDE = -I./deps

GLFW_LINKS = /usr/lib/x86_64-linux-gnu/libglfw.so
GLEW_LINKS = /usr/lib/x86_64-linux-gnu/libX11.so
SOIL2_LINKS = ./deps/SOIL2/lib/linux/libsoil2.so

all : $(OBJ)
	$(CC) ./src/main.cpp -o  main $(COMPILER_FLAGS) $(USER_INCLUDE) $(DEPS_INCLUDE) $(GLFW_LINKS) $(GLEW_LINKS) $(SOIL2_LINKS) -lGL -lglfw -lGLEW -lGLU -lGL -lGL -lX11 -ldl -lpthread -lrt