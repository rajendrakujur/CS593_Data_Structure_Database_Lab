/*Last update by RAJENDRA KUJUR (214161008) on 03-09-2021 at 10:20*/

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

// function that returns the length of list pointed by head pointer
int lengthOfList(struct SingleLinkedList *head)
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

        // new_node->next = NULL;
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

// function that swap the list nodes starting from front and back
struct SingleLinkedList *swapBetweenIndices(struct SingleLinkedList *&head, int low, int high)
{
    // traverse list to traverse the head node
    struct SingleLinkedList *traverse;
    traverse = head;
    int count = 1;

    // first move just till just before the low index
    for (; count < low - 1; count++)
    {
        traverse = traverse->next;
    }
    // store the low indexed node into start
    struct SingleLinkedList *start;

    // to traverse the list that has to be swapped
    struct SingleLinkedList *finish;

    if (low != 1)
    {
        // and make traverse's next to NULL so that reversed list can be added at the end
        start = traverse->next;
        traverse->next = NULL;
        finish = start;
    }
    else
    {
        start = NULL;
        finish = head;
    }

    // to store the next node's address of high indexed node
    struct SingleLinkedList *last;

    // to store the finish node's next temporarity
    struct SingleLinkedList *stack_next;

    // initialize a stack to store the list's node so that the list can be swapped
    struct stack s;
    s.top = -1;
    s.size = 1000;

    // traverse upto high index
    for (count = low; count < high; count++)
    {
        // store the finish node's next since it will be updated to NULL temporarity while pushing to stack
        stack_next = finish->next;
        finish->next = NULL;

        push(s, finish);

        // restore the finish node's next value
        finish = stack_next;
    }

    last = finish->next;

    // update traverse node
    if (low != 1)
    {
        traverse->next = finish;
        traverse = traverse->next;
        // make it's next to NULL to fecilitate on updating pointers
        traverse->next = NULL;
    }
    else
    // if the low ==1 then update head node
    {
        head = finish;
        head->next = NULL;
    }

    // pop the element from stack and add at the end of the list pointed by head
    while (!isEmpty(s))
    {
        addEnd(head, pop(s));
    }

    // at last add the high indexed node's next pointer that was previously stored into last
    addEnd(head, last);

    // return the final head
    return head;
}

// main function execution begins here
int main()
{
    // declaration of list
    struct SingleLinkedList *head;
    head = NULL;

    int number = 0;
    int length = 0;

    cout << "Enter list length : ";
    cin >> length;

    cout << "Enter Lists elements : ";
    for (int count = 0; count < length; count++)
    {
        cin >> number;
        // create a node with number as data field and NULL as next field and add at the end of list_1
        addEnd(head, createNode(number, NULL));
    }

    int low, high;

    do
    {
        cout << "Enter valid p (1-based indexing): ";
        cin >> low;
    } while (low < 1 || low > length);

    do
    {
        cout << "Enter valid q (1-based indexing): ";
        cin >> high;
    } while (high < low || high > length);

    // declare result to store the sorted list
    struct SingleLinkedList *result;
    result = swapBetweenIndices(head, low, high);

    // print the final result
    printList(result);
    return 0;
}