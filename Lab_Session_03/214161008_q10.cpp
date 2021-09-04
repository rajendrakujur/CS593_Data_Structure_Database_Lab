/*Last update by RAJENDRA KUJUR (214161008) on 02-09-2021 at 20:48*/

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

// performs insertion sort on a list pointed by head
void insertionSort(struct SingleLinkedList *&head)
{
    if (!head)
        return;
    if (!head->next)
        return;

    // temporary nodes to keep track

    // the node that is to be compared from starting to self
    struct SingleLinkedList *compare_node;

    // the current node from where the comparing will begin in each iteration
    struct SingleLinkedList *current_node;

    // to keep track of the previous node if we want to move the node from right side to left side
    struct SingleLinkedList *previous;

    // to keep store the next node of the node that is being compared in the iteration
    struct SingleLinkedList *next;

    // to keep track whether the number is swapped or not
    bool flag = false;

    // comparision will begin from second node
    compare_node = head->next;

    // loop will continue till we reach till the end
    while (compare_node)
    {
        current_node = head;
        previous = NULL;
        next = compare_node->next;
        flag = false;

        // move current node forward till we reach compare_node
        while (current_node != compare_node)
        {
            // if the node hasn't been moved to left and data is less than the node's data i.e. present on its left side
            if (!flag && compare_node->data < current_node->data)
            {
                // if previous is NULL it means we got to update the head node and the compare_node is smallest
                if (!previous)
                {
                    head = compare_node;
                }
                else
                {
                    previous->next = compare_node;
                }
                compare_node->next = current_node;

                flag = true;
            }

            // if the flag is set and we reach till the compare_node then skip one node and break the loop
            if (flag && current_node->next == compare_node)
            {
                current_node->next = next;
                break;
            }

            // updation of pointers
            previous = current_node;
            current_node = current_node->next;
        }

        compare_node = compare_node->next;
    }
}

// main function execution begins here
int main()
{
    // declaration of List
    struct SingleLinkedList *head;
    head = NULL;

    int number = 0;
    int length = 0;

    cout << "Enter list length : ";
    cin >> length;

    cout << "Enter Lists's elements : ";
    while (length--)
    {
        cin >> number;
        // create a node with number as data field and NULL as next field and add at the end of list_1
        addEnd(head, createNode(number, NULL));
    }

    cout << "\nBefore Sorting : \n";
    printList(head);
    insertionSort(head);

    cout << "\nAfter Sorting : \n";
    printList(head);
    return 0;
}