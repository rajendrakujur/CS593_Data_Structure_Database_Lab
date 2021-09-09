/*Last update by RAJENDRA KUJUR (214161008) on 31-08-2021 at 13:07*/

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

// function that sorts the list elements
struct SingleLinkedList *sort(struct SingleLinkedList *list)
{
    struct SingleLinkedList *result;
    result = NULL;

    if (!list)
    {
        cout << "\nList is empty nothing to sort.";
        return result;
    }

    // to store the next address temporarily
    struct SingleLinkedList *next;
    next = NULL;

    // to store the address of node to be added in the result temporarily
    struct SingleLinkedList *temp_node;
    temp_node = NULL;

    // to traverse the list
    struct SingleLinkedList *traverse;
    traverse = list;

    // traverse and scan for zero
    while (traverse)
    {
        // if zero encountered in the head then update head node itself
        if (list->data == 0)
        {
            temp_node = list;
            next = list->next;
            temp_node->next = NULL;
            list = next;
            addEnd(result, temp_node);
            traverse = list;
        }
        // else if next node's data is zero then do updation of pointers
        else if (traverse->next && traverse->next->data == 0)
        {
            temp_node = traverse->next;
            next = traverse->next->next;
            temp_node->next = NULL;
            addEnd(result, temp_node);
            traverse->next = next;
        }
        else
        {
            traverse = traverse->next;
        }
    }
    traverse = list;

    // traverse and scan for 1
    while (traverse)
    {
        // if the head itself pointing to 1
        if (list->data == 1)
        {
            temp_node = list;
            next = list->next;
            temp_node->next = NULL;
            list = next;
            addEnd(result, temp_node);
            traverse = list;
        }
        // if the next node's data is 1 then update the pointers
        else if (traverse->next && traverse->next->data == 1)
        {
            temp_node = traverse->next;
            next = traverse->next->next;
            temp_node->next = NULL;
            addEnd(result, temp_node);
            traverse->next = next;
        }
        else
        {
            traverse = traverse->next;
        }
    }
    traverse = list;

    // scan for data 2 or this step can be skiped and directly added list into the result
    while (traverse)
    {
        if (list->data == 2)
        {
            temp_node = list;
            next = list->next;
            temp_node->next = NULL;
            list = next;
            addEnd(result, temp_node);
            traverse = list;
        }
        else if (traverse->next && traverse->next->data == 2)
        {
            temp_node = traverse->next;
            next = traverse->next->next;
            temp_node->next = NULL;
            addEnd(result, temp_node);
            traverse->next = next;
        }
        else
        {
            traverse = traverse->next;
        }
    }
    return result;
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

    cout << "Enter Lists elements : ";
    while (length--)
    {
        // cout << "Enter element : ";
        cin >> number;
        // create a node with number as data field and NULL as next field and add at the end of list_1
        addEnd(head, createNode(number, NULL));
        // cout << "\nLength : " << length;
    }

    // declare result to store the sorted list
    struct SingleLinkedList *result;
    result = sort(head);

    // print the final result
    printList(result);
    return 0;
}
