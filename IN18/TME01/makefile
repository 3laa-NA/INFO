ALL_TARGETS = hello_world hello_world1

all: $(ALL_TARGETS)

clean:
	rm -f hello_world hello_world1 image

hello_world1: hello_world1.c
	gcc -Wall -o hello_world1 hello_world1.c

hello_world: hello_world.c
	gcc -Wall -o hello_world hello_world.c

image: image.c
	gcc -Wall -o image image.c
