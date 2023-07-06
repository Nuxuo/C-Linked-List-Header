Linked List Functions
This README provides an overview of the functions available in the provided code for a linked list implementation. These functions allow you to manipulate and perform operations on a linked list data structure.

Function List
int linkedlist_GET_SIZE(struct LinkedList* self)
double* linkedlist_GET_FIRST(struct LinkedList* self)
double* linkedlist_GET_LAST(struct LinkedList* self)
double linkedlist_GET_AT(struct LinkedList* self, int position)
void linkedlist_INSERT(struct LinkedList* self, int position, double value)
void linkedlist_UPDATE(struct LinkedList* self, int position, double value)
int linkedlist_FIND(struct LinkedList* self, double search_value)
int linkedlist_COUNT(struct LinkedList* self, double search_value)
void linkedlist_REMOVE_FIRST(struct LinkedList* self)
void linkedlist_REMOVE_LAST(struct LinkedList* self)
void linkedlist_REMOVE_AT(struct LinkedList* self, int position)
void linkedlist_REMOVE_ALL(struct LinkedList* self, double value)
LinkedList linkedlist_COPY(struct LinkedList* self)
LinkedList linkedlist_CONCATENATE(struct LinkedList* list1, struct LinkedList* list2)
void linkedlist_POSITION_DELETE(struct LinkedList* self, int position)
void linkedlist_VALUE_DELETE(struct LinkedList* self, double search_value)
bool linkedlist_CONTAINS(struct LinkedList* self, double search_value)
double linkedlist_SUM(struct LinkedList* self)
double linkedlist_AVG(struct LinkedList* self)
void linkedlist_BUBBLESORT(struct LinkedList* self)
void linkedlist_REVERSE(struct LinkedList* self)
void linkedlist_ADD(struct LinkedList* self, double value)
void linkedlist_APPEND(struct LinkedList* self, double value)
void linkedlist_DISPLAY(struct LinkedList* self)
void linkedlist_CLEAR(LinkedList* LinkedList)
LinkedList new_linkedList()

Function Descriptions

int linkedlist_GET_SIZE(struct LinkedList* self)

Returns the size of the linked list.
double* linkedlist_GET_FIRST(struct LinkedList* self)

Returns a pointer to the value of the first element in the linked list. Returns NULL if the list is empty.
double* linkedlist_GET_LAST(struct LinkedList* self)

Returns a pointer to the value of the last element in the linked list. Returns NULL if the list is empty.
double linkedlist_GET_AT(struct LinkedList* self, int position)

Returns the value at the specified position in the linked list. The position is zero-based. Returns 0.0 if the position is invalid.
void linkedlist_INSERT(struct LinkedList* self, int position, double value)

Inserts a new element with the given value at the specified position in the linked list. If the position is invalid, the element is appended to the end of the list.
void linkedlist_UPDATE(struct LinkedList* self, int position, double value)

Updates the value at the specified position in the linked list with the given value. If the position is invalid, no changes are made.
int linkedlist_FIND(struct LinkedList* self, double search_value)

Searches the linked list for the first occurrence of the given value and returns its position. Returns -1 if the value is not found.
int linkedlist_COUNT(struct LinkedList* self, double search_value)

Counts the number of occurrences of the given value in the linked list and returns the count.
`void linkedlinkedlist_REMOVE_FIRST(struct LinkedList* self)

Removes the first element from the linked list.
void linkedlist_REMOVE_LAST(struct LinkedList* self)

Removes the last element from the linked list.
void linkedlist_REMOVE_AT(struct LinkedList* self, int position)

Removes the element at the specified position from the linked list. If the position is invalid, no changes are made.
void linkedlist_REMOVE_ALL(struct LinkedList* self, double value)

Removes all occurrences of the given value from the linked list.
LinkedList linkedlist_COPY(struct LinkedList* self)

Creates a new linked list and copies all the elements from the current linked list to the new list. Returns the new linked list.
LinkedList linkedlist_CONCATENATE(struct LinkedList* list1, struct LinkedList* list2)

Creates a new linked list by concatenating two existing linked lists, list1 and list2. Returns the concatenated linked list.
void linkedlist_POSITION_DELETE(struct LinkedList* self, int position)

Deletes the element at the specified position from the linked list. If the position is invalid, no changes are made.
void linkedlist_VALUE_DELETE(struct LinkedList* self, double search_value)

Deletes the first occurrence of the given value from the linked list.
bool linkedlist_CONTAINS(struct LinkedList* self, double search_value)

Checks if the linked list contains the given value. Returns true if the value is found, false otherwise.
double linkedlist_SUM(struct LinkedList* self)

Calculates and returns the sum of all elements in the linked list.
double linkedlist_AVG(struct LinkedList* self)

Calculates and returns the average (arithmetic mean) of all elements in the linked list.
void linkedlist_BUBBLESORT(struct LinkedList* self)

Sorts the elements of the linked list in ascending order using the bubble sort algorithm.
void linkedlist_REVERSE(struct LinkedList* self)

Reverses the order of elements in the linked list.
void linkedlist_ADD(struct LinkedList* self, double value)

Adds a new element with the given value at the beginning of the linked list.
void linkedlist_APPEND(struct LinkedList* self, double value)

Adds a new element with the given value at the end of the linked list.
void linkedlist_DISPLAY(struct LinkedList* self)

Displays the elements of the linked list.
void linkedlist_CLEAR(LinkedList* LinkedList)

Clears the linked list by deallocating all memory occupied by its elements.
LinkedList new_linkedList()

Creates and initializes a new empty linked list. Returns the new linked list.
Usage
To use these linked list functions, you need to have a struct LinkedList object. You can create a new linked list using the new_linkedList() function. Once you have a linked list object, you can call any of the provided functions to perform various operations on the linked list.

For example, you can create a new linked list, add elements to it using linkedlist_ADD(), and display the list using linkedlist_DISPLAY():

LinkedList list = new_linkedList();

linkedlist_ADD(&list, 5.0);
linkedlist_ADD(&list, 10.0);
linkedlist_ADD(&list, 15.0);

linkedlist_DISPLAY(&list);
This will output: [15][10][5]

Feel free to use these functions and modify them as needed to suit your specific requirements for a linked list implementation.