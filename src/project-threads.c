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
	printHello();
	cList* cfop = create_cList("CFOP");
	add_cStep(cfop,"Cross");
	add_cStep(cfop,"F2L");
	add_cStep(cfop,"OLL");
	add_cStep(cfop,"PLL");

	free_all(cfop);
	return EXIT_SUCCESS;
}

void display(FILE* stream,cList* list){
	if (list!=NULL){
		cStep* step = list->first;
		char* buff = "Steps of ";
		strncat(buff,list->name,sizeof(list->name));
		strcat(buff," : ");
		strcat(buff,list->first->name);
		fprintf(stream,buff);
		while (step->next!=NULL){
			fprintf(stream,"%s, ",step->name);
			step=step->next;
		}
	}
	else{
		fprintf(stderr,"List not initialized !\n");
	}
}

void add_cStep(cList* pListe, char* name) {
	cStep* n_step = malloc(sizeof(cStep));
	n_step->name = name;
	if (pListe->first == NULL) {
		pListe->first = n_step;
	} else {
		cStep* c_step = pListe->first;
		while (c_step->next != NULL) {
			c_step = c_step->next;
		}
		c_step->next = n_step;
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
		free(list);
	}
}

cList* create_cList(char* name) {
	cList* pListe = malloc(sizeof(pListe));
	pListe->name=name;
	return pListe;
}

