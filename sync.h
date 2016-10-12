/*
 *
 *
 * sync.h
 */

#ifndef _STHREAD_SYNC_H_
#define _STHREAD_SYNC_H_



struct sthread_rwlock_struct {
    /* FILL ME IN! 
	read_lock is 0 or 1
	write_lock is 0 or 1
	make wait queue for threads
	call test and set with lock
    */
    unsigned long  *lock;
    sthread_t *wait_queue;
    int *front_of_queue;//next thread in queue to be woken
    int *count_variable;//back of queue, next open spot to add to queue
    sthread_t thread_id;
};

typedef struct sthread_rwlock_struct sthread_rwlock_t;

int sthread_rwlock_init(sthread_rwlock_t *rwlock);
int sthread_rwlock_destroy(sthread_rwlock_t *rwlock);
int sthread_read_lock(sthread_rwlock_t *rwlock);
int sthread_read_try_lock(sthread_rwlock_t *rwlock);
int sthread_read_unlock(sthread_rwlock_t *rwlock);
int sthread_write_lock(sthread_rwlock_t *rwlock);
int sthread_write_try_lock(sthread_rwlock_t *rwlock);
int sthread_write_unlock(sthread_rwlock_t *rwlock);

#endif

