#include "boundary.h"

int main(int argc, char** argv) {

	boundary_t myboundary;

	boundary_init (&myboundary); // Adresse
	boundary_print(&myboundary);
	boundary_delete(&myboundary, 1);
	boundary_insert (&myboundary, 6, 0);
	boundary_print(&myboundary);
	boundary_insert (&myboundary, 4, 0);
	boundary_print(&myboundary);
	boundary_delete(&myboundary, 2);
	boundary_print(&myboundary);
	boundary_delete(&myboundary, 0);
	//boundary_print(&myboundary);
	//  boundary_deinit(&myboundary);
	//boundary_print(&myboundary);

	return 0;
}




