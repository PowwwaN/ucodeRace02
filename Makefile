CFLAGS = -std=c11 -Wall -Wextra -Wpedantic -Werror
LANG = clang

PROJ_NAME = way_home

all: uninstall $(PROJ_NAME)

$(PROJ_NAME):
	mkdir -p ./temp
	cp ./src/*.c ./inc/*.h ./temp/
	$(LANG) $(CFLAGS) ./temp/*.c -include ./temp/*.h -c
	mkdir -p obj
	mv ./*.o ./obj/
#	rm -rf ./temp/
	$(LANG) $(CFLAGS) ./obj/* -o $(PROJ_NAME) 
	rm -rf ./obj/

uninstall: clean
	rm -rf $(PROJ_NAME)

clean:
	rm -rf ./obj
	rm -rf ./temp
	rm -rf *.o

reinstall: uninstall $(PROJ_NAME)
