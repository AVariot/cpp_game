#####################
#                   #
#	     R&A        #
#                   #
#####################


CC = g++
CFLAGS = -Wall -g -std=c++20
LFLAGS = -L/path/to/sfml/lib -lsfml-graphics -lsfml-window -lsfml-system

SRC_DIR = ./src
BUILD_DIR = ./build

SRCS := $(shell find . -name "*.cpp")
OBJS := $(SRCS:%=$(BUILD_DIR)/%.o)
DEPS := $(OBJS:.o=.d)

EXE = Geometry_douch

.PHONY: all clean

all: $(EXE)

$(EXE): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@ $(LFLAGS)

$(BUILD_DIR)/%.cpp.o: %.cpp
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -MMD -c $< -o $@

clean:
	rm -rf $(BUILD_DIR)

fclean: clean
	rm -rf $(EXE)

re: fclean all

-include $(DEPS)