// single-linked list
#include <stdio.h>
#include <stdlib.h>


// structures
struct ll_node{
    int value;
    struct ll_node* next;
};
typedef struct ll_node ll_node;
typedef struct {
    ll_node* head;
    int size;
} LinkedList;


// methods:

// finds a certain value in the linked list and returns its index
// if no node with such index exists, returns -1
int find_value(LinkedList* ll, int value) {
    ll_node* current = ll->head;
    int current_index = 0;
    while (current != NULL) {
        if (current->value == value) {
            return current_index;
        }
        current = current->next;
        ++current_index;
    }
    return -1;
}

// initialize an empty linked list
void ll_init_empty(LinkedList *ll){
    ll->head = NULL;
    ll->size = 0;
}

// prints the contents of the linked list to stdout
void ll_print_list(LinkedList *ll) {
    ll_node* current = ll->head;
    if (current == NULL) {
        printf("[]\n");
    }
    else {
        printf("[");
        while (current->next != NULL) {
            printf("%d, ", current->value);
            current = current->next;
        }
        printf("%d", current->value);
        printf("]\n");
    }
}

// adds the new node with a given value to the linked list
// so that its index in a new list is equal to a given index
void ll_insert_node(LinkedList *ll, int index, int value) {
    if (index <= ll->size && index >= 0) {

        ll_node* new = (ll_node*) malloc(sizeof(ll_node));
        new->value = value;
        new->next = NULL;

        if (ll->size == 0) {
            ll->head = new;
        }
        else if (index == 0) {
            new->next = ll->head;
            ll->head = new;
        }
        else if (index == ll->size) {
            ll_node* current = ll->head;
            while (current->next != NULL) {
                current = current->next;
            }
            current->next = new;
        }
        else {
            ll_node* current = ll->head;
            int current_index = 0;
            while (current_index != index-1) {
                current = current->next;
                ++current_index;
            }
            new->next = current->next;
            current->next = new;
        }
        ++(ll->size);
    }
    else {
        printf("invalid index for insertion!\n");
    }
}

// adds the new node with a given value to the linked list
// so that its index in a new list is equal to an index after the given one
void ll_insert_node_after_index(LinkedList *ll, int index, int value) {
    if (index >= 0 && index < ll->size) {
        ll_insert_node(ll, index + 1, value);
    }
    else {
        printf("invalid index for insertion!\n");
    }
}

// adds the new node with a given value to the linked list
// so that it is inserted after the first element with the given value
void ll_insert_node_after_value(LinkedList *ll, int value_to_find, int value_to_insert) {
    int index = find_value(ll, value_to_find);
    if (index >= 0 && index < ll->size) {
        ll_insert_node(ll, index + 1, value_to_insert);
    }
    else {
        printf("element with such value doesn't exist!\n");
    }
}

// removes the node with the given index from the linked list
void ll_delete_node_by_index(LinkedList* ll, int index) {
    if (index >= 0 && index < ll->size) {
        if (index == 0) {
            // delete tail
            ll_node* temp = ll->head;
            ll->head = ll->head->next;
            free(temp);
        }
        else if (index == ll->size - 1) {
            // delete head
            if (ll->size == 1) {
                // from a list with just one element
                ll->head = NULL;
            }
            else {
                // from a list with more than 1 element
                ll_node *current = ll->head;
                while (current->next->next != NULL) {
                    current = current->next;
                }
                free(current->next);
                current->next = NULL;
            }
        }
        else {
            // delete from middle
            ll_node* current = ll->head;
            int current_index = 0;
            while (current_index != index-1) {
                current = current->next;
                ++current_index;
            }
            ll_node* temp = current->next;
            current->next = current->next->next;
            free(temp);
        }
        --(ll->size);
    }
    else {
        printf("the given index is invalid!\n");
    }
}

// removes the node with the given value from the linked list
void ll_delete_node_by_value(LinkedList *ll, int value) {
    int index = find_value(ll, value);
    ll_delete_node_by_index(ll, index);
}

// some testing
int main(void) {

    LinkedList ll;
    ll_init_empty(&ll);

    printf("Inserting at the beginning:\n");
    for (int i = 0; i < 10; ++i) {
        ll_print_list(&ll);
        ll_insert_node(&ll, 0, i);
    }
    ll_print_list(&ll);

    printf("Clearing the list(elements 0-9 are removed):\n");
    for (int i = 0; i < 10; ++i) {
        ll_print_list(&ll);
        ll_delete_node_by_value(&ll, i);
    }

    printf("Inserting at the end:\n");
    for (int i = 0; i < 10; ++i) {
        ll_print_list(&ll);
        ll_insert_node(&ll, i, i);
    }
    ll_print_list(&ll);

    printf("Clearing the list (elements 0-9 are removed):\n");
    for (int i = 0; i < 10; ++i) {
        ll_print_list(&ll);
        ll_delete_node_by_value(&ll, i);
    }

    printf("Inserting in the middle:\n");
    for (int i = 0; i < 10; ++i) {
        ll_print_list(&ll);
        ll_insert_node(&ll, ll.size / 2, i);
    }
    ll_print_list(&ll);

    printf("Clearing the list (elements 9-0 are removed, so that deleting from the middle is tested):\n");
    for (int i = 9; i > -1; --i) {
        ll_print_list(&ll);
        ll_delete_node_by_value(&ll, i);
    }
    ll_print_list(&ll);

    ll_insert_node(&ll, 0, 0);

    printf("Inserting in the middle (this time with a function that inserts after a certain index):\n");
    for (int i = 1; i < 10; ++i) {
        ll_print_list(&ll);
        ll_insert_node_after_index(&ll, ll.size / 2, i);
    }
    ll_print_list(&ll);

    printf("Clearing the list (elements 0-9 are removed):\n");
    for (int i = 0; i < 10; ++i) {
        ll_print_list(&ll);
        ll_delete_node_by_value(&ll, i);
    }
    ll_print_list(&ll);

    ll_insert_node(&ll, 0, 0);
    printf("Inserting in the middle (this time with a function that inserts after a certain value):\n");
    for (int i = 1; i < 10; ++i) {
        ll_print_list(&ll);
        ll_insert_node_after_value(&ll, ll.size / 2, i);
    }
    ll_print_list(&ll);

    printf("Clearing the list (elements 0-9 are removed):\n");
    for (int i = 0; i < 10; ++i) {
        ll_print_list(&ll);
        ll_delete_node_by_value(&ll, i);
    }
    ll_print_list(&ll);


    return 0;
}
