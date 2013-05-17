#include <pthread.h>
#include <stdio.h>
#include "hrtimer_x86.cc"

#define COUNT 10000
#define THREADS 20


volatile long shared_counter = 0;

#ifdef USE_LOCKS
pthread_spinlock_t lock;		
#endif


void *threadMain(void *args)
{
	int i;
	for (i = 0; i < COUNT; ++i)
	{
		/* code */
		#ifdef USE_LOCKS
		pthread_spin_lock(&lock);
		#endif

		shared_counter++;

		#ifdef USE_LOCKS
		pthread_spin_unlock(&lock);
		#endif
	}

	return NULL;
}

int main(int argc, char const *argv[])
{
	int i;
	double startTime, endTime;

	#ifdef USE_LOCKS
	pthread_spin_init(&lock, PTHREAD_PROCESS_SHARED);
	#endif

	/* code */
	pthread_t threads[THREADS];
	for (i = 0; i < THREADS; ++i)
	{
		/* code */
		pthread_create(&threads[i], NULL, threadMain, NULL);
	}

	startTime = gethrtime_x86();

	for (i = 0; i < THREADS; ++i)
	{
		/* code */
		pthread_join(threads[i], NULL);
	}

	endTime = gethrtime_x86();

	printf("Total Shared Count is: %ld\n", shared_counter);
	printf("Time taken: %fs\n", endTime - startTime);

	return 0;
}