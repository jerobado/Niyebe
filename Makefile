# Alternative to CMAKE

# Check OS in order to use the appropriate compiler
ifeq ($(OS),Windows_NT)
	COMPILER=x86_64-w64-mingw32-g++
	TARGET=niyebe.exe
else
	COMPILER=g++
	TARGET=niyebe
endif

# Directories
SRC-DIR = src/
INCLUDE-DIR = include/

# Flags
i-flag = -I include
static-flag = -static -static-libstdc++ -static-libgcc
compiler-flag = -std=c++20 -Wall -Wextra

# Source
sources = main.cpp
objects = main.o niyebe.o

# Rules & Recipes
$(TARGET): $(objects)
	@$(COMPILER) $(static-flag) -o $(TARGET) $(objects)
	@echo [LINK] $(COMPILER) $(static-flag) $< - $@

main.o: $(SRC-DIR)main.cpp $(INCLUDE-DIR)NiyebeConfig.h
	@$(COMPILER) $(i-flag) $(compiler-flag) $(static-flag) -c $(SRC-DIR)main.cpp
	@echo [COMPILE] $(COMPILER) $(i-flag) $(compiler-flag) $< - $@

niyebe.o: $(SRC-DIR)niyebe.cpp
	@$(COMPILER) $(i-flag) $(compiler-flag) $(static-flag) -c $(SRC-DIR)niyebe.cpp
	@echo [COMPILE] $(COMPILER) $(i-flag) $(compiler-flag) $< - $@

install:
ifneq (,$(wildcard ./niyebe))
	@rm -rf /opt/Niyebe
	@mkdir /opt/Niyebe
	@cp niyebe /opt/Niyebe
	@echo "Successfully installed niyebe in /opt/Niyebe."
else
	@echo "INSTALL ERROR: Source code not yet compiled.\n"
	@echo "Suggested fix: Run 'make' to compile."
endif


clean:
ifeq ($(OS),Windows_NT)
	@del *.o *.exe
	@echo "Removed *.o *.exe files"
else
	@rm -f *.o $(TARGET)
	@echo "Removed *.o *.exe files"
endif