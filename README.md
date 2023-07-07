# Linked List Functions

This README provides an overview of the functions available in the provided code for a linked list implementation. These functions allow you to manipulate and perform operations on a linked list data structure.

## Table of Contents
- [Introduction](#introduction)
- [Types](#types)
- [Function List](#function-list)
- [Usage](#usage)
- [Contributing](#contributing)
- [License](#license)

## Introduction
The provided code implements a linked list data structure in C. It includes various functions for performing operations on the linked list such as inserting elements, updating values, finding elements, removing elements, copying lists, concatenating lists, sorting, reversing, and more.

## Types
The following types are defined in the code:

```c
typedef struct Cell {
    double value;
    struct Cell* Next;
} Cell;

typedef struct LinkedList {
    struct Cell* Head;
} LinkedList;
```

## Cell
A struct representing a single node in the linked list, containing a value and a pointer to the Next node.

## LinkedList
A struct representing the linked list itself, containing a pointer to the Head node.

## Function List

| Return Type | Function Name                                                            | Parameters                                                    | Description                                                  |
|-------------|--------------------------------------------------------------------------|---------------------------------------------------------------|--------------------------------------------------------------|
| `Cell*`     | `NEW_CELL`                                                               | `double value`                                                | Creates a new cell with the given value.                     |
| `int*`      | `linkedlist_GET_SIZE`                                                    | `struct LinkedList* self`                                     | Returns the number of elements in the linked list.           |
| `double*`   | `linkedlist_GET_FIRST`                                                   | `struct LinkedList* self`                                     | Returns a pointer to the value of the first element.         |
| `double*`   | `linkedlist_GET_LAST`                                                    | `struct LinkedList* self`                                     | Returns a pointer to the value of the last element.          |
| `double*`   | `linkedlist_GET_AT`                                                      | `struct LinkedList* self, int position`                        | Returns a pointer to the value at the specified position.    |
| `void`      | `linkedlist_INSERT`                                                      | `struct LinkedList* self, int position, double value`         | Inserts a new element at the specified position.             |
| `void`      | `linkedlist_UPDATE`                                                      | `struct LinkedList* self, int position, double value`         | Updates the value at the specified position.                 |
| `int*`      | `linkedlist_FIND`                                                        | `struct LinkedList* self, double search_value`                | Finds the position of the first occurrence of a value.       |
| `int*`      | `linkedlist_COUNT`                                                       | `struct LinkedList* self, double search_value`                | Counts the number of occurrences of a value.                 |
| `void`      | `linkedlist_REMOVE_FIRST`                                                | `struct LinkedList* self`                                     | Removes the first element.                                   |
| `void`      | `linkedlist_REMOVE_LAST`                                                 | `struct LinkedList* self`                                     | Removes the last element.                                    |
| `LinkedList`| `linkedlist_COPY`                                                        | `struct LinkedList* self`                                     | Creates a copy of the linked list.                           |
| `LinkedList`| `linkedlist_CONCATENATE`                                                 | `struct LinkedList* list1, struct LinkedList* list2`          | Concatenates two linked lists.                               |
| `void`      | `linkedlist_REMOVE_AT`                                                   | `struct LinkedList* self, int position`                        | Removes the element at the specified position.               |
| `void`      | `linkedlist_VALUE_DELETE`                                                | `struct LinkedList* self, double search_value`                | Removes all occurrences of a value.                          |
| `bool`      | `linkedlist_CONTAINS`                                                    | `struct LinkedList* self, double search_value`                | Checks if the linked list contains a value.                  |
| `double*`   | `linkedlist_SUM`                                                         | `struct LinkedList* self`                                     | Calculates the sum of all elements.                          |
| `double*`   | `linkedlist_AVG`                                                         | `struct LinkedList* self`                                     | Calculates the average of all elements.                      |
| `void`      | `linkedlist_BUBBLESORT`                                                  | `struct LinkedList* self`                                     | Sorts the elements in ascending order using bubble sort.     |
| `void`      | `linkedlist_REVERSE`                                                     | `struct LinkedList* self`                                     | Reverses the order of elements.                              |
| `void`      | `linkedlist_ADD`                                                         | `struct LinkedList* self, double value`                       | Adds a new element to the end of the linked list.            |

For detailed descriptions of each function, refer to the code comments.


## Usage

To use these linked list functions, you need to have a LinkedList object. You can create a new linked list using the appropriate initialization function.

Here's an example of creating a new linked list, adding elements, and performing operations:


```c
LinkedList list;
list.Head = NULL;

// Add elements to the list
linkedlist_ADD(&list, 5.0);
linkedlist_ADD(&list, 10.0);
linkedlist_ADD(&list, 15.0);

// Get the size of the list
int* size = linkedlist_GET_SIZE(&list);
printf("Size of the list: %d\n", *size);

// Get the first element
double* first = linkedlist_GET_FIRST(&list);
printf("First element: %.2f\n", *first);

// Get the last element
double* last = linkedlist_GET_LAST(&list);
printf("Last element: %.2f\n", *last);

// Get the elementat a specific position
double* element = linkedlist_GET_AT(&list, 1);
if (element != NULL) {
    printf("Element at position 1: %.2f\n", *element);
} else {
    printf("Invalid position\n");
}

// Update the value at position 1
linkedlist_UPDATE(&list, 1, 20.0);

// Find the position of a value
int* position = linkedlist_FIND(&list, 15.0);
if (position != NULL) {
    printf("Position of value 15.0: %d\n", *position);
} else {
    printf("Value not found\n");
}

// Remove the first element
linkedlist_REMOVE_FIRST(&list);

// Remove the last element
linkedlist_REMOVE_LAST(&list);

// Copy the list
LinkedList newList = linkedlist_COPY(&list);

// Concatenate two lists
LinkedList list1;
LinkedList list2;
LinkedList concatenatedList = linkedlist_CONCATENATE(&list1, &list2);

// Remove an element at a specific position
linkedlist_REMOVE_AT(&list, 1);

// Delete the first occurrence of a value
linkedlist_VALUE_DELETE(&list, 10.0);

// Check if the list contains a value
bool contains = linkedlist_CONTAINS(&list, 15.0);
if (contains) {
    printf("List contains value 15.0\n");
} else {
    printf("List does not contain value 15.0\n");
}

// Calculate the sum of all elements
double* sum = linkedlist_SUM(&list);
printf("Sum of all elements: %.2f\n", *sum);

// Calculate the average of all elements
double* average = linkedlist_AVG(&list);
printf("Average of all elements: %.2f\n", *average);

// Sort the list
linkedlist_BUBBLESORT(&list);

// Reverse the list
linkedlist_REVERSE(&list);

// Add an element to the beginning of the list
linkedlist_ADD(&list, 25.0);

// Display the elements of the list
linkedlist_DISPLAY(&list);

// Clear the list
linkedlist_CLEAR(&list);

// Create a new empty linked list
LinkedList newLinkedList = new_linkedList();
```

Feel free to use these functions and modify them as needed to suit your specific requirements for a linked list implementation.

## Contributing
Contributions are welcome! If you find any issues or have suggestions for improvements, please feel free to contribute to this project.