#include <stdio.h>
#include <stdlib.h>

typedef enum { false = 0, true = !false } bool;

typedef struct Cell {
    double value;
    struct Cell* Next;
} Cell;

typedef struct LinkedList {
    struct Cell* Head;
} LinkedList;

static Cell* NEW_CELL(double value) {
    Cell* newCell = malloc(sizeof(Cell));
    newCell->value = value;
    newCell->Next = NULL;
    return newCell;
}

LinkedList new_linkedList() {
    LinkedList _LINKEDLinkedList_;
    _LINKEDLinkedList_.Head = NULL;
    return _LINKEDLinkedList_;
}

int linkedlist_GET_SIZE(struct LinkedList* self) {
    if(self->Head == NULL)
        return 0;

    int SIZE = 0;
    Cell* current = self->Head;
    while (current != NULL) {
        SIZE++;
        Cell* next = current->Next;
        current = next;
    }

    return SIZE;
}

void linkedlist_ADD(struct LinkedList* self, double value) {
    if (self->Head == NULL) {
        self->Head = NEW_CELL(value);
    } else {
        Cell* newCell = NEW_CELL(value);
        newCell->Next = self->Head;
        self->Head = newCell;
    }
}

void linkedlist_APPEND(struct LinkedList* self, double value) {
    if (self->Head == NULL) {
        self->Head = NEW_CELL(value);
    } else {
        Cell* current = self->Head;
        while (current->Next != NULL) {
            current = current->Next;
        }
        current->Next = NEW_CELL(value);
    }
}

double* linkedlist_GET_FIRST(struct LinkedList* self) {
    if(self->Head == NULL || &(self->Head->value) == NULL)
        return NULL;
    return &(self->Head->value);
}

double* linkedlist_GET_LAST(struct LinkedList* self) {
    Cell* current = self->Head;
    while (current != NULL) {
        if(current->Next == NULL)
            return &(current->value);
        Cell* next = current->Next;
        current = next;
    }
    return NULL;
}

double* linkedlist_GET_AT(struct LinkedList* self, int position) {
    if (self == NULL || self->Head == NULL) {
        return NULL;
    }

    int INDEX = 0;
    Cell* current = self->Head;
    while (current != NULL) {
        if(INDEX == position){
            return &(current->value);
        }
        Cell* next = current->Next;
        current = next;
        INDEX++;
    }
    return NULL;
}

void linkedlist_INSERT(struct LinkedList* self, int position, double value) {
    if (self == NULL || self->Head == NULL) {
        return;
    }

    if (position == 0) {
        Cell* temp = self->Head;
        self->Head = NEW_CELL(value);
        self->Head->Next = temp;
        return;
    }

    Cell* current = self->Head;
    int index = 0;

    while (current != NULL) {
        if (index == position - 1) {
            Cell* newCell = NEW_CELL(value);
            Cell* next = current->Next;
            current->Next = newCell;
            newCell->Next = next;
            return;
        }

        current = current->Next;
        index++;
    }
}

void linkedlist_UPDATE(struct LinkedList* self, int position, double value) {
    if (self == NULL || self->Head == NULL) {
        return;
    }

    int INDEX = 0;
    Cell* current = self->Head;
    while (current != NULL) {
        if(INDEX == position){
            current->value = value;
            return;
        }
        Cell* next = current->Next;
        current = next;
        INDEX++;
    }
}

int linkedlist_FIND(struct LinkedList* self, double search_value) {
    if (self == NULL || self->Head == NULL) {
        return -1;
    }
    
    int INDEX = 0;
    Cell* current = self->Head;
    while (current != NULL) {
        if(current->value == search_value){
            return INDEX;
        }
        Cell* next = current->Next;
        current = next;
        INDEX++;
    }
    return -1;
}

int linkedlist_COUNT(struct LinkedList* self, double search_value) {
    int ITEMS = 0;
    Cell* current = self->Head;
    while (current != NULL) {
        ITEMS++;
        Cell* next = current->Next;
        current = next;
    }
    return ITEMS;
}

void linkedlist_REMOVE_FIRST(struct LinkedList* self) {
    if (self == NULL || self->Head == NULL) {
        return;
    }
    Cell* temp_next = self->Head->Next;
    free(self->Head);
    self->Head = temp_next;
}

void linkedlist_REMOVE_LAST(struct LinkedList* self) {
    if (self == NULL || self->Head == NULL) {
        return;
    }

    if (self->Head->Next == NULL) {
        free(self->Head);
        self->Head = NULL;
        return;
    }

    Cell* current = self->Head;
    Cell* prev = NULL;

    while (current->Next != NULL) {
        prev = current;
        current = current->Next;
    }

    prev->Next = NULL;
    free(current);
}

