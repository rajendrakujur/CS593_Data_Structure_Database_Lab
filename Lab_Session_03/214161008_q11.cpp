/*Last update by RAJENDRA KUJUR (214161008) on 10-09-2021 at 08:00*/

#include <iostream>
using namespace std;

// structure for single linked list
struct SingleLinkedList
{
    float data;
    struct SingleLinkedList *next;
};

// takes number and next_node as an argument
// creates a node with number as data field and next_node as next field and returns
struct SingleLinkedList *createNode(float number, struct SingleLinkedList *next_node)
{
    struct SingleLinkedList *new_node;
    new_node = new SingleLinkedList();
    new_node->data = number;
    new_node->next = next_node;
    return new_node;
}

// Adds a node called new_node at the end of SingleLinkedList which is pointed by head
void addEnd(struct SingleLinkedList *&head, struct SingleLinkedList *new_node)
{
    // if head is NULL
    if (!head)
    {
        head = new_node;
    }
    else
    {
        // else copy address the head's address into temporary node
        struct SingleLinkedList *temp;
        temp = head;
        // traverse temp node
        while (temp->next)
        {
            temp = temp->next;
        }
        // and add to the last node which is currently pointing to NULL
        temp->next = new_node;
    }
}

// prints the list
void printList(struct SingleLinkedList *head)
{
    if (!head)
    {
        cout << "\nList is empty nothing to print ";
        return;
    }
    while (head)
    {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL\n";
}

// merge the sorted lists pointed by first_half and second half
struct SingleLinkedList *mergeList(struct SingleLinkedList *first_half, struct SingleLinkedList *second_half)
{
    // intialized a new list pointed by sorted_list
    struct SingleLinkedList *sorted_list;
    sorted_list = NULL;

    // if first_half is empty then return second_half and vice-versa
    if (!first_half)
    {
        return second_half;
    }
    else if (!second_half)
    {
        return first_half;
    }

    // if we get to a point where first_half's data is less than second_half's then update sorted list to first_half
    if (first_half->data <= second_half->data)
    {
        sorted_list = first_half;
        // call recursively for the next node
        sorted_list->next = mergeList(first_half->next, second_half);
    }
    else
    {
        // if we get to a point where second_half's data is less than first_half's then update sorted list to second_half
        sorted_list = second_half;
        // call the mergeList recursively for the next node
        sorted_list->next = mergeList(first_half, second_half->next);
    }

    // return the final sorted list
    return sorted_list;
}

// this divides the list pointed by head into two halves
void split(struct SingleLinkedList *head, struct SingleLinkedList *&first_half, struct SingleLinkedList *&second_half)
{
    // slow_pointer will be move one by one intialized with head
    struct SingleLinkedList *slow_pointer;
    slow_pointer = head;

    // fast pointer will by two by the time slow pointer moves one
    struct SingleLinkedList *fast_pointer;
    fast_pointer = head->next;

    // used the concept of fast and slow pointer to reach the middle of the list
    while (fast_pointer)
    {
        fast_pointer = fast_pointer->next;
        if (fast_pointer)
        {
            fast_pointer = fast_pointer->next;
            slow_pointer = slow_pointer->next;
        }
    }

    // first half will begin from head
    first_half = head;

    // second half will begin from slow_pointer->next
    second_half = slow_pointer->next;

    // update slow_pointer's next so that we won't end up entering into second half
    slow_pointer->next = NULL;
}

// function that sorts the list pointed by head recursively
void mergeSort(struct SingleLinkedList *&head)
{
    // if node is NULL or only one element return directly
    if (!head || !head->next)
    {
        return;
    }

    // else traverse node will point to the list head is pointing and traverse
    struct SingleLinkedList *traverse;
    traverse = head;

    // to divide list into two halves
    struct SingleLinkedList *first_half;
    struct SingleLinkedList *second_half;

    // split the head node into two halves, first half and second half are passed by call by reference so they'll be updated
    split(head, first_half, second_half);

    // call the sorting function individually on both the halves
    mergeSort(first_half);
    mergeSort(second_half);

    // at the end merge both the sorted list into head
    head = mergeList(first_half, second_half);
}

// main function execution begins here
int main()
{
    // declaration of List
    struct SingleLinkedList *head;
    head = NULL;

    // required temporaries
    int length = 0;
    float number;
    cout << "Enter list length : ";
    cin >> length;

    cout << "Enter list's elements : ";
    while (length--)
    {
        cin >> number;
        // create a node with number as data field and NULL as next field and add at the end of list_1
        addEnd(head, createNode(number, NULL));
    }

    // print list before deletion i.e. original list
    cout << "\nBefore Sorting : \n";
    printList(head);
    // call mergeSort function
    mergeSort(head);
    // print the sorted list
    cout << "After Sorting : \n";
    printList(head);
    return 0;
}
