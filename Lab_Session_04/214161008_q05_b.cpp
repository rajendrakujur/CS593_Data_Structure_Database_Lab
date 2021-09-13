/*Last update by RAJENDRA KUJUR (214161008) on 13-09-2021 at 13:44*/

#include <iostream>
using namespace std;

// structure definition for double linked list
struct DoublyLinkedList
{
    int data;
    struct DoublyLinkedList *previous;
    struct DoublyLinkedList *next;
};

// create a node with data field as number and previous and next pointer to null and returns
struct DoublyLinkedList *createNode(int number)
{
    struct DoublyLinkedList *new_node;
    new_node = new DoublyLinkedList();
    new_node->previous = NULL;
    new_node->data = number;
    new_node->next = NULL;
    return new_node;
}

// function to insert new_node at the beginning of list pointed by head
void enqueueFront(struct DoublyLinkedList *&head, struct DoublyLinkedList *new_node)
{
    if (!head)
    {
        head = new_node;
    }
    else
    {
        new_node->next = head;
        head->previous = new_node;
        head = new_node;
    }
}

// function to insert new_node at the end of list pointed by head
void enqueueRear(struct DoublyLinkedList *&head, struct DoublyLinkedList *new_node)
{
    if (!head)
    {
        head = new_node;
    }
    else
    {
        // created a temporary node called traverse to traverse the list pointed by head
        struct DoublyLinkedList *traverse;
        traverse = head;

        // traverse till the last node of the list
        while (traverse->next)
        {
            traverse = traverse->next;
        }

        // update pointer to the new_node and new_node's pointer to the traversing node
        traverse->next = new_node;
        new_node->previous = traverse;
    }
}

// function to delete a node from the beginning of the list
void dequeueFront(struct DoublyLinkedList *&head)
{
    // if length of list is 0 so delete operation can't be performed
    if (!head)
    {
        cout << "\nLength of list = 0, So can't delete.";
        return;
    }

    // else make a delete_node that points to head
    struct DoublyLinkedList *delete_node;
    delete_node = head;

    // if list is having more than one element then update head to its next node
    if (head->next)
    {
        head = head->next;
        head->previous = NULL;
    }
    // else make head as NULL
    else
    {
        head = NULL;
    }

    // free the memory space
    free(delete_node);
}

// function to delete a node from the end
void dequeueRear(struct DoublyLinkedList *&head)
{
    if (!head)
    {
        cout << "\nLength of list = 0, So can't delete.";
        return;
    }

    struct DoublyLinkedList *delete_node;
    struct DoublyLinkedList *traverse;

    traverse = head;
    // traverse to the just before the last node
    while (traverse->next)
    {
        traverse = traverse->next;
    }

    // Assign the last node to delete_node
    delete_node = traverse;

    // if there is a node left after deleteing
    if (traverse->previous)
    {
        traverse->previous->next = NULL;
    }
    // if the list has only one node then make head = NULL
    else
    {
        head = NULL;
    }

    // free the memory
    free(delete_node);
}

// prints the list
void printList(struct DoublyLinkedList *head)
{
    while (head)
    {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL";
}

// main deleteFromBeginningfunction execution begins here
int main()
{
    // declaration of list
    struct DoublyLinkedList *head;
    head = NULL;

    // few variable that will be required while performing operations
    int number;
    int choice;

    // Loop  will continue till the user wants
    while (1)
    {
        cout << "\n1.Insert node at the beginning.";
        cout << "\n2.Insert node at the end.";
        cout << "\n3.Delete node from beginning";
        cout << "\n4.Delete node from end";
        cout << "\nEnter choice : ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter number to insert : ";
            cin >> number;

            enqueueFront(head, createNode(number));
            break;

        case 2:
            cout << "Enter number to insert : ";
            cin >> number;

            enqueueRear(head, createNode(number));
            break;

        case 3:
            dequeueFront(head);
            break;

        case 4:
            dequeueRear(head);
            break;

        default:
            continue;
        }

        cout << "\nUpdated List : ";
        printList(head);

        // ask the user whether s/he want to continue
        cout << "\nDo you want to continue? 0(for no) 1 or any other(for yes) : ";
        cin >> choice;

        if (!choice)
        {
            break;
        }
    }
    return 0;
}
