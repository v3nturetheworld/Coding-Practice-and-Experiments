#include "singly_linked_list.h"

#define RESULT(x) (x == 1) ? "True" : "False"
void test_insert()
{
    printf("\nTesting Insertions...\n");
    struct node *SLL = create_singly_linked_list();
    int arr[12];
    for(int i = 0; i < 12; ++i)
    {
        int num = rand() % 25;
        arr[i] = num;
        insert(SLL, num);
    }
    printf("Done Testing Insertions!\n");
    print_list(SLL);
    printf("Data Generated: ");
    for(int i = 0; i < 12; ++i)
        printf("%d ", arr[i]);
    printf("\n");
    clean_linked_list(SLL);
}

void test_search()
{
    printf("\nTesting Search...\n");
    struct node *head = create_singly_linked_list();
    insert(head, 3);
    insert(head, 5);
    insert(head, 2);
    insert(head, 9);
    insert(head, 1);
    print_list(head);

    search(head, 2);
    search(head, 11);
    search(head, 3);
    remove_node(head, 2);
    search(head, 2);
    insert(head, 2);
    search(head, 2);
    print_list(head);
    printf("Done with search test!\n");
    clean_linked_list(head);
}
//TODO:
//1. Check if I can return a struct without malloc for loop detection.
//// struct loop_res { bool is_loop; struct node *loop_location; };
//2. Write a function that removes the loop from the linked list
//3. Test
void add_loop(struct node *LL)
{
    printf("Adding a loop at the End...\n");
    struct node *head = LL;
    int i = 0;
    printf("Iterating...");
    while(head->next != NULL) 
    {
        head = head->next;
        printf("%d ", i++);
    }
    printf("\n");
    head->next = LL;
    printf("Loop inserted into the list so that the tail links to head\n");
}
void test_loop_check(int num_nodes)
{
    printf("\n\nTesting Loop Check\n");
    struct node *LL = create_singly_linked_list();
    for(int i = 0; i < num_nodes; ++i)
        insert(LL, rand() % 50);
    print_list(LL);
    printf("\n\n");
    bool res = is_loop(LL);
    printf("1. Was a loop detected? %s\n", RESULT(res));
    add_loop(LL); 
    res = is_loop(LL);
    printf("2. Was a loop detected? %s\n", RESULT(res));

    printf("Done with Loop Test\n");
    clean_linked_list(LL);
}

int main(int argc, char *argv[])
{
    printf("Testing Singly Linked List...\n");
    struct node *SLL = create_singly_linked_list();
    
    print_list(SLL);
    clean_linked_list(SLL);

    test_insert();
    test_search();
    test_loop_check(5);
    return 1;
}
