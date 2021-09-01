/*Last update by RAJENDRA KUJUR (214161008) on 31-08-2021 at 12:24*/

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

// function to insert new_node at the beginning of list pointed by head
void insertAtBeginning(struct DoublyLinkedList *&head, struct DoublyLinkedList *new_node)
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
void insertAtEnd(struct DoublyLinkedList *&head, struct DoublyLinkedList *new_node)
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

// function inserts new_node at index in the list pointed by head
void insertAtIndex(struct DoublyLinkedList *&head, struct DoublyLinkedList *new_node, int index)
{
    // if index is 0 then insert in the beginning of the list
    if (index == 0 || !head)
    {
        insertAtBeginning(head, new_node);
        return;
    }
    else
    {
        // else traverse the list
        int current_index = 0;
        struct DoublyLinkedList *traverse;
        traverse = head;

        for (int current_index = 0; current_index < index - 1; current_index++)
        {
            traverse = traverse->next;
        }

        // create a temp_node to store the next node of traversing list
        struct DoublyLinkedList *temp_node;

        temp_node = traverse->next;

        // update the pointers of new_node
        new_node->previous = traverse;
        new_node->next = temp_node;

        // temp_node's previous pointer will be updated only if it exist
        if (temp_node)
            temp_node->previous = new_node;
        traverse->next = new_node;
    }
}

// function to delete a node from the beginning of the list
void deleteFromBeginning(struct DoublyLinkedList *&head)
{
    // if length of list is 0 so delete operation can't be performed
    if (lengthOfList(head) == 0)
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
void deleteFromEnd(struct DoublyLinkedList *&head)
{
    if (lengthOfList(head) == 0)
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

// function to delete the node present at index
void deleteAtIndex(struct DoublyLinkedList *&head, int index)
{
    // if index = 0 we have to delete the first node
    if (index == 0)
    {
        deleteFromBeginning(head);
        return;
    }

    int current_index = 0;
    // make a delete node to store the node which has to be deleted
    struct DoublyLinkedList *delete_node;

    // traverse node to traverse the original list
    struct DoublyLinkedList *traverse;
    traverse = head;

    for (int current_index = 0; current_index < index - 1; current_index++)
    {
        traverse = traverse->next;
    }

    delete_node = traverse->next;

    traverse->next = delete_node->next;
    // if the node that has to be deleted has next node(i.e. not NULL)
    if (delete_node->next)
        delete_node->next->previous = traverse;

    // free the memory
    free(delete_node);
}

// search the number into list and return index if present else return -1 if absent
int searchInLinkedList(struct DoublyLinkedList *head, int number)
{
    if (!head)
    {
        return -1;
    }

    int index = 0;
    while (head)
    {
        if (head->data == number)
        {
            return index;
        }
        head = head->next;
    }

    return -1;
}

// prints the list
void printList(struct DoublyLinkedList *head)
{
    while (head)
    {
        cout << head->data << "->";
        head = head->next;
    }
    cout << "NULL";
}

// main function execution begins here
int main()
{
    struct DoublyLinkedList *head;
    head = NULL;

    // few variable that will be required while performing operations
    int number, index;
    int choice;
    int length = 0;

    // Loop  will continue till the user wants
    while (1)
    {
        cout << "\n1.Insert node at the beginning.";
        cout << "\n2.Insert node at the end.";
        cout << "\n3.Insert node at any position k (0-based).";
        cout << "\n4.Delete node from beginning";
        cout << "\n5.Delete node from end";
        cout << "\n6.Delete node from any position k (0-based)";
        cout << "\n7.Search in the linked list.";
        cout << "\nEnter choice : ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter number to insert : ";
            cin >> number;

            insertAtBeginning(head, createNode(number));
            break;

        case 2:
            cout << "Enter number to insert : ";
            cin >> number;

            insertAtEnd(head, createNode(number));
            break;

        case 3:
            length = lengthOfList(head);
            // if user enters the index out of range
            do
            {
                cout << "Enter valid index(>=0 and <=length):";
                cin >> index;
            } while (index < 0 || index > length);

            cout << "Enter number to insert : ";
            cin >> number;

            insertAtIndex(head, createNode(number), index);
            break;

        case 4:
            deleteFromBeginning(head);
            break;

        case 5:
            deleteFromEnd(head);
            break;

        case 6:
            length = lengthOfList(head);
            // if user enters the index out of range
            do
            {
                cout << "Enter valid index(>=0 and <=length):";
                cin >> index;
            } while (index < 0 || index > length);

            deleteAtIndex(head, index);
            break;

        case 7:
            cout << "Enter number to search : ";
            cin >> number;
            index = searchInLinkedList(head, number);

            if (index == -1)
            {
                cout << "Number not found.\n";
            }
            else
            {
                cout << "Found at index : " << index << endl;
            }
            break;

        default:
            continue;
        }

        cout << "\n\nUpdated List : ";
        printList(head);

        // ask the user whether s/he want to continue
        cout << "\nDo you want to continue? 0(for no) 1 or any other(for yes) : ";
        cin >> choice;

        if (!choice)
        {
            break;
        }
    }
}
