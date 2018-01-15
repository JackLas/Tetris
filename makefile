#folders
SRC = source
HDR = header
BIN = bin

#compiler flags
FLAGS = -Wall -std=c++14 $(addprefix -I, $(HDR))

#command to object files compilation
COMPILATION_COMMAND = g++ $< $(FLAGS) -c -o $@

#DLL's linking flags
DLL_LINK = 	-lsfml-system \
			-lsfml-window \
			-lsfml-graphics

#object files
OBJ = 	$(BIN)/main.o \
		$(BIN)/Engine.o \
		$(BIN)/Game.o \
		$(BIN)/ResourceLoader.o \
		$(BIN)/GameArea.o \
		$(BIN)/Tetramino.o \
		$(BIN)/Block.o

#final linking
main.exe: $(OBJ)
	g++ $^ $(FLAGS) $(DLL_LINK) -o $@

#object compilation
$(BIN)/main.o: $(SRC)/main.cpp $(HDR)/Game.hpp 
	$(COMPILATION_COMMAND)

$(BIN)/Engine.o: $(SRC)/Engine.cpp $(HDR)/Engine.hpp
	$(COMPILATION_COMMAND)

$(BIN)/Game.o: $(SRC)/Game.cpp $(HDR)/Game.hpp $(HDR)/Engine.hpp $(HDR)/GameArea.hpp $(HDR)/ResourceLoader.hpp
	$(COMPILATION_COMMAND)

$(BIN)/ResourceLoader.o: $(SRC)/ResourceLoader.cpp $(HDR)/ResourceLoader.hpp
	$(COMPILATION_COMMAND)

$(BIN)/GameArea.o: $(SRC)/GameArea.cpp $(HDR)/GameArea.hpp
	$(COMPILATION_COMMAND)

$(BIN)/Tetramino.o: $(SRC)/Tetramino.cpp $(HDR)/Tetramino.hpp
	$(COMPILATION_COMMAND)

$(BIN)/Block.o: $(SRC)/Block.cpp $(HDR)/Block.hpp
	$(COMPILATION_COMMAND)