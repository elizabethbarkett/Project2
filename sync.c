/*
 * NAME, etc.
 *
 * sync.c
 *
 * Synchronization routines for SThread
 */

#define _REENTRANT

#include "sthread.h"


/*
 * rwlock routines
 */

int sthread_rwlock_init(sthread_rwlock_t *rwlock)
{
        /* FILL ME IN! */
        return -1;
}

int sthread_rwlock_destroy(sthread_rwlock_t *rwlock)
{
        /* FILL ME IN! */
        return -1;
}

int sthread_read_lock(sthread_rwlock_t *rwlock)
{
        /* FILL ME IN! */
        return -1;
}

int sthread_read_try_lock(sthread_rwlock_t *rwlock)
{
        /* FILL ME IN! */
        return -1;
}

int sthread_read_unlock(sthread_rwlock_t *rwlock)
{
        /* FILL ME IN! */
        return -1;
}

int sthread_write_lock(sthread_rwlock_t *rwlock)
{
        /* FILL ME IN! */
        return -1;
}

int sthread_write_try_lock(sthread_rwlock_t *rwlock)
{
        /* FILL ME IN! */
        return -1;
}

int sthread_write_unlock(sthread_rwlock_t *rwlock)
{
        /* FILL ME IN! */
        return -1;
}
