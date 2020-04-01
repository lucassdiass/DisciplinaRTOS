/*
 * RTOSthreads.c
 *
 *  Created on: 1 de abr de 2020
 *      Author: lucas
 */

#include "RTOSthreads.h"
primos * pr=NULL;
int var_global=0;
int var_primos=1;
void * incrementaGlobal(void * tid)
{
	long t=(long)tid;
	while(var_global<1000)
	{
		pthread_mutex_lock(&lock);
		if(var_global<1000)
		{
			++var_global;
			printf("Thread #%ld Valor: %d\n", t,var_global );
		}
		pthread_mutex_unlock(&lock);
	}
	pthread_cond_signal(&condition1);
	//var_global=1;
	pthread_mutex_unlock(&stop);
	pthread_exit(NULL);
}


void * encontrandoPrimos(void * tid)
{
	long t=(long)tid;
	int p=0, index=0;
	primos * aux=NULL;
	while(var_primos<MAX)
	{
		pthread_mutex_lock(&lock);
		if(var_primos<MAX)
		{
			//printf("Thread #%ld\n",t);
			p=primo(var_primos);
			++var_primos;
			pthread_mutex_unlock(&lock);

			if(p)
			{
				pthread_mutex_lock(&signalMutex);
				aux=malloc(sizeof(primos));
				if(pr==NULL)
				{
					pr=aux;
					pr->size=1;
					pr->primos= malloc(sizeof(int));
					*(pr->primos)=p;
				}
				else
				{
					aux->size=pr->size+1;
					aux->primos= malloc(sizeof(int)*aux->size);
					for(index=0;index<pr->size;index++)
					{
						*(aux->primos+index)=*(pr->primos+index);
					}
					*(aux->primos+index)=p;
					free(pr->primos);
					free(pr);
					pr=aux;
				}
				pthread_mutex_unlock(&signalMutex);

			}
		}
	}
	pthread_cond_signal(&condition2);
	pthread_mutex_unlock(&stop);
	pthread_exit(NULL);
}
int primo(int val)
{
	int aux=0, index=0;
	if(val<1)
	{
		return 0;
	}
	for(index=1;index<val;index++)
	{
		if(!(val%index))
		{
			aux++;
		}
	}
	if(aux<=2)
	{
		return val;
	}
	return 0;
}

