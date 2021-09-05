/*Last update by RAJENDRA KUJUR (214161008) on 31-08-2021 at 17:32*/

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

// calculates the length of the list and returns
int lengthOfList(struct DoublyLinkedList *head)
{
    int length = 0;
    if (!head)
        return length;
    while (head)
    {
        length++;
        head = head->next;
    }
    return length;
}

// inserts an element to the list in increasing order
void insertToList(struct DoublyLinkedList *&head, struct DoublyLinkedList *new_node)
{
    // if head is NULL assign new_node to head
    if (!head)
    {
        head = new_node;
        return;
    }

    // a temporary pointer to traverse the list initialized to head
    struct DoublyLinkedList *current;

    current = head;

    // keep traversing untill we get current->data >= new_node->data
    while (current->data < new_node->data)
    {
        if (current->next)
        {
            current = current->next;
        }
        // if the pointer reaches to NULL i.e. the inserted number is highest
        else
        {
            current->next = new_node;
            new_node->previous = current;
            return;
        }
    }

    // updation of pointers to new_node
    new_node->next = current;
    new_node->previous = current->previous;

    // check if current pointer has previous node as not NULL
    if (current->previous)
    {
        current->previous->next = new_node;
    }
    // if founds to be NULL then update head to new_node since the new_node->data will be smallest
    else
    {
        head = new_node;
    }
    current->previous = new_node;
}

// delete an element from the list
void deleteFromList(struct DoublyLinkedList *&head, int number)
{
    // if list length is zero then print error message
    if (lengthOfList(head) == 0)
    {
        cout << "\nList length is 0, can't perfrom delete operation.";
        return;
    }

    // temporary list to traverse the head node
    struct DoublyLinkedList *traverse;
    traverse = head;

    // traverse untill we get to the number
    while (traverse->data != number)
    {
        if (traverse->next)
        {
            traverse = traverse->next;
        }
        // if traverse points to NULL means we reach to the end of list and print message
        else
        {
            cout << "\nNumber not found";
            return;
        }
    }

    // intialize a pointer to point at current node that has to be deleted
    struct DoublyLinkedList *current;
    current = traverse;

    // update the pointers accordingly
    current->previous->next = current->next;
    if (current->next)
        current->next->previous = current->previous;

    // free the memory
    free(current);
}

// prints the list in ascending order
void printAscending(struct DoublyLinkedList *head)
{
    // if head is NULL print NULL and returns
    if (!head)
    {
        cout << "\nNULL";
        return;
    }

    cout << "\nNULL <- ";

    while (head)
    {
        cout << head->data;
        if (head->next)
            cout << " <=> ";
        else
            cout << " -> ";
        head = head->next;
    }

    cout << "NULL";
}

// prints the list in desceding order i.e. backwards
void printDescending(struct DoublyLinkedList *head)
{
    // if head is NULL then returns
    if (!head)
    {
        cout << "\nNULL";
        return;
    }

    // go forward till we reach to the last element
    while (1)
    {
        if (head->next)
        {
            head = head->next;
        }
        else
        {
            break;
        }
    }

    cout << "\nNULL <- ";

    // now traverse backwards using previous pointers and print
    while (head)
    {
        cout << head->data;
        if (head->previous)
            cout << " <=> ";
        else
            cout << " -> ";
        head = head->previous;
    }

    cout << "NULL";
}

// main function execution begins here
int main()
{
    // declaration of list
    struct DoublyLinkedList *head;
    head = NULL;

    // few variable that will be required while performing operations
    int number, index;
    int choice;
    int length = 0;

    // Loop  will continue till the user wants
    while (1)
    {
        cout << "\n1.Insert Element(integer) ";
        cout << "\n2.Delete Element";
        cout << "\n3.Print in Ascending order.";
        cout << "\n4.Print in Descending order.";

        cout << "\nEnter choice : ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Insert element (Integer): ";
            cin >> number;

            insertToList(head, createNode(number));
            break;

        case 2:
            cout << "Enter number to delete : ";
            cin >> number;

            deleteFromList(head, number);
            break;

        case 3:
            printAscending(head);
            break;

        case 4:
            printDescending(head);
            break;

        default:
            continue;
        }

        // ask the user whether s/he want to continue
        cout << "\nDo you want to continue? 0(for no) 1 or any other(for yes) : ";
        cin >> choice;

        if (!choice)
        {
            break;
        }
    }
}