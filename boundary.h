#ifndef BOUNDARY_H
#define BOUNDARY_H

struct vertex {
	struct vertex* next;
	int v;
};

typedef struct vertex vertex_t;

typedef struct {
	vertex_t* head;
	int length;
	
} boundary_t;

void boundary_init(boundary_t* b);
void boundary_deinit(boundary_t* b);
void boundary_insert(boundary_t* b, int val_new, int pos);
void boundary_delete(boundary_t* b, int pos);
void boundary_print(boundary_t* b);



#endif //BOUNDARY_H
