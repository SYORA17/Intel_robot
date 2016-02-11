#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXCHAR 256
#define MAXCOM 10


void getargs(int *argc, char *argv[])
{

	
	char c;
	int cnt = 0;
	*argc = 0;
	int charcnt = 0;
	int prev = 0;
	int err = 0;
	do{
		c = getchar();

		if (cnt++ == MAXCHAR-1) {
			break;
		}

		if (c == EOF) {
			break;
		}

		if (prev != 1 && (c == ' ' || c == '\t' || c ==  '\n')) {
				prev = 1;	
				argv[*argc][charcnt] = '\0';
				charcnt = 0;
				*argc += 1;
		} else if (('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z') || ('0' <= c && c <= '9') ){
			argv[*argc][charcnt++] = c;
			prev = 0;
		}
	} while (c !=  '\n');
	
	
	argv[*argc][charcnt] = '\0';

}


