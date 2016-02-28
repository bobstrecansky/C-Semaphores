#include <stdio.h>
#include <stdlib.h>
#include "semProcs.h"

/*******************************************************
   Implementations of a general (counting) semaphores  *
********************************************************/

semaphore *semInit(int initialCount) {
   semaphore *new;
   new = malloc(sizeof(semaphore));
   if (new == NULL) {
      /* malloc() failed */
      exit(0)
   }
   pthread_mutex_init(&(new->semaMutex), NULL);
   pthread_cond_init(&(new->semaWait), NULL);
   new->count = initialCount;
   return(new);
}
   
void semWait(semaphore *semaPtr) {
    pthread_mutex_lock(&(semaPtr->semaMutex));
    semaPtr->count--;
    if (semaPtr->count < 0) {
       /* Wait on the semaphore's condition variable */
       pthread_cond_wait(&(semaPtr->semaWait),&(semaPtr->semaMutex));
    }
    pthread_mutex_unlock(&(semaPtr->semaMutex));
}

void semSignal(semaphore *semaPtr) {
    pthread_mutex_lock(&(semaPtr->semaMutex));
    semaPtr->count++;
    if (semaPtr->count <= 0) {
       pthread_cond_signal(&(semaPtr->semaWait)); /* If one or more threads are
                                                     waiting, wake-up one     */
    }
    pthread_mutex_unlock(&(semaPtr->semaMutex));
}

/************************************************
  End implementation of general semaphores
************************************************/
