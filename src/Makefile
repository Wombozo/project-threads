CC=gcc
CFLAGS=-ansi -wall
LFLAGS=-lfunction
LPATH=/home/guillaume/Documents/workspace/project-library/src/
LOGS=-DLOGS
EXEC=myExe


all: ${EXEC} clean 

${EXEC}: main.o 
		${CC} $^ -o $@ ${LFLAGS} -L${LPATH} ${LOGS}

main.o: project-threads.c project-threads.h
		${CC} -c  $< -o $@ ${LOGS}

clean: 
		rm -rf *.o *~

#-L/home/guillaume/Documents/workspace/project-library/src/ -lfunction