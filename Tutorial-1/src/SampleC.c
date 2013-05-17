#include <stdio.h>
#include <signal.h>

static int counter = 0;

void signal_handler(int arg)
{
	counter++;
	printf("  Caught Ctrl+C\n");
}

int main(int argc, char const *argv[])
{
	/* code */
	signal(SIGINT, signal_handler);
	while(counter < 3);
	return 0;
}