/*Last update by RAJENDRA KUJUR (214161008) on 04-09-2021 at 21:42*/

#include <iostream>
using namespace std;

// structure for single linked list
struct SingleLinkedList
{
    int data;
    struct SingleLinkedList *next;
};

// takes number and next_node as an argument
// creates a node with number as data field and next_node as next field and returns
struct SingleLinkedList *createNode(int number, struct SingleLinkedList *next_node)
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
void printList(struct SingleLinkedList *list)
{
    if (!list)
        return;
    while (list)
    {
        cout << list->data << " -> ";
        list = list->next;
    }
    cout << "NULL\n";
}

// swaps the kth node from front and last of the list pointed by head
struct SingleLinkedList *swapKthNode(struct SingleLinkedList *head, int length, int k)
{
    //
    if (!head || !head->next)
    {
        return head;
    }

    // points to the (k-1)th node from front
    struct SingleLinkedList *front_previous;
    front_previous = NULL;

    // points to the kth node from front
    struct SingleLinkedList *front;
    front = head;

    // points to the (k+1)th node from front
    struct SingleLinkedList *front_next;
    front_next = head->next;

    // points to the (k-1)th node from rear
    struct SingleLinkedList *rear_previous;
    rear_previous = NULL;

    // points to the kth node from rear
    struct SingleLinkedList *rear;
    rear = head;

    // points to the (k+1)th node from rear
    struct SingleLinkedList *rear_next;
    rear_next = head->next;

    // set all front pointers
    for (int index = 0; index < k; index++)
    {
        front_previous = front;
        front = front->next;
        front_next = front_next->next;
    }

    // set all rear pointers
    for (int index = 0; index < length - k - 1; index++)
    {
        rear_previous = rear;
        rear = rear->next;
        rear_next = rear_next->next;
    }

    // if (k-1)th node from front pointing to NULL means we have update head
    if (front_previous)
        front_previous->next = rear;
    else
        head = rear;

    rear->next = front_next;

    // if (k-1)th node from rear pointing to NULL means we have update head
    if (rear_previous)
        rear_previous->next = front;
    else
        head = front;

    front->next = rear_next;

    // return the final list
    return head;
}

// main function execution begins here
int main()
{
    // declaration of list pointed by head
    struct SingleLinkedList *head;
    head = NULL;

    int number = 0;
    int k;
    int length = 0;

    cout << "Enter List length : ";
    cin >> length;

    cout << "Enter List's elements : ";
    for (int count = 0; count < length; count++)
    {
        cin >> number;
        // create a node with number as data field and NULL as next field and add at the end of list_1
        addEnd(head, createNode(number, NULL));
    }

    do
    {
        cout << "Enter valid k(0-based indexing) : ";
        cin >> k;
    } while (k >= length || k < 0);

    // declaration to store result
    struct SingleLinkedList *result;
    result = NULL;

    // call the function and store the result back to result node
    result = swapKthNode(head, length, k);

    // print the final result
    printList(result);
    return 0;
}