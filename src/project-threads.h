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
#include <string.h>
#include <syslog.h>

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
cList* create_cList(char*,char*);
void add_cStep(cList*,char*);
void free_all(cList* list);
void display(FILE* stream,cList* list);

#ifdef LOGS

#define START_DEBUG(filename) openlog(filename, LOG_PID|LOG_ODELAY, LOG_LOCAL7)
#define DEBUG_PRINT(fmt, args...) syslog(LOG_DEBUG, fmt, ##args)
#define INFO_PRINT(fmt, args...) syslog(LOG_INFO, fmt, ##args)
#define ERROR_PRINT(fmt, args...) syslog(LOG_ERR, fmt, ##args)

#endif


#endif /* PROJECT_THREADS_H_ */

