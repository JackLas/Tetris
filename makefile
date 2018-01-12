#folders
SRC = source
HDR = header
BIN = bin

#compilation flags
COMP_FLAGS = -Wall -std=c++14 $(addprefix -I, $(HDR))

#output object flags
OBJ_OUT_FLAGS = -c -o $@

#DLL's flags
DLL_LINK = 	-lsfml-system \
			-lsfml-window \
			-lsfml-graphics

#full flags
FLAGS = $(COMP_FLAGS) $(DLL_LINK)

#object files
OBJ = 	$(BIN)/main.o \
		$(BIN)/Engine.o \
		$(BIN)/Game.o \
		$(BIN)/ResourceLoader.o \
		$(BIN)/GameArea.o 

#final linking
main.exe: $(OBJ)
	g++ $^ $(FLAGS) -o $@

#object compilation
$(BIN)/main.o: $(SRC)/main.cpp $(HDR)/Game.hpp 
	g++ $< $(FLAGS) $(OBJ_OUT_FLAGS)

$(BIN)/Engine.o: $(SRC)/Engine.cpp $(HDR)/Engine.hpp
	g++ $< $(FLAGS) $(OBJ_OUT_FLAGS)

$(BIN)/Game.o: $(SRC)/Game.cpp $(HDR)/Game.hpp $(HDR)/Engine.hpp $(HDR)/GameArea.hpp $(HDR)/ResourceLoader.hpp
	g++ $< $(FLAGS) $(OBJ_OUT_FLAGS)

$(BIN)/ResourceLoader.o: $(SRC)/ResourceLoader.cpp $(HDR)/ResourceLoader.hpp
	g++ $< $(FLAGS) $(OBJ_OUT_FLAGS)

$(BIN)/GameArea.o: $(SRC)/GameArea.cpp $(HDR)/GameArea.hpp
	g++ $< $(FLAGS) $(OBJ_OUT_FLAGS)