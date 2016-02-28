#ifndef SEMPROCS_H
#define SEMPROCS_H

#include <pthread.h>

/* Semaphore data type */
typedef struct semaData {
    pthread_mutex_t semaMutex;   /* mutex to protect the semaphore value */
    pthread_cond_t  semaWait;    /* condition variable to wait on        */
    int count;                   /* semaphore's count value              */
} semaphore;

/* Prototype statements */
semaphore *semInit(int initialCountValue);
void semWait(semaphore *sem);
void semSignal(semaphore *sem);

#endif

