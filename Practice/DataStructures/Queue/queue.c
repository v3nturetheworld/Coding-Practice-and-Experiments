#include "queue.h"



struct Queue *create_queue(int size)
{
    struct Queue *q = (struct Queue *)malloc(sizeof(struct Queue));
    q->data = (int *)malloc(sizeof(int) * (size+1));
    q->head = q->tail = q->data[0] = 0;
    q->size = size+1;
    printf("Queue created with %d items\n", size);
    return q;
}

int Enqueue(struct Queue *q, int val)
{
    if(!q)
    {
        fprintf(stderr, "ERROR: Cannot Enqueue a NULL queue\n");
        return 0;
    }
    //Inc Tail by 1 and check if it = head. Don't need modulo here since it's done
    //at the bottom. This check will fail in some edge cases when you actually want
    //to insert 0 into the queue.
    if(((q->tail+1) % q->size) == q->head) //&& (q->data[q->head] != 0))
    {
        fprintf(stderr, "ERROR: head = tail. Queue is FULL!\n");
        return -1;
    }

    q->data[q->tail] = val;
    q->tail = (q->tail+1) % q->size;
    printf("Enqueued the value %d\n", val);
    return 1;
}


int Dequeue(struct Queue *q)
{
    if(!q)
    {
        fprintf(stderr, "ERROR: Cannot remove anything from a NULL Queue\n");
        return -1;
    }
    if(q->head == q->tail)
    {
        fprintf(stderr, "ERROR: head == tail. Queue is empty.\n");
        return -1;
    }
    int temp = q->data[q->head];
    q->head = (q->head+1) % q->size;
    printf("Dequeued the value %d\n", temp);
    return temp;
}


void clean_queue(struct Queue *q)
{
    if(q == NULL) return;
    free(q->data);
    free(q);
    printf("Resources for Queue freed\n");
}
