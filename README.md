## Filename: semaphores.c
#### Objective: Create multiple child threads that each print individual word. The objective of this program is to prove thread concurrency.

#### Usage: 

###### make lint # Lint the configs
###### /usr/bin/cppcheck *.c *.h
###### Checking semProcs.c...
###### 1/3 files checked 34% done
###### Checking semProcs.h...
###### 2/3 files checked 46% done
###### Checking semaphors.c...
###### 3/3 files checked 100% done

###### ~/Desktop/C Programming - Semaphores> make && ./semaphors 10 # Execute the executible 
###### gcc -g -Wall   -c -o semaphors.o semaphors.c
###### gcc -g -Wall   -c -o semProcs.o semProcs.c
###### gcc -o semaphors semaphors.o semProcs.o -g -Wall -lpthread
###### Tick tock the mouse ran up the clock
###### Tick tock the mouse ran up the clock
###### Tick tock the mouse ran up the clock
###### Tick tock the mouse ran up the clock
###### Tick tock the mouse ran up the clock
###### Tick tock the mouse ran up the clock
###### Tick tock the mouse ran up the clock
###### Tick tock the mouse ran up the clock
###### Tick tock the mouse ran up the clock
###### Tick tock the mouse ran up the clock
###### Parent done

