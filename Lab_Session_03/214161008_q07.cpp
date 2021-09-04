/*Last update by RAJENDRA KUJUR (214161008) on 31-08-2021 at 17:18*/

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

// update the list according to given problem
struct SingleLinkedList *updateList(struct SingleLinkedList *&head_a, struct SingleLinkedList *head_b, int low, int high)
{
    // to traverse the returning list i.e. here head_a
    struct SingleLinkedList *traverse;
    traverse = head_a;

    // to temporary store nodes' address
    struct SingleLinkedList *store;

    // first traverse till just before the low indexed node
    for (int count = 0; count < low; count++)
    {
        store = traverse;
        traverse = traverse->next;
    }

    // if low is 0 i.e. the head node will be updated to directly head_b and stroe will be updated accordingly
    if (low == 0)
    {
        head_a = head_b;
        store = head_b;
    }
    else
    {
        store->next = head_b;
    }

    if (traverse->next)
        traverse = traverse->next;

    // traverse head_b till its next point to NULL
    while (store->next)
    {
        store = store->next;
    }

    // traverse the original head_a list till high indexed node
    for (int count = low; count < high; count++)
    {
        traverse = traverse->next;
    }

    // update store's next pointer since it is now in head_b
    store->next = traverse;

    // return the final processed list
    return head_a;
}

// main function execution begins here
int main()
{
    // Declaration of lists
    struct SingleLinkedList *head_a;
    struct SingleLinkedList *head_b;
    head_a = NULL;
    head_b = NULL;

    int number = 0;
    int length_a = 0;
    int length_b = 0;

    cout << "Enter List A length : ";
    cin >> length_a;

    cout << "Enter Lists A's elements : ";
    for (int count = 0; count < length_a; count++)
    {
        cin >> number;
        // create a node with number as data field and NULL as next field and add at the end of list_1
        addEnd(head_a, createNode(number, NULL));
    }

    cout << "Enter List B length : ";
    cin >> length_b;

    cout << "Enter Lists B's elements : ";
    for (int count = 0; count < length_b; count++)
    {
        cin >> number;
        // create a node with number as data field and NULL as next field and add at the end of list_1
        addEnd(head_b, createNode(number, NULL));
    }

    int low, high;
    do
    {
        cout << "Enter valid low(0-based indexing): ";
        cin >> low;
    } while (low < 0 || low >= length_a);
    do
    {
        cout << "Enter valid high(0-based indexing): ";
        cin >> high;
    } while (high < low || high >= length_a);

    // to store the final list
    struct SingleLinkedList *result;
    result = updateList(head_a, head_b, low, high);

    // print the result
    cout << "\nUpdated List : \n";
    printList(result);
    return 0;
}
