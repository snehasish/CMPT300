#include <stdio.h>
#include "hrtimer_x86.cc"

void empty(void){}

int main(int argc, char const *argv[])
{
	/* code */
	double start, end;
	start = gethrtime_x86();
	empty();
	end = gethrtime_x86();
	printf("Time: %0.8f\n", end-start );
	return 0;
}