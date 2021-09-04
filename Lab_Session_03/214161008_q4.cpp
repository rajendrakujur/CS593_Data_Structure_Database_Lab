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
    int count_zero = 0;
    int count_one = 0;
    int count_two = 0;

    // traverse list till list becomes and update respective counts if that number appears
    while (list)
    {
        if (list->data == 0)
        {
            count_zero++;
        }
        else if (list->data == 1)
        {
            count_one++;
        }
        else if (list->data == 2)
        {
            count_two++;
        }
        list = list->next;
    }

    struct SingleLinkedList *result = NULL;

    // assign a new node at the end till count_zero becomes zero
    while (count_zero)
    {
        addEnd(result, createNode(0, NULL));
        count_zero--;
        continue;
    }
    // assign a new node at the end till count_one becomes zero
    while (count_one)
    {
        addEnd(result, createNode(1, NULL));
        count_one--;
        continue;
    }
    // assign a new node at the end till count_two becomes zero
    while (count_two)
    {
        addEnd(result, createNode(2, NULL));
        count_two--;
        continue;
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
        cin >> number;
        // create a node with number as data field and NULL as next field and add at the end of list_1
        addEnd(head, createNode(number, NULL));
    }

    // declare result to store the sorted list
    struct SingleLinkedList *result;
    result = sort(head);

    // print the final result
    printList(result);
    return 0;
}