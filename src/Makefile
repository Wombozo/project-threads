CC=gcc
CFLAGS=-ansi -wall
LFLAGS=-lfunction
LPATH=/home/guillaume/Documents/workspace/project-library/src/
EXEC=myExe

all: ${EXEC} clean 

${EXEC}: main.o 
		${CC} $^ -o $@ ${LFLAGS} -L${LPATH}

main.o: project-threads.c project-threads.h
		${CC} -c  $< -o $@

clean: 
		rm -rf *.o *~

#-L/home/guillaume/Documents/workspace/project-library/src/ -lfunction