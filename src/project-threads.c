/*
 ============================================================================
 Name        : project-threads.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include "project-threads.h"

int main(void) {
	setvbuf(stdout, NULL, _IONBF, 0);
	START_DEBUG("cube");
	DEBUG_PRINT("Creating CFOP List\n");
	cList* cfop = create_cList("CFOP","Cross");
	add_cStep(cfop, "F2L");
	add_cStep(cfop, "OLL");
	add_cStep(cfop, "PLL");
	DEBUG_PRINT("Creating Rouquin List\n");
	cList* roux = create_cList("Rouquin","First block");
	add_cStep(roux, "Second block");
	add_cStep(roux, "CMLL");
	add_cStep(roux, "2 Edges");
	add_cStep(roux,"M slice");
	display(stdout, cfop);
	display(stdout, roux);
	free_all(cfop);
	free_all(roux);
	return EXIT_SUCCESS;
}

void display(FILE* stream, cList* list) {
	if (list != NULL) {
		cStep* step = list->first;
		char* buff = malloc(1024 * sizeof(buff));
		strcpy(buff,"Steps of ");
		strcat(buff,list->name);
		strcat(buff, " : ");
		strcat(buff, list->first->name);
		fprintf(stream, "%s", buff);
		while (step->next != NULL) {
			step = step->next;
			fprintf(stream, ", %s", step->name);

		}
		fprintf(stream,"\n");
	} else {
		fprintf(stderr, "List not initialized !\n");
	}
}

void add_cStep(cList* pListe, char* name) {
	cStep* n_step = malloc(sizeof(cStep));
	n_step->name = name;
	n_step->next = NULL;
	if (pListe->first == NULL) {
		pListe->first = n_step;
	} else {
		int a=0;
		cStep* c_step = pListe->first;
		while (c_step->next != NULL) {
			c_step = c_step->next;
			a++;
		}
		c_step->next = n_step;
		DEBUG_PRINT("%s created !\n",name);
	}

}

void free_all(cList* list) {
	if (list != NULL) {
		cStep* prev_step = list->first;
		while (prev_step->next != NULL) {
			cStep* cur_step = prev_step->next;
			free(prev_step);
			prev_step = cur_step;
		}
		DEBUG_PRINT("%s freed\n",list->name);
		free(list);
	}
}

cList* create_cList(char* name,char* name_f) {
	cList* pListe = malloc(sizeof(pListe));
	pListe->name = name;
	cStep* firstone = malloc(sizeof(firstone));
	firstone->name=name_f;
	firstone->next=NULL;
	pListe->first=firstone;
	DEBUG_PRINT("%s created !\n",pListe->name);
	return pListe;
}

