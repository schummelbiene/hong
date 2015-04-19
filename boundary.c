#include <stdio.h>
#include <stdlib.h>

#include "boundary.h"

// Creates a BRILLIANT (not really new, because we already have the pointer to it), empty boundary
void boundary_init(boundary_t* b) {
	b->head = NULL;
	b->length = 0;
};

// Clears the whole boundary list.
void boundary_deinit(boundary_t* b) {
    if(b->length <= 0) return;
    vertex_t* ver_iter = b->head;
    do {
        vertex_t* ver_help = ver_iter;
        ver_iter = ver_iter->next;
        free(ver_help);
    } while(b->head != ver_iter);
    b->head = NULL;
    b->length = 0;
};


// Inserts a new vertex with valence val_new into the boundary at the position between the elements at pos and pos+1.

void boundary_insert(boundary_t* b, int val_new, int pos) {

	//	b->head =def= (*l).head;
	vertex_t* ver_new = malloc(sizeof(vertex_t));
	ver_new->v = val_new;
	
	if(b->length == 0) {
		b->head = ver_new;
		ver_new->next = ver_new;
		//		i += 1 =def= i++ =def= i = i + 1
		//    x *= 2 =def= x <<= 1
		b->length = 1;
		return;
	}
	
	pos = pos % b->length;

	//	vertex_t ver_new = *malloc(sizeof(vertex_t)); falsch, lokal


	vertex_t* ver_iter = b->head;
	
	for (int i = 1; i < pos; i++) {
		ver_iter = ver_iter->next;
	}
	
	// (start;abbruchbedingung;befehl für jede iteration)

	ver_new->next = ver_iter->next;
	ver_iter->next = ver_new;

	b->length++;
	
};

// Inserts n - 2 new vertices between positions pos - 1 and pos.

void boundary_add_ngon(boundary_t* b, int n, int pos) {

	// Insertion of n - 2 new vertices
	for (int i = 1; i < n - 1; i++) {
		boundary_insert(b, 1, pos);
	}

	//Incrementation of the both border vertices
	for (int i = 0; i < n + pos; i++) {}
	
}

// Deletes the element at position pos of the boundary b. 

void boundary_delete(boundary_t* b, int pos) {

	if(b->length == 0) {
		printf("Nothing to delete. \n");
		return;
	}	else if(b->length == 1) {
		free(b->head);
		b->head = NULL;
		b->length = 0;
		return;
	}
    pos %= b->length;
	// Philosophy: First set the second element as new head element, then delete the last element (at position 'length'). This is the old head.
    if(pos == 0) {
		pos = b->length-1;
		b->head = b->head->next;	
	}
	
	vertex_t* ver_iter = b->head;
	
	for(int i = 0; i < pos-1; i++) {
		ver_iter = ver_iter->next;
	}
	vertex_t* ver_help = ver_iter->next;
	ver_iter->next = ver_iter->next->next;
	free(ver_help);
 	
	b->length--;

}

void boundary_print(boundary_t* b) {

	vertex_t* ver_help = b->head;
	if (b->length > 0){
		printf("%2i: ", b->length);
	}
	
	for(int i = 0; i < b->length; i++) {
		printf("%i ", ver_help->v);
		ver_help = ver_help->next;
	}
	printf("\n");
}
