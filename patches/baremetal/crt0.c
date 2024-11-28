#include <stdio.h> // fflush()
#include <stdlib.h> // EXIT_FAILURE

extern int main(int argc, char *argv[]);

extern char __bss_start;
extern char __bss_stop;

static void zero_bss(void);

int _start()
{
	zero_bss();

	int retval = main();
	
	fflush(stdout);

	return retval;
}

static void zero_bss(void)
{
	for(char *c = &__bss_start; c < &__bss_stop; c++)
		*c = 0;
}
