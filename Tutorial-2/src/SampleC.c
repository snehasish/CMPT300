#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
	/* Forcing context switches */

	pid_t pid = 0;
	int pc_pipe[2], cp_pipe[2], n = 0, i;
	pipe(pc_pipe);
	pipe(cp_pipe);

	pid = fork();

	if(pid == 0) 
	{
		/* Child */
		
		for (i = 0; i < 10; ++i)
		{
			/* code */
			n = 20;
			write(cp_pipe[1], &n, sizeof(n) );
			read(pc_pipe[0], &n, sizeof(n) );
			printf("N from parent: %d\n", n);
		}
		
		
	}
	else if( pid < 0)
	{
		/* Error */

	}
	else
	{
		/* Parent */
		for (i = 0; i < 10; ++i)
		{
			/* code */
			read(cp_pipe[0], &n, sizeof(n) );
			printf("N from child: %d\n", n);
			n = 10;
			write(pc_pipe[1], &n, sizeof(n) );
		}
		
	}

	return 0;
}