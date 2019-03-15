vpath %.h config
vpath %.c config
CFLAGS = -I config

objects = main.o config/config.o

spvclient : $(objects)
	gcc -o $@ $(CFLAGS)  $(objects)

main.o : main.c config.h
	gcc -c main.c $(CFLAGS)

config.o : config.c config.h
	gcc -c config.c $(CFLAGS) 
.PHONY : clean
clean:
	-rm spvclient $(objects)
