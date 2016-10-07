/*
 * NAME, etc.
 *
 * sync.c
 *
 * Synchronization routines for SThread
 */

#define _REENTRANT

#include "sthread.h"
#include<sched.h>


/*
 * rwlock routines
 */

int sthread_rwlock_init(sthread_rwlock_t *rwlock)
{
        /* FILL ME IN! */
        //5 points. use to initialize resources related to this struct
        return -1;
}

int sthread_rwlock_destroy(sthread_rwlock_t *rwlock)
{
        /* FILL ME IN! */
        //5 points. use to free resources related to this struct
        return -1;
}

int sthread_read_lock(sthread_rwlock_t *rwlock)
{
        /* FILL ME IN! */
        //15 points! should acquire the lock rwlock in read mode if the lock is available and otherwise block waiting until the lock can 
        //be acquired in read mode
        
        return -1;
}

int sthread_read_try_lock(sthread_rwlock_t *rwlock)
{
        /* FILL ME IN! */
        //5 points. should obtain the lock in read mode and return 0 if the lock is available and otherwise return 1 immediately 
        //without blocking
        return -1;
}

int sthread_read_unlock(sthread_rwlock_t *rwlock)
{
        /* FILL ME IN! */
        //10 points. should release the lock that was acquired in read mode and wake up one of the threads waiting in the sleeping
        //queue. These two operations must be one atomic step.
        
        return -1;
}

int sthread_write_lock(sthread_rwlock_t *rwlock)
{
        /* FILL ME IN! */
        //15 points! should acquire the lock rwlock in write mode if the lock is available and otherwise 
        //block waiting until the lock can be acquired in write mode
        return -1;
}

int sthread_write_try_lock(sthread_rwlock_t *rwlock)
{
        /* FILL ME IN! */
        //5 points. should obtain the lock in write mode and return 0 if the lock is available and otherwise return 1 
        //immediately w/o blocking
        return -1;
}

int sthread_write_unlock(sthread_rwlock_t *rwlock)
{
        /* FILL ME IN! */
        //10 points. should release the lock that was acquired in write mode and wake up one of the threads waiting in the sleeping queue. These
        //two operations should be one atomic step.
        return -1;
}
