/*
	Sample code for the tutorial adapted from 
	[LINK](http://stackoverflow.com/questions/4812891/fork-and-pipes-in-c)

*/


#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
/* Read characters from the pipe and echo them to stdout. */

void
read_from_pipe (int file)
{
    FILE *stream;
    int c;
    stream = fdopen (file, "r");
    while ((c = fgetc (stream)) != EOF)
        putchar (c);
    fclose (stream);
}

/* Write some random text to the pipe. */

void
write_to_pipe (int file)
{
    FILE *stream;
    stream = fdopen (file, "w");
    fprintf (stream, "hello, world!\n");
    fprintf (stream, "goodbye, world!\n");
    fclose (stream);
}

int
main (void)
{
    pid_t pid;
    int mypipe[2];
    char *argv[] = {"./SampleA", NULL};

    /* Create the pipe. */
    if (pipe (mypipe))
    {
        fprintf (stderr, "Pipe failed.\n");
        return EXIT_FAILURE;
    }

    /* Create the child process. */
    printf("Before fork\n");
    pid = fork ();
    printf("[%d] After fork\n",pid);


    if (pid == (pid_t) 0)
    {
    	printf("[%d] This is the child process\n", pid);
        /* This is the child process.
           Close other end first. */
        close (mypipe[1]);
        read_from_pipe (mypipe[0]);

        printf("Launching program SampleA\n\n");
        execvp(argv[0], argv);

        return EXIT_SUCCESS;
    }
    else if (pid < (pid_t) 0)
    {
        /* The fork failed. */
        fprintf (stderr, "Fork failed.\n");
        return EXIT_FAILURE;
    }
    else
    {
    	printf("[%d] This is the parent process\n", pid);
        /* This is the parent process.
           Close other end first. */
        close (mypipe[0]);
        write_to_pipe (mypipe[1]);

        waitpid(pid, NULL, 0);
        printf("\n[%d] Child process finished\n", pid);

        return EXIT_SUCCESS;
    }
}