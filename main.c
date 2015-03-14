#include "boundary.h"

void main(int argc, char** argv) {

	boundary_t myboundary;
	
    boundary_init (&myboundary); // Adresse
	boundary_insert (&myboundary, 6, 0);
	boundary_insert (&myboundary, 8, 1);
	boundary_print(&myboundary);
	boundary_delete(&myboundary, 0);
}




