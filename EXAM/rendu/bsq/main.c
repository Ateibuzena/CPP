#include "bsq.h"

int main(int argc, char* argv[])
{
	if(argc == 1)
	{
		if (execute_bsq(stdin))
			fprintf(stderr, "Error: invalid map\n");
	}
	else
	{
		// si el subject acepta más de un argumento:
		/*for(int i = 1; i < argc; i++)
		{
		    if(convert_file_pointer(argv[i]) == -1)
		        fprintf(stderr, "Error: invalid map\n");

		    if(i < argc - 1)
		        fprintf(stdout, "\n");
		}*/
		// si el subject acepta solo un argumento:
		if (argc > 2)
			fprintf(stderr, "Error: invalid number of arguments\n");

		if (convert_file_pointer(argv[1]))
		    fprintf(stderr, "Error: invalid map\n");

	}
	return(0);
}

