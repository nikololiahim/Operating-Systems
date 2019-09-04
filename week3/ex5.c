#include <stdio.h>
#include <stdlib.h>


// dll stands for doubly linked list
typedef struct dlln {
    struct dlln* prev;
    struct dlln* next;
    int value;
} dll_node;

typedef struct {
    int size;
    dll_node* head;
    dll_node* tail;
} dll;


//methods:

// finds a certain value in the linked list and returns its index
// if no node with such index exists, returns -1
int find_value(dll* list, int value) {
    dll_node* current = list->tail;
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

// initialize an empty dll
void dll_init_empty(dll* list) {
    list->size = 0;
    list->head = NULL;
    list->tail = NULL;
}

// prints the contents of the dll to stdout
void dll_print_list(dll* list) {
    dll_node* current = list->tail;
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
void dll_insert_node_at_index(dll* l, int index, int value) {
    if (index >= 0 && index <= l->size) {

        dll_node* new = (dll_node*) malloc(sizeof(dll_node));
        new->value = value;
        new->next = NULL;
        new->prev = NULL;

        if (l->size == 0) {
            l->head = l->tail = new;
        }
        else if (index == 0) {
            new->next = l->tail;
            l->tail->prev = new;
            l->tail = new;
        }
        else if (index == l->size) {
            new->prev = l->head;
            l->head->next = new;
            l->head = new;
        }
        else {
            dll_node* current;
            int current_index;
            if (index < l->size/2) {
                current = l->tail;
                current_index = 0;
                while (current_index != index) {
                    current = current->next;
                    ++current_index;
                }
            }
            else {
                current = l->head;
                current_index = l->size-1;
                while (current_index != index) {
                    current = current->prev;
                    --current_index;
                }
            }
            new->next = current;
            new->prev = current->prev;
            current->prev->next = new;
            current->prev = new;
        }
        ++(l->size);
    }
    else {
        printf("index is out of range!");
    }
}

// adds the new node with a given value to the dll
// so that it is inserted after the first element with the given value
void dll_insert_node_after_value(dll* l, int value_to_find, int value_to_insert) {
    int index = find_value(l, value_to_find);
    if (index >= 0) {
        dll_insert_node_at_index(l, index + 1, value_to_insert);
    }
    else {
        printf("node with such value doesn't exist!\n");
    }
}

void dll_delete_node_by_value(dll* l, int value) {
    int index = find_value(l, value);
    if (index >= 0 && index < l->size) {
        if (l->size == 1) {
            l->head = l->tail = NULL;
        }
        else if (index == 0) {
            dll_node* temp = l->tail;
            l->tail->next->prev = NULL;
            l->tail = l->tail->next;
            free(temp);
        }
        else if (index == l->size - 1) {
            dll_node* temp = l->head;
            l->head->prev->next = NULL;
            l->head = l->head->prev;
            free(temp);
        }
        else {
            dll_node* current;
            int current_index;
            if (index < l->size/2) {
                current = l->tail;
                current_index = 0;
                while (current_index != index) {
                    current = current->next;
                    ++current_index;
                }
            }
            else {
                current = l->head;
                current_index = l->size-1;
                while (current_index != index) {
                    current = current->prev;
                    --current_index;
                }
            }
            current->prev->next = current->next;
            current->next->prev = current->prev;
            free(current);
        }
        --(l->size);
    }
    else {
        printf("the linked list doesn't contain such value!\n");
    }
}
int main() {
    dll ll;
    dll_init_empty(&ll);

    dll_insert_node_at_index(&ll, 0, 0);

    printf("Inserting at the beginning:\n");
    for (int i = 0; i < 10; ++i) {
        dll_print_list(&ll);
        dll_insert_node_after_value(&ll, i, i+1);
    }
    dll_print_list(&ll);

    printf("Deleting from the beginning:\n");
    for (int i = 0; i < 10; ++i) {
        dll_print_list(&ll);
        dll_delete_node_by_value(&ll, i);
    }
    dll_print_list(&ll);

    dll_delete_node_by_value(&ll, 10);
    dll_insert_node_at_index(&ll, 0, 0);

    printf("Inserting at the end:\n");
    for (int i = 0; i < 10; ++i) {
        dll_print_list(&ll);
        dll_insert_node_after_value(&ll, i, i+1);
    }
    dll_print_list(&ll);


    printf("Deleting from the end:\n");
    for (int i = 10; i > -1; --i) {
        dll_print_list(&ll);
        dll_delete_node_by_value(&ll, i);
    }
    dll_print_list(&ll);

    dll_insert_node_at_index(&ll, 0, 0);

    printf("Inserting at the end:\n");
    for (int i = 0; i < 10; ++i) {
        dll_print_list(&ll);
        dll_insert_node_after_value(&ll, i, i+1);
    }

    printf("Deleting from the middle:\n");
    dll_print_list(&ll);
    dll_delete_node_by_value(&ll, 5);
    dll_print_list(&ll);
    dll_delete_node_by_value(&ll, 6);
    dll_print_list(&ll);
    dll_delete_node_by_value(&ll, 4);
    dll_print_list(&ll);
    dll_delete_node_by_value(&ll, 7);
    dll_print_list(&ll);
    dll_delete_node_by_value(&ll, 3);
    dll_print_list(&ll);
    dll_delete_node_by_value(&ll, 8);
    dll_print_list(&ll);
    dll_delete_node_by_value(&ll, 2);
    dll_print_list(&ll);
    dll_delete_node_by_value(&ll, 9);
    dll_print_list(&ll);
    dll_delete_node_by_value(&ll, 1);
    dll_print_list(&ll);
    dll_delete_node_by_value(&ll, 10);
    dll_print_list(&ll);
    dll_delete_node_by_value(&ll, 0);
    dll_print_list(&ll);

    return 0;
}