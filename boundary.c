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
// TODO: boundary_insert adds an element after pos, it would be nice if actually adds it before.
// TODO: if the boundary is empty, inserting an element should close the cycle.
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
	
	for (int i = 0; i < pos; i++) {
		ver_iter = ver_iter->next;
	}
	
	// (start;abbruchbedingung;befehl für jede iteration)

	ver_new->next = ver_iter->next;
	ver_iter->next = ver_new;

	b->length++;
	
};

// Deletes the element at position pos of the boundary b. 
//TODO: if pos==0, retarget the b->head pointer.
//TODO: if b->length == 0; define a behavior
//TODO(MAYBE): if b->length == 1; set b->head == NULL
void boundary_delete(boundary_t* b, int pos) {
	
	if(pos == 0) {
		pos = b->length;
	};

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
	
	for(int i = 0; i < b->length; i++) {
		printf("%i ", ver_help->v);
		ver_help = ver_help->next;
	}
	printf("\n");
}
