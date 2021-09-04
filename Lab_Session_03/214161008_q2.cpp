/*Last update by RAJENDRA KUJUR (214161008) on 02-09-2021 at 13:08*/

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

// deletes the last occurence of the number if it appears atleast once in the list
void deleteLastOccurence(struct SingleLinkedList *previous, struct SingleLinkedList *&head, int number)
{
    // if we reach to the end of the list or the list is empty
    if (!head)
    {
        return;
    }
    else
    {
        // recursive call to delete and update previous and head pointers accordingly
        deleteLastOccurence(head, head->next, number);

        // boolean to keep track so that element will be deleted only once
        static bool deleted = false;

        // deletion block
        if (head->data == number && !deleted)
        {
            deleted = true;

            // if the node has to be deleted is not a head node
            if (previous)
                previous->next = head->next;
            else
                // if head node is to be deleted then update the pointer to its next node
                head = head->next;
        }
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

// main function execution begins here
int main()
{
    // declaration of List
    struct SingleLinkedList *head;
    head = NULL;

    // required temporaries
    int length = 0, number;
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
    printList(head);

    // prompts the user to input the number
    cout << "\nEnter number you want to delete : ";
    cin >> number;

    // call the function
    deleteLastOccurence(NULL, head, number);

    printList(head);
    return 0;
}