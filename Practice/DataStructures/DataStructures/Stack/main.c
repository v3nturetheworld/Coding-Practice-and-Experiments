#include "stack.h"


void test_push()
{
    struct stack *s = create_stack(10);
    printf("\n\nStress Testing PUSH Stack!\n");
    for(int i = 0; i < 12; ++i)
    {
        push(s, i);
    }

    clean_stack(s);
    printf("Done stress testing PUSH stack\n\n");

}

void test_pop()
{
    struct stack *s = create_stack(10);
    printf("\n\nStress Testing POP Stack!\n");
    for(int i = 0; i < 10; ++i)
    {
        push(s, rand() % 25);
    }
    printf("[TEST][POP]: ");
    for(int i = 0; i < 5; ++i)
    {
        printf("%d ", pop(s));
    }
    printf("\n[TEST][PUSH]:\n");
    for(int i = 0; i < 10; ++i)
    {
        push(s, rand() % 25);
    }
    
    printf("[TEST][POP]: ");
    for(int i = 0; i < 12; ++i)
    {
        printf("%d ", pop(s));
    }
    
    push(s, 4);
    printf("POP[4]: %d\n", pop(s));
    pop(s);
    
    push(s, 3);
    push(s, 5);
    printf("[TEST][POP]: ");
    for(int i = 0; i < 5; ++i)
    {
        printf("%d ", pop(s));
    }
    printf("\nDone Stress Testing Pop!\n");
    clean_stack(s);
    
}


int main(int argc, char* argv[])
{
    printf("Stack Test Started!\n");
    struct stack *s = create_stack(10);
    
    printf("[isempty test]:\n");
    isempty(s);
    
    printf("[push tests]:\n");
    push(s, 2);
    push(s, 5);
    push(s, 1);
    printf("[pop tests]:\n");
    
    int t_0 = pop(s);
    printf("[pop test][1]: %d\n",t_0);
    int t_1 = pop(s);
    printf("[pop test][2]: %d\n",t_1);
   
    printf("Cleaning stack...");
    clean_stack(s);


    test_push();
    test_pop();
    return 0;
}
