/*Last update by RAJENDRA KUJUR (214161008) on 31-08-2021 at 06:07*/

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

// compares nodes data at each node and add the maximum one into new_list and returns
struct SingleLinkedList *compareAndAdd(struct SingleLinkedList *first_list, struct SingleLinkedList *second_list)
{
    // creates max_list node to store result
    struct SingleLinkedList *max_list;
    max_list = NULL;

    // if list is having 0 nodes
    if (!first_list)
    {
        return max_list;
    }

    // compares till the list is having some content
    while (first_list)
    {
        static struct SingleLinkedList *new_node;

        // if data in first list is greater than data in second list
        // create a new_node using this data
        if (first_list->data > second_list->data)
        {
            new_node = createNode(first_list->data, NULL);
        }
        // if data in first limit is smaller or equal to data in second list
        else
        {
            new_node = createNode(second_list->data, NULL);
        }
        // add the node created at the last of the max_list
        addEnd(max_list, new_node);

        // move the first_list and second_list pointer to the next node
        first_list = first_list->next;
        second_list = second_list->next;
    }

    // return max_list
    return max_list;
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
    // declaration of list_1
    struct SingleLinkedList *list_1;
    list_1 = NULL;

    // declaration of list_2
    struct SingleLinkedList *list_2;
    list_2 = NULL;

    int number = 0;
    bool choice = 0;
    int length = 0;

    cout << "Enter list length : ";
    cin >> length;

    cout << "Enter List-1's elements : ";
    for (int count = 0; count < length; count++)
    {
        cin >> number;
        // create a node with number as data field and NULL as next field and add at the end of list_1
        addEnd(list_1, createNode(number, NULL));
    }

    cout << "Enter List-2's elements : ";
    // since both list be having same length so loop will run till the length of first_list length
    for (int count = 0; count < length; count++)
    {
        cin >> number;
        // create a node with number as data field and NULL as next field and add at the end of list_2
        addEnd(list_2, createNode(number, NULL));
    }

    // declaration to store result
    struct SingleLinkedList *result;
    result = NULL;

    // call the function and store the result back to result node
    result = compareAndAdd(list_1, list_2);

    // print the final result
    printList(result);
    return 0;
}