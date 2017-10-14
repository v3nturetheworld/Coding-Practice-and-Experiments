#include "singly_linked_list.h"



struct node *create_singly_linked_list()
{
    struct node *head = NULL;
    head = (struct node *)malloc(sizeof(struct node));
    if(head == NULL)
    {
        fprintf(stderr, "ERROR: Memory for the linked list could not be allocated!\n");
        exit(-1);
    }
    head->next = NULL;
    head->value = 0;
    return head;
}
//TODO: Optimise insert so it takes O(1) time
bool insert(struct node *node_ptr, int value)
{
    if(!node_ptr)
    {
        fprintf(stderr, "ERROR [Insert]: The node provided is NULL\n");
        return false;
    }
 
    if(node_ptr->value == 0)
    {
        printf("First Insertion\n");
        node_ptr->value = value;
        return true;
    }
    //All normal situations
    //printf("Normal Insertion...Current node_ptr location: %p\n", node_ptr);
    while(node_ptr->next != NULL)
    {
        //printf("Still looking...\n");
        node_ptr = node_ptr->next;
    }
    node_ptr->next = (struct node *)malloc(sizeof(struct node));
    if(node_ptr->next == NULL)
    {
        fprintf(stderr, "ERROR [insert]: Could not allocate memory for more nodes\n");
        return false;
    }
    node_ptr->next->value = value;
    node_ptr->next->next = NULL;
    //node_ptr->next = temp;
    printf("insert: Inserted value %d into the linked list at node with memory location %p.\n", value, (void *)node_ptr->next);
    return true;
}

bool remove_node(struct node *node_ptr, int value)
{
    if(!node_ptr)
    {
        fprintf(stderr, "ERROR [Remove]: The node provided is NULL\n");
        return false;
    }
    
    if(node_ptr->value == value)
    {
        if(node_ptr->next != NULL)
        {
            struct node *temp = node_ptr->next;
            node_ptr->value = temp->value;
            node_ptr->next = temp->next;
            free(temp);
        }
        else
            free(node_ptr);
    }
    else
    {
        struct node *search_res = search(node_ptr, value);
        if(search_res)
            remove_node(search_res, value);
        else
        {
            fprintf(stderr, "ERROR [remove]: No node in the linked list containing the value %d\n", value);
            return false;
        }
    }

    printf("The node containing the value %d was removed from the list!\n", value);

    return true;
}

struct node *search(struct node *head_node_ptr, int value)
{
    if(!head_node_ptr)
    {
        fprintf(stderr, "ERROR [Search]: Could not find node with value %d because the node provided is NULL\n", value);
        return NULL;
    }
    if(head_node_ptr->value == value)
    {
        printf("Found node containing %d at location %p\n", value, head_node_ptr);
        return head_node_ptr;
    }
    return search(head_node_ptr->next, value);
}



bool clean_linked_list(struct node *head)
{
    if(head == NULL) return false;
    int i = 0;
    while(head != NULL)
    {
        struct node *temp = head;
        head = head->next;
        free(temp);
        ++i;
    }
    printf("[%d items freed]: Memory used for linked list has been cleaned\n", i);
    return true;
}


void print_list(struct node *head)
{
    printf("Current Linked List: ");
    struct node *curr_node = head;
    while(curr_node != NULL)
    {
        printf("%d ", curr_node->value);
        curr_node = curr_node->next;
    }
    printf("\n");
}


bool is_loop(struct node *head)
{
    //Base cases:
    //1. The list is empty
    //2. The list contains 1 Node
    //3. The list contains 1 Node and it points to itself
    if(!head){ printf("[BC1]: An empty list was passed.\n"); return false; }
    if(!head->next) { printf("[BC2]: The List contains 1 Node, and the node it points to is NULL.\n"); return false;}
    if(head->next == head) { printf("[BC3]: The List Contains 1 Node and it points to itself.\n"); return true; }

    struct node *turtle, *hare; //Normal iterative pointer and runner pointer
    turtle = hare = head;
    int counter = 0;
    do
    {
        //printf("[%d]: 1. Turtle = %d, Hare = %d\n", counter, turtle->value, hare->value);
        turtle = turtle->next;
        if(!turtle)
        {
            printf("[EOL]: TURTLE is NULL, we've reached the end of the list.\n");
            break;
        }
        //printf("[%d]: 2. Turtle = %d, Hare = %d\n", counter, turtle->value, hare->value);
        if(!(hare->next) || !(hare->next->next))
        {
            //printf("HARE is NULL...setting it back to locate of turtle\n");
            hare = turtle;
        }
        else
        {
            hare = hare->next->next;
            if(turtle == hare)
            {
                printf("Loop Detected!\n");
                return true;
            }
            //printf("[%d]: 3. Turtle = %d, Hare = %d\n", counter, turtle->value, hare->value);
        }
        //printf("[%d]: Turtle = %d, Hare = %d\n", counter++, turtle->value, hare->value);
    } while(hare != NULL);

    return false;
}
