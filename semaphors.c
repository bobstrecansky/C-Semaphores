/*  
	Semaphores.c
	Create multiple child threads that each print individual word.  
	The objective of this program is to prove thread concurrency.
*/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <assert.h>
#include "semProcs.h"

/** Parameter structure template **/
typedef struct parms {
   int id;           /* Thread's unique id                 */
   char *word;       /* Pointer to word to print           */
   int  loopCnt;     /* Number of loops to perform         */
} parm_t;

/** Global data **/
semaphore *lock[8];

/** print words **/
void *printWord(void *parmPtr) {
   int ndx;

   /* Print this thread's word loopCnt times */
   for (ndx=0; ndx<((parm_t *)parmPtr)->loopCnt; ndx++) {
	semWait(lock[((parm_t *)parmPtr)->id]);
	fprintf(stdout, "%s", ((parm_t *)parmPtr)->word);    
	semSignal(lock[(((parm_t *)parmPtr)->id+1	) % 8]);
   }
   return(NULL);
}

/** Main **/
int main(int argc, char *argv[]) {
#define NUMWORDS 8                 /* Number of words/threads    */
  pthread_t threadIDs[NUMWORDS];;  /* Thread IDs                 */
  parm_t    parmPtr[NUMWORDS];     /* Thread parameters          */
  int       loops;                 /* Number of loops per thread */
  int       ndx;                   /* array index                */
  char *words[] = {"Tick ", "tock ", "the ", "mouse ", "ran ", 
                   "up ", "the ", "clock\n"};
int i;
lock[0] = semInit(1);
for(i=1; i < NUMWORDS; i++){
lock[i] = semInit(0);  //creates semaphores for each NUMWORDS

}

  /* Pickup the loop count from the command line */
  if (argc != 2) {
     printf("Usage: ./hw5 loopcnt\n");
     exit(1);
  }
  assert((loops= atoi(argv[1])) > 0);

  /* Create the printWord threads */
  for (ndx=0; ndx<NUMWORDS;  ndx++) {
      parmPtr[ndx].word = words[ndx];
      parmPtr[ndx].loopCnt = loops;
      parmPtr[ndx].id  = ndx;
      pthread_create(&threadIDs[ndx], NULL, printWord, &parmPtr[ndx]);
  }

  /* And wait for them to complete */
  for (ndx=0; ndx<NUMWORDS; ndx++) {
     pthread_join(threadIDs[ndx], NULL);
  }
  
  printf("\nParent done\n");

  exit(0);
}
