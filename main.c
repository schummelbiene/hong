#include "boundary.h"

void main(int argc, char** argv) {

	boundary_t myboundary;

    boundary_init (&myboundary); // Adresse
	boundary_print(&myboundary);
	boundary_insert (&myboundary, 6, 0);
	boundary_print(&myboundary);
	boundary_insert (&myboundary, 8, 1);
	boundary_print(&myboundary);
	//boundary_delete(&myboundary, 0);
	//boundary_print(&myboundary);
    boundary_deinit(&myboundary);
	boundary_print(&myboundary);
}




