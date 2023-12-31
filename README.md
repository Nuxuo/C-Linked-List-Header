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
typedef enum { STRING, INT, CHAR, FLOAT, DOUBLE, BOOL } type;

typedef struct Cell {
    void * value;
    struct Cell* Next;
} Cell;

typedef struct LinkedList {
    struct Cell* Head;
    type type;
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
| `void*`     | `linkedlist_GET_FIRST`  | `struct LinkedList* self`            | Returns a pointer to the value of the first element. | O(1)           |
| `void*`     | `linkedlist_GET_LAST`   | `struct LinkedList* self`            | Returns a pointer to the value of the last element. | O(n)            |
| `void*`     | `linkedlist_GET_AT`     | `struct LinkedList* self, int position` | Returns a pointer to the value at the specified position. | O(n)      |
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
    int value1 = 10;
    int value2 = 20;
    int value3 = 30;
    linkedlist_ADD(&list, (void*)&value1);
    linkedlist_ADD(&list, (void*)&value2);
    linkedlist_ADD(&list, (void*)&value3);

    // Display the linked list
    printf("Linked List: ");
    linkedlist_DISPLAY(&list);

    // Get the size of the linked list
    int size = linkedlist_GET_SIZE(&list);
    printf("Size of the linked list: %d\n", size);

    // Get the first and last elements of the linked list
    int* first = (int*)linkedlist_GET_FIRST(&list);
    int* last = (int*)linkedlist_GET_LAST(&list);
    printf("First element: %d\n", *first);
    printf("Last element: %d\n", *last);

    // Get the element at a specific position
    int* element = (int*)linkedlist_GET_AT(&list, 1);
    printf("Element at position 1: %d\n", *element);

    // Insert an element at a specific position
    int insertValue = 15;
    linkedlist_INSERT(&list, 1, (void*)&insertValue);

    // Update an element at a specific position
    int updateValue = 25;
    linkedlist_UPDATE(&list, 2, (void*)&updateValue);

    // Display the updated linked list
    printf("Updated Linked List: ");
    linkedlist_DISPLAY(&list);

    // Find the position of an element in the linked list
    int searchValue = 20;
    int position = linkedlist_FIND(&list, (void*)&searchValue);
    printf("Position of 20: %d\n", position);

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
    int containsValue = 20;
    bool contains = linkedlist_CONTAINS(&list, (void*)&containsValue);
    printf("Contains 20: %s\n", contains ? "true" : "false");

    // Reverse the linked list
    linkedlist_REVERSE(&list);

    // Display the reversed linked list
    printf("Reversed Linked List: ");
    linkedlist_DISPLAY(&list);

    // Clear the linked list
    linkedlist_CLEAR(&list);
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