/*Last update by RAJENDRA KUJUR (214161008) on 03-09-2021 at 15:26*/

#include <unistd.h>
#include <iostream>
using namespace std;

// structure for single linked list
struct SingleLinkedList
{
    int data;
    struct SingleLinkedList *next;
};

// structure for stack
struct stack
{
    struct SingleLinkedList *(data[1000]);
    int top;
    int size;
};

// returns true if stack is full, else returns false
bool isFull(struct stack s)
{
    if (s.top == s.size - 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// returns true if stack is empty, else returns false
bool isEmpty(struct stack s)
{
    if (s.top == -1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// pushes the node in stack
void push(struct stack &s, struct SingleLinkedList *node)
{
    if (!isFull(s))
    {
        s.data[++s.top] = node;
    }
}

// returns top node from stack
struct SingleLinkedList *top(struct stack s)
{
    return s.data[s.top];
}

// pops the top element from the stack and returns char
struct SingleLinkedList *pop(struct stack &s)
{
    if (!isEmpty(s))
    {
        return s.data[s.top--];
    }
    else
    {
        return NULL;
    }
}

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
void printList(struct SingleLinkedList *head)
{
    if (!head)
        return;
    while (head)
    {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL\n";
}

// Reverses the entire list pointed by head
struct SingleLinkedList *reverseList(struct SingleLinkedList *&head)
{
    // to traverse the list pointed by head
    struct SingleLinkedList *traverse;
    traverse = head;

    // to store the node temporariy so that node's next can be made NULL before pushing into the stack
    struct SingleLinkedList *store;

    // stack declaration
    struct stack s;
    s.top = -1;
    s.size = 10000;

    // traverse untill the end of the traverse list
    while (traverse)
    {
        store = traverse->next;
        traverse->next = NULL;
        push(s, traverse);
        traverse = store;
    }

    // reset the list by pointing head to NULL
    head = NULL;

    // pop and add at the end of the list till the stack becomes empty
    while (!isEmpty(s))
    {
        addEnd(head, pop(s));
    }

    // returns the reversed list pointed by head
    return head;
}

// reverses the list alternatively first 'number' of nodes will be reversed next 'number' of nodes will be as it is and so on
struct SingleLinkedList *reverseAlternate(struct SingleLinkedList *&head, int number)
{
    if (!head || !head->next || number == 1)
    {
        return head;
    }

    // traverse node to traverse the entire node
    struct SingleLinkedList *traverse;
    traverse = head;

    // we will make a new linked list start from afresh
    head = NULL;

    while (traverse)
    {
        // To store the list that has to be reversed
        static struct SingleLinkedList *list_to_reverse;
        list_to_reverse = traverse;

        // to store some nodes temporarly
        struct SingleLinkedList *next;

        // traverse till the node we have to get reverse list
        for (int count = 0; (count < number - 1) && (traverse); count++)
        {
            traverse = traverse->next;

            if (traverse)
            {
                next = traverse->next;
            }
            else
            {
                next = NULL;
            }
        }
        // if traverse is not NULL point its next to NULL so that we won't end up into infinite loop
        if (traverse)
            traverse->next = NULL;

        // add at the end of head node the reversed list returned by reverseList function
        addEnd(head, reverseList(list_to_reverse));

        // update traverse again
        traverse = next;

        // traverse till we have to store it as it is
        for (int count = 0; (count < number) && (traverse); count++)
        {
            next = traverse->next;
            traverse->next = NULL;

            // keep updating head node reading traverse node each time
            addEnd(head, traverse);
            traverse = next;
        }
        traverse = next;
    }

    // return the final output
    return head;
}

// main function execution begins here
int main()
{
    // declaration of List
    struct SingleLinkedList *head;
    head = NULL;

    int length, number;
    cout << "Enter length : ";
    cin >> length;
    int count = 0;
    while (count < length)
    {
        cout << "Enter List's next element : ";
        cin >> number;
        // create a node with number as data field and NULL as next field and add at the end of list_1
        addEnd(head, createNode(number, NULL));
        count++;
    }

    // print just after the entire list input
    cout << "Given Linked List : \n";
    printList(head);

    // to store the result
    struct SingleLinkedList *result;

    do
    {
        cout << "Enter valid n : ";
        cin >> number;
    } while (number <= 0 || number > length);

    // call the function and store the required format into result
    result = reverseAlternate(head, number);

    cout << "\nOutput : \n";
    printList(result);

    return 0;
}
