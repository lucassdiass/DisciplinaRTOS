/*
 * RTOSthreadsmain.c
 *
 *  Created on: 1 de abr de 2020
 *      Author: lucas
 */
#include "RTOSthreads.h"
int main()
{
	pthread_t threads[NUM_THREADS];
	pthread_t  t=0;
	int rc=0, index=0;
	pthread_t thr_id ;
	for(;t<NUM_THREADS;t++)
	{
		rc=pthread_create(&threads[t],NULL, incrementaGlobal, (void *)t );
		if(rc)
		{
			printf("Erro ao criar a thread\n");
		}
	}
	if(var_global<1000)
	{
		pthread_cond_wait(&condition1, &stop); // waiting for event
		pthread_mutex_unlock(&stop);
	}
	for(t=0;t<9;t++)
	{
		rc=pthread_create(&threads[t],NULL, encontrandoPrimos, (void *)t);
		if(rc)
		{
			printf("Erro ao criar a thread\n");
		}
	}
	if(var_primos<MAX)
	{
		pthread_cond_wait(&condition2, &stop); // waiting for event
		pthread_mutex_unlock(&stop);
	}
	if(pr!=NULL)
	{
		for(;index<pr->size;index++)
		{
			printf("%d\n", pr->primos[index]);
		}
	}
	return 0;
}



