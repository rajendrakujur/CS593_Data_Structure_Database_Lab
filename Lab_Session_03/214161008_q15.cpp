/*Last update by RAJENDRA KUJUR (214161008) on 04-04-2021 at 18:30*/

#include <iostream>
using namespace std;

// definition for XOR List
struct XORList
{
    int data;
    struct XORList *both;
};

// creates a node and returns the node's address
struct XORList *createNode(int number)
{
    struct XORList *new_node;
    new_node = NULL;

    new_node = new XORList();
    new_node->data = number;
    new_node->both = NULL;

    return new_node;
}

// Adds a new node at the end of original list pointed by head
void add(struct XORList *&head, struct XORList *new_node)
{
    if (!head)
    {
        head = new_node;
        return;
    }

    // traverse node initialized to head so that we won't end up loosing head's address
    struct XORList *traverse;
    traverse = head;

    // to keep track of previous address default initalization to NULL
    struct XORList *previous;
    previous = NULL;

    // to temporarily store address
    struct XORList *temp;

    // traverse untill previous and new_node's XOR is resulting something
    while (reinterpret_cast<struct XORList *>(reinterpret_cast<uintptr_t>(previous) ^ reinterpret_cast<uintptr_t>(traverse->both)))
    {
        temp = traverse;
        // traverse to next node (next node's address is XOR of previous and traverse's next)
        traverse = reinterpret_cast<struct XORList *>(reinterpret_cast<uintptr_t>(previous) ^ reinterpret_cast<uintptr_t>(traverse->both));
        previous = temp;
    }

    // updation of pointers accordingly
    traverse->both = reinterpret_cast<struct XORList *>(reinterpret_cast<uintptr_t>(previous) ^ reinterpret_cast<uintptr_t>(new_node));
    new_node->both = reinterpret_cast<struct XORList *>(reinterpret_cast<uintptr_t>(traverse) ^ reinterpret_cast<uintptr_t>(new_node->both));
}

// returns the node at index'th position in a 0-based indexing list pointed by head
struct XORList *get(struct XORList *head, int index)
{
    if (index == 0)
    {
        return head;
    }

    // traverse node initialized to head so that we won't end up loosing head's address
    struct XORList *traverse;
    traverse = head;

    // to keep track of previous address default initalization to NULL
    struct XORList *previous;
    previous = NULL;

    // to temporarily store address
    struct XORList *temp;

    // traverse till we reach the correct node
    for (int count = 0; count < index; count++)
    {
        temp = traverse;
        traverse = reinterpret_cast<struct XORList *>(reinterpret_cast<uintptr_t>(previous) ^ reinterpret_cast<uintptr_t>(traverse->both));
        previous = temp;
    }

    // and then return
    return traverse;
}

// calculates the length of XOR list pointed by head and returns
int length(struct XORList *head)
{

    int length = 0;
    if (!head)
        return length;

    // traverse node initialized to head so that we won't end up loosing head's address
    struct XORList *traverse;
    traverse = head;

    // to keep track of previous address default initalization to NULL
    struct XORList *previous;
    previous = NULL;

    // to temporarily store address
    struct XORList *temp;

    // traverse until traverse is not NULL
    do
    {
        temp = traverse;
        traverse = reinterpret_cast<struct XORList *>(reinterpret_cast<uintptr_t>(previous) ^ reinterpret_cast<uintptr_t>(traverse->both));
        previous = temp;
        length++;
    } while (traverse);

    // returns the final length
    return length;
}

// to print the XOR list pointed by head
void printXORList(struct XORList *head)
{

    if (!head)
        return;

    // traverse node initialized to head so that we won't end up loosing head's address
    struct XORList *traverse;
    traverse = head;

    // to keep track of previous address default initalization to NULL
    struct XORList *previous;
    previous = NULL;

    // to temporarily store address
    struct XORList *temp;

    // traverse until traverse is not NULL
    do
    {
        cout << traverse->data << " -> ";
        temp = traverse;
        traverse = reinterpret_cast<struct XORList *>(reinterpret_cast<uintptr_t>(previous) ^ reinterpret_cast<uintptr_t>(traverse->both));
        previous = temp;
    } while (traverse);

    cout << "NULL\n";
}

// main function execution begins here
int main()
{
    // declaration of head node by default initalized to NULL
    struct XORList *head;
    head = NULL;

    // further temporaries will be used whenever required
    int number;
    int choice;

    while (1)
    {
        // Prompts user for choices
        cout << "(1) Add another number";
        cout << "\n(2) Get number at index";
        cout << "\n(3) Print List";
        cout << "\n   Any other Exit.\n";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter number to add: ";
            cin >> number;
            add(head, createNode(number));
            break;

        case 2:
            do
            {
                cout << "Enter valid index (0-based Indexing): ";
                cin >> number;
            } while (number < 0 || number >= length(head));

            static struct XORList *returned_node;
            returned_node = get(head, number);
            cout << "\nAddress : " << returned_node << "\thaving Data : " << returned_node->data << endl;
            break;

        case 3:
            printXORList(head);
            break;

        default:
            exit(0);
            break;
        }

        cout << "--------------------------------------------------------------------------" << endl;
    }
    return 0;
}
