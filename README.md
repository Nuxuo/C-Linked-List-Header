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

| Return Type | Function Name           | Parameters                           | Description                                        | Time Complexity |
|-------------|-------------------------|--------------------------------------|----------------------------------------------------|-----------------|
| `int*`      | `linkedlist_GET_SIZE`   | `struct LinkedList* self`            | Returns the number of elements in the linked list. | O(n)            |
| `void*`   | `linkedlist_GET_FIRST`  | `struct LinkedList* self`            | Returns a pointer to the value of the first element. | O(1)           |
| `void*`   | `linkedlist_GET_LAST`   | `struct LinkedList* self`            | Returns a pointer to the value of the last element. | O(n)            |
| `void*`   | `linkedlist_GET_AT`     | `struct LinkedList* self, int position` | Returns a pointer to the value at the specified position. | O(n)      |
| `void`      | `linkedlist_INSERT`     | `struct LinkedList* self, int position, void * value` | Inserts a new element at the specified position. | O(n)    |
| `void`      | `linkedlist_UPDATE`     | `struct LinkedList* self, int position, void * value` | Updates the value at the specified position. | O(n)    |
| `int*`      | `linkedlist_FIND`       | `struct LinkedList* self, void * search_value` | Finds the position of the first occurrence of a value. | O(n) |
| `int*`      | `linkedlist_COUNT`      | `struct LinkedList* self, void * search_value` | Counts the number of occurrences of a value. | O(n) |
| `void`      | `linkedlist_REMOVE_FIRST` | `struct LinkedList* self` | Removes the first element. | O(1)               |
| `void`      | `linkedlist_REMOVE_LAST`  | `struct LinkedList* self` | Removes the last element. | O(n)                |
| `LinkedList`| `linkedlist_COPY`       | `struct LinkedList* self`            | Creates a copy of the linked list. | O(n)             |
| `LinkedList`| `linkedlist_CONCATENATE`| `struct LinkedList* list1, struct LinkedList* list2` | Concatenates two linked lists. | O(n)               |
| `void`      | `linkedlist_REMOVE_AT`  | `struct LinkedList* self, int position` | Removes the element at the specified position. | O(n)       |
| `void`      | `linkedlist_VALUE_DELETE` | `struct LinkedList* self, void * search_value` | Removes all occurrences of a value. | O(n)           |
| `bool`      | `linkedlist_CONTAINS`   | `struct LinkedList* self, void * search_value` | Checks if the linked list contains a value. | O(n)      |
| ~~`void*`~~   | ~~`linkedlist_SUM`~~        | ~~`struct LinkedList* self` ~~           | Calculates the sum of all elements. | O(n)            |
| ~~`void*`~~   | ~~`linkedlist_AVG`~~        | ~~`struct LinkedList* self` ~~           | Calculates the average of all elements. | O(n)        |
| ~~`void` ~~     | ~~`linkedlist_BUBBLESORT`~~ | ~~`struct LinkedList* self` ~~           | Sorts the elements in ascending order using bubble sort. | O(n^2) |
| `void`      | `linkedlist_REVERSE`    | `struct LinkedList* self`            | Reverses the order of elements. | O(n)                |
| `void`      | `linkedlist_ADD`        | `struct LinkedList* self, void * value` | Adds a new element to the end of the linked list. | O(1)   |

For detailed descriptions of each function, refer to the code comments.


## Usage

To use these linked list functions, you need to have a LinkedList object. You can create a new linked list using the appropriate initialization function.

Here's an example of creating a new linked list, adding elements, and performing operations:

