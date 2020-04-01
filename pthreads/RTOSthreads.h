/*
 * RTOSthreads.h
 *
 *  Created on: 1 de abr de 2020
 *      Author: lucas
 */

#ifndef RTOSTHREADS_H_
#define RTOSTHREADS_H_

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>
pthread_cond_t condition1, condition2;
pthread_mutex_t signalMutex, stop;
pthread_mutex_t lock;
#define NUM_THREADS 10
#define MAX 9999

extern int var_global, var_primos;
typedef struct primos
{
	int * primos;
	unsigned int size;
}primos;
extern primos * pr;
/*
 * Faça um programa com 10 threads que incrementam de forma concorrente
 * uma variável global (chamada int var_global) 1000 vezes. A cada
 * incremento, cada thread imprime o valor incrementado e o identificador
 * da thread que modificou o valor
 */
void * incrementaGlobal(void * tid);
/*
 * Faça um programa que calcule os numeros primos existentes entre 0 e 9999
 * Ao final, o programa deve imprimir os valores calculados
 */
void * encontrandoPrimos(void * tid);

int primo(int val);


#endif /* RTOSTHREADS_H_ */
