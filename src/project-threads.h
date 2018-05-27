/*
 * project-threads.h
 *
 *  Created on: 27 mai 2018
 *      Author: guillaume
 */

#ifndef PROJECT_THREADS_H_
#define PROJECT_THREADS_H_

/*
 * Include files
 */
#include <stdio.h>
#include <stdlib.h>
#include <function.h>

/*
 * struct
 */
typedef struct cStep cStep;

struct cStep{
	char* name;
	cStep* next;
};

typedef struct cList{
	char* name;
	cStep* first;
}cList;

/*
 * Prototypes
 */
cList* create_cList(char*);
void add_cStep(cList*,char*);
void free_all(cList* list);

#endif /* PROJECT_THREADS_H_ */
