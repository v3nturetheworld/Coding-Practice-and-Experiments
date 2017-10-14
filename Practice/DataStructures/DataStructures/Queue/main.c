#include "queue.h"


void test_enqueue()
{
    printf("\n\nTesting Enqueue\n");
    struct Queue *q = create_queue(10);
    for(int i = 0; i < 12; ++i)
        Enqueue(q, rand() % 25);
    printf("Done Testing Enqueue\n");
    clean_queue(q);
}

void test_dequeue()
{
    printf("\n\nTesting Dequeue\n");
    
    struct Queue *q;
    
//    printf("1. NULL test\n");
//    Dequeue(q);
   
    int arr[10] = {0};
    printf("2. Empty Queue test\n");
    q = create_queue(10);
    Dequeue(q);
    
    printf("3. Null item dequeue test\n");
    Enqueue(q, rand() % 25);
    Enqueue(q, rand() % 25);
    
    Dequeue(q);
    Dequeue(q);
    Dequeue(q);

    printf("4. Fill empty fill test\n");
    printf("ENQUEUEING...\n");
    for(int i = 0; i < 10; ++i)
    {
        int num = rand() % 25;
        arr[i] = num;
        printf("[%d]: ", i);
        Enqueue(q, num);
    }
    printf("\nDEQUEUEING...\n");
    for(int i = 0; i < 10; ++i)
    {
        printf("[%d]: ", i); 
        int res = Dequeue(q);
        if(arr[i] != res)
        {
            fprintf(stderr, "\nERROR: Enqueue'd value doesn't match dequeued value\n");
        }
    }
    printf("\nENQUEUEING...\n");
    for(int i = 0; i < 10; ++i)
    {
        int num = rand() % 25;
        arr[i] = num;

        printf("[%d]: ", i);
        Enqueue(q, num);
    }
    printf("\nDEQUEUEING...\n");
    for(int i = 0; i < 12; ++i)
    {
        printf("[%d]: ", i);
        int res = Dequeue(q);
        if((arr[i] != res) && (res != -1))
        {
            fprintf(stderr, "\nERROR: Enqueue'd value doesn't match dequeued value\n");
        }
    }

    //Enqueue more items the queue can hold
    printf("\n\n5. Exceed maximum capacity test\n");
    for(int i = 0; i < 15; ++i)
    {
        printf("[%d]: ", i);
        Enqueue(q, rand() % 25);
    }
    printf("\nDEQUEUEING...\n");
    for(int i = 0; i < 10; ++i)
    {
        printf("[%d]: ", i);
        if(Dequeue(q) == -1)
            fprintf(stderr, "ERROR: Dequeue returned -1\n");
    }
    printf("Done with Dequeue Tests...\n");
    clean_queue(q);
}

int main(int argc, char *argv[])
{
    printf("Queue Test...\n");
    struct Queue *q = create_queue(10);


    printf("Enque Tests:\n");
    Enqueue(q, 3);
    Enqueue(q, 5);
    Enqueue(q, 7);

    printf("Dequeue Tests: ");
    printf("%d ", Dequeue(q));
    printf("%d ", Dequeue(q));
    printf("%d ", Dequeue(q));
    printf("\nDone with small tests...\n");
    clean_queue(q);


    test_enqueue();
    test_dequeue();
    return 1;
}
