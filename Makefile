OBJS = semaphors.o semProcs.o
CFLAGS = -g -Wall

semaphors: ${OBJS}
	gcc -o $@ ${OBJS} -g -Wall -lpthread

${OBJS}: semProcs.h

clean:
	rm -f *.o semaphores

lint:
	/usr/bin/cppcheck *.c *.h
