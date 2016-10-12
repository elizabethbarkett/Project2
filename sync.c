/*
 *
 *
 * sync.c
 *
 * Synchronization routines for SThread
 */
#include "sthread.h"
#include <sched.h>
#include <stdlib.h>
#include <stdio.h>

/*
 * rwlock routines
 TODO: 
 */

int sthread_rwlock_init(sthread_rwlock_t *rwlock)
{
        /* FILL ME IN! */
        rwlock->lock = 0; //unlocked
        //dynamically allocated queue
        rwlock->wait_queue = malloc(1000*sizeof(sthread_t));
        rwlock->thread_id = 0;
        rwlock->front_of_queue = 0;
        rwlock->count_variable = 0;
        return 1;
}

int sthread_rwlock_destroy(sthread_rwlock_t *rwlock)
{
        /* FILL ME IN! */
        free(rwlock->wait_queue);
        return 1;
}

int sthread_read_lock(sthread_rwlock_t *rwlock)
{
        sthread_t this_thread = sthread_self();
        while(0){
                int isLocked = sthread_write_try_lock(rwlock);
        // return isLocked
        //if 0 call read_lock
        //if 1 add thread to queue and suspend
                if(isLocked == 0){
                //rwlock->thread_id = sthread_self();
                //enter C.S. then release lock 
                        printf("Entering critical section %d\n", this_thread);
                }
                else{
                //yeild thread and add to wait queue
                        
                        
                        rwlock->wait_queue[*rwlock->count_variable++] = this_thread;
                        printf("suspending thread %d wait count = %d\n", this_thread, rwlock->count_variable);
                        sthread_suspend();
                        //thread woken, 
                        printf("Thread woken = %d\n", this_thread);
                        rwlock->thread_id = sthread_self();
                     
                }
        }
        /* FILL ME IN! */
        return -1;
}

int sthread_read_try_lock(sthread_rwlock_t *rwlock)
{
        /* FILL ME IN! 
        call test and set on rwlock->lock
        if lock is 0
        call read_lock
        else
        add to queue

        */
        int isLocked = test_and_set(rwlock->lock);
        return isLocked;
        /*while(TRUE){
        int isLocked = test_and_set(rwlock->lock);
        // return isLocked
        //if 0 call read_lock
        //if 1 add thread to queue and suspend
        if(isLocked == 0){
                //enter C.S. 
        }
        else{
                //yeild thread and add to wait queue
        }
        }*/
        return -1;
}

int sthread_read_unlock(sthread_rwlock_t *rwlock)
{
        rwlock->lock = 0;
        //call try_lock with next thread in queue
        //one ATOMIC step
        sthread_wake(rwlock->wait_queue[*rwlock->front_of_queue++]);
        return -1;
}

int sthread_write_lock(sthread_rwlock_t *rwlock)
{
        sthread_t this_thread = sthread_self();
        while(0){
                int isLocked = sthread_write_try_lock(rwlock);
        // return isLocked
        //if 0 call read_lock
        //if 1 add thread to queue and suspend
                if(isLocked == 0){
                //enter C.S. 
                printf("Entering critical section %d\n", this_thread);
                }
                else{
                //yeild thread and add to wait queue
                        //sthread_t this_thread = sthread_self();
                        //rwlock->wait_queue[rwlock->count_variable++] = this_thread
                        //rwlock->thread_id = sthread_self();
                        //rwlock->wait_queue[rwlock->count_variable++] = rwlock->thread_id;
                        //sthread_suspend();
                        //thread woken, update front of queue
                        
                        
                        rwlock->wait_queue[*rwlock->count_variable++] = this_thread;
                        printf("suspending thread %d wait count = %d\n", this_thread, rwlock->count_variable);
                        sthread_suspend();
                        //thread woken, 
                        printf("Thread woken = %d\n", this_thread);
                        //rwlock->thread_id = sthread_self();
                     
                }
        }
        /* FILL ME IN! */
        return -1;
}

int sthread_write_try_lock(sthread_rwlock_t *rwlock)
{// should obtain the lock in write mode and return 0 if the lock is available 
        //and otherwise return 1 immediately without blocking.
        int isLocked = test_and_set(rwlock->lock);
        return isLocked;
        
        /* FILL ME IN! */
        return -1;
}

int sthread_write_unlock(sthread_rwlock_t *rwlock)
{
        rwlock->lock = 0;
        //call try_lock with next thread in queue update front of queue
        //one ATOMIC step
        sthread_wake(rwlock->wait_queue[*rwlock->front_of_queue++]);

        return -1;
}