LinkedList linkedlist_COPY(struct LinkedList* self) {
    LinkedList newLinkedList = new_linkedList();

    Cell* current = self->Head;
    while (current != NULL) {
        Cell* next = current->Next;
        linkedlist_APPEND(&newLinkedList,current->value);
        current = next;
    }

    return newLinkedList;
}

LinkedList linkedlist_CONCATENATE(struct LinkedList* list1, struct LinkedList* list2) {
    LinkedList concatenatedList;

    if (list1 == NULL || list1->Head == NULL) {
        concatenatedList = *list2;
        return concatenatedList;
    }

    if (list2 == NULL || list2->Head == NULL) {
        concatenatedList = *list1;
        return concatenatedList;
    }

    Cell* lastCell = list1->Head;
    while (lastCell->Next != NULL) {
        lastCell = lastCell->Next;
    }

    lastCell->Next = list2->Head;

    concatenatedList = *list1;
    return concatenatedList;
}

void linkedlist_REMOVE_AT(struct LinkedList* self, int position) {
    if (self == NULL || self->Head == NULL) {
        return;
    }

    if (position == 0) {
        Cell* temp_next = self->Head->Next;
        free(self->Head);
        self->Head = temp_next;
        return;
    }

    Cell* current = self->Head;
    Cell* prev = NULL;
    int count = 0;

    while (current != NULL && count < position) {
        prev = current;
        current = current->Next;
        count++;
    }

    if (current == NULL) {
        return;
    }

    prev->Next = current->Next;
    free(current);
}

void linkedlist_VALUE_DELETE(struct LinkedList* self, double search_value) {
    if (self == NULL || self->Head == NULL) {
        return;
    }

    if (self->Head->value == search_value) {
        Cell* temp_next = self->Head->Next;
        free(self->Head);
        self->Head = temp_next;
        return;
    }

    Cell* current = self->Head->Next;
    Cell* prev = self->Head;

    while (current != NULL) {
        if (current->value == search_value) {
            if (current->Next == NULL) {
                free(current);
                prev->Next = NULL;
                return;
            }
            else {
                Cell* temp_next = current->Next;
                free(current);
                prev->Next = temp_next;
                return;
            }
        }

        prev = current;
        current = current->Next;
    }
}

bool linkedlist_CONTAINS(struct LinkedList* self, double search_value){
    Cell* current = self->Head;
    while (current != NULL) {
        if(current->value == search_value)
            return true;
        Cell* next = current->Next;
        current = next;
    }
    return false;
}

double linkedlist_SUM(struct LinkedList* self){
    double SUM = 0;
    Cell* current = self->Head;
    while (current != NULL) {
        SUM = SUM + current->value;
        Cell* next = current->Next;
        current = next;
    }
    return SUM;
}

double linkedlist_AVG(struct LinkedList* self){
    double SUM = 0; int ITEMS = 0;
    Cell* current = self->Head;
    while (current != NULL) {
        SUM = SUM + current->value;
        ITEMS ++;
        Cell* next = current->Next;
        current = next;
    }
    SUM = SUM / ITEMS;
    return SUM;
}

void linkedlist_BUBBLESORT(struct LinkedList* self){
    Cell * SortSeeker = self->Head;
    int Sorted = 1;

    while (Sorted == 1){
        Sorted = 0;
        while (SortSeeker->Next != NULL)
        {
            if(SortSeeker->value > SortSeeker->Next->value ? true : false) {
                double TEMP_SIZE = SortSeeker->value;
                SortSeeker->value = SortSeeker->Next->value;
                SortSeeker->Next->value = TEMP_SIZE;
                Sorted = 1;
            }
            SortSeeker = SortSeeker->Next;
        }
        SortSeeker = self->Head;
    }
}

void linkedlist_REVERSE(struct LinkedList* self){
    if(self->Head == NULL || self->Head->Next == NULL)
        return;
    
    Cell * CURRENT = self->Head;
    Cell * NEXT    = NULL;
    Cell * PREV    = NULL;

    while (CURRENT != NULL){
        NEXT = CURRENT->Next;
        CURRENT->Next = PREV;
        PREV = CURRENT;
        CURRENT = NEXT;
    }
    self->Head = PREV;
}

void linkedlist_DISPLAY(struct LinkedList* self) {
    Cell* current = self->Head;
    while (current != NULL) {
        printf("[%.6g]", current->value);
        current = current->Next;
    }
    printf("\n");
}

void linkedlist_CLEAR(LinkedList* self) {
    Cell* current = self->Head;
    while (current != NULL) {
        Cell* next = current->Next;
        free(current);
        current = next;
    }
    self->Head = NULL;
}