## INT BASED LIST
```c
    // Create a new linked list
    LinkedList list = new_linkedList(INT);

    // Add elements to the linked list
    linkedlist_ADD(&list, (void*)10);
    linkedlist_ADD(&list, (void*)20);
    linkedlist_ADD(&list, (void*)30);

    // Get the size of the linked list
    int size = linkedlist_GET_SIZE(&list);
    printf("Size of the linked list: %d\n", size);

    // Get the first element of the linked list
    int* first = (int*)linkedlist_GET_FIRST(&list);
    printf("First element: %d\n", *first);

    // Get the last element of the linked list
    int* last = (int*)linkedlist_GET_LAST(&list);
    printf("Last element: %d\n", *last);

    // Get the element at a specific position
    int* atPosition = (int*)linkedlist_GET_AT(&list, 1);
    printf("Element at position 1: %d\n", *atPosition);

    // Insert an element at a specific position
    linkedlist_INSERT(&list, 1, (void*)15);
    linkedlist_DISPLAY(&list);

    // Update the value at a specific position
    linkedlist_UPDATE(&list, 2, (void*)25);
    linkedlist_DISPLAY(&list);

    // Find the position of a value
    int position = linkedlist_FIND(&list, (void*)20);
    printf("Position of value 20: %d\n", position);

    // Count the number of occurrences of a value
    int count = linkedlist_COUNT(&list, (void*)10);
    printf("Number of occurrences of value 10: %d\n", count);

    // Remove the first element
    linkedlist_REMOVE_FIRST(&list);
    linkedlist_DISPLAY(&list);

    // Remove the last element
    linkedlist_REMOVE_LAST(&list);
    linkedlist_DISPLAY(&list);

    // Create a copy of the linked list
    LinkedList copy = linkedlist_COPY(&list);
    linkedlist_DISPLAY(&copy);

    // Concatenate two linked lists
    LinkedList list2 = new_linkedList(INT);
    linkedlist_ADD(&list2, (void*)40);
    linkedlist_ADD(&list2, (void*)50);
    LinkedList concatenated = linkedlist_CONCATENATE(&list, &list2);
    linkedlist_DISPLAY(&concatenated);

    // Remove an element at a specific position
    linkedlist_REMOVE_AT(&concatenated, 2);
    linkedlist_DISPLAY(&concatenated);

    // Remove all occurrences of a value
    linkedlist_VALUE_DELETE(&concatenated, (void*)20);
    linkedlist_DISPLAY(&concatenated);

    // Check if the linked list contains a value
    bool contains = linkedlist_CONTAINS(&concatenated, (void*)30);
    printf("Linked list contains value 30: %s\n", contains ? "true" : "false");

    // Reverse the order of elements
    linkedlist_REVERSE(&concatenated);
    linkedlist_DISPLAY(&concatenated);

    // Clear the linked list
    linkedlist_CLEAR(&concatenated);
```

## STRING BASED LIST
```c
    // Create a new linked list
    LinkedList list = new_linkedList(STRING);

    // Add elements to the linked list
    char* str1 = "Hello";
    char* str2 = "World";
    char* str3 = "LinkedList";
    linkedlist_ADD(&list, (void*)str1);
    linkedlist_ADD(&list, (void*)str2);
    linkedlist_ADD(&list, (void*)str3);

    // Display the linked list
    printf("Linked List: ");
    linkedlist_DISPLAY(&list);

    // Get the size of the linked list
    int size = linkedlist_GET_SIZE(&list);
    printf("Size of the linked list: %d\n", size);

    // Get the first and last elements of the linked list
    char* first = (char*)linkedlist_GET_FIRST(&list);
    char* last = (char*)linkedlist_GET_LAST(&list);
    printf("First element: %s\n", first);
    printf("Last element: %s\n", last);

    // Get the element at a specific position
    char* element = (char*)linkedlist_GET_AT(&list, 1);
    printf("Element at position 1: %s\n", element);

    // Insert an element at a specific position
    char* insertValue = "OpenAI";
    linkedlist_INSERT(&list, 1, (void*)insertValue);

    // Update an element at a specific position
    char* updateValue = "GPT-3";
    linkedlist_UPDATE(&list, 2, (void*)updateValue);

    // Display the updated linked list
    printf("Updated Linked List: ");
    linkedlist_DISPLAY(&list);

    // Find the position of an element in the linked list
    char* searchValue = "World";
    int position = linkedlist_FIND(&list, (void*)searchValue);
    printf("Position of 'World': %d\n", position);

    // Count the number of elements in the linked list
    int count = linkedlist_COUNT(&list);
    printf("Count of elements: %d\n", count);

    // Remove the first and last elements from the linked list
    linkedlist_REMOVE_FIRST(&list);
    linkedlist_REMOVE_LAST(&list);

    // Display the modified linked list
    printf("Modified Linked List: ");
    linkedlist_DISPLAY(&list);

    // Check if the linked list contains a specific value
    char* containsValue = "Hello";
    bool contains = linkedlist_CONTAINS(&list, (void*)containsValue);
    printf("Contains 'Hello': %s\n", contains ? "true" : "false");

    // Reverse the linked list
    linkedlist_REVERSE(&list);

    // Display the reversed linked list
    printf("Reversed Linked List: ");
    linkedlist_DISPLAY(&list);

    // Clear the linked list
    linkedlist_CLEAR(&list);
```

Feel free to use these functions and modify them as needed to suit your specific requirements for a linked list implementation.

## Contributing
Contributions are welcome! If you find any issues or have suggestions for improvements, please feel free to contribute to this project.