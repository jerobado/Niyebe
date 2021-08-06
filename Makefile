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

# Source
sources = main.cpp
objects = main.o

# Rules & Recipes
$(TARGET): $(objects)
	@$(COMPILER) $(static-flag) -o $(TARGET) $(objects)
	@echo "$(COMPILER) $< --> $@"

main.o: $(SRC-DIR)main.cpp $(INCLUDE-DIR)NiyebeConfig.h
	@$(COMPILER) $(static-flag) $(i-flag) -c $(SRC-DIR)main.cpp
	@echo "$(COMPILER) $< --> $@"

install:
ifneq (,$(wildcard ./niyebe))
	@rm -rf /opt/niyebe
	@mkdir /opt/niyebe
	@cp niyebe /opt/niyebe
	@echo "Successfully installed niyebe in /opt/niyebe."
else
	@echo "Source code not yet compiled."
	@echo "Run 'make' to compile."
endif


clean:
	@rm -f *.o $(TARGET)
	@echo "Removed *.o *.exe files"
