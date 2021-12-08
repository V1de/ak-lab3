#include <stdlib.h>
#include <getopt.h>
#include <stdio.h>

/*
|	Vitalii Derachyts 
|   Lab3
*/

int main(int argc, char* argv[]) {
	const char* short_options = "hvd::f:";
	const struct option long_options[] = {
		{"help",no_argument,NULL,'h'},
		{"version",no_argument,NULL,'v'},
		{"date",no_argument,NULL,'d'},
		{NULL,0,NULL,0}
	};

	int rez;
	int check_h = 1;
	int check_v = 1;
	int check_d = 1;
	int option_index;

	while ((rez = getopt_long(argc, argv, short_options,
		long_options, &option_index)) != -1) {

		switch (rez) {
		case 'h': {
			if (check_h > 0){
				printf("-h (--help) shows programm options\n"
						"-v (--version) shows current program version\n"
						"-d (--date) shows date of release\n");
			}
			check_h--;
			break;
		};
		case 'v': {
			if (check_v > 0){
				printf("Current version = 1.0.0.\n");
			}
			check_v--;
			break;
		};

		case 'd': {
			if (check_d > 0){
				printf("Date of release - 08.12.21 \n");
			}
			check_d--;
			break;
		};
		
		case '?': default: {
			printf("Error.\n Watch -help first!\n");
			break;
		};
		};
	};
	return 0;
};