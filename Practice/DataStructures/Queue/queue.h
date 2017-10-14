//Queue.h
//An implementation of a fixed size Queue
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

struct Queue {
    int *data;
    int head, tail, size;
};

struct Queue * create_queue(int size);
int Enqueue(struct Queue *q, int val);
int Dequeue(struct Queue *q);
void clean_queue(struct Queue *q);
