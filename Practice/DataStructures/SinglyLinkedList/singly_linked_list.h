//Singly Linked List implementation
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


struct node
{
    struct node *next;
    int value;
};

struct node *create_singly_linked_list();
bool insert(struct node *node_ptr, int value);
bool remove_node(struct node *node_ptr, int value);
struct node *search(struct node *head_node_ptr, int value);
bool clean_linked_list(struct node *head);
void print_list(struct node *head);
bool is_loop(struct node *head);
