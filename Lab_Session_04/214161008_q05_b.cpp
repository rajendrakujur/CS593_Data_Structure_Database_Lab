/*Last update by RAJENDRA KUJUR (214161008) on 13-09-2021 at 13:44*/

#include <iostream>
#include <fstream>
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
int dequeueFront(struct DoublyLinkedList *&head)
{
    // else make a delete_node that points to head
    struct DoublyLinkedList *delete_node;
    delete_node = head;

    int return_value = delete_node->data;
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
    return return_value;
}

// function to delete a node from the end
int dequeueRear(struct DoublyLinkedList *&head)
{
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
    int return_value = delete_node->data;
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
    return return_value;
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

// takes a string convert it into integer and returns
int stringToInteger(string str)
{
    int str_index = 0;

    // to check the coefficient
    int coefficient = 1;
    if (str[str_index] == '-')
    {
        coefficient = -1;
        str_index++;
    }

    int return_value = str[str_index++] - '0';

    while (str[str_index] != '\0')
    {
        return_value *= 10;
        return_value += str[str_index++] - '0';
    }
    return coefficient * return_value;
}

void readFile()
{
    ifstream fin;
    fin.open("214161008_q05_b_input.txt");

    ofstream fout;
    fout.open("214161008_q05_b_output.txt");

    // declaration of list
    struct DoublyLinkedList *head;
    head = NULL;

    // few variable that will be required while performing operations
    int number;
    int choice;
    string line;

    // Loop  will continue till the user wants
    while (!fin.eof())
    {
        fin >> line;
        choice = stringToInteger(line);

        switch (choice)
        {
        // enqueues element at the front of the dequeue
        case 1:
            fin >> line;
            number = stringToInteger(line);
            enqueueFront(head, createNode(number));
            fout << "Enqueued (front) : " << number;
            break;

        // enqueues element at the rear of the dequeue
        case 2:
            fin >> line;
            number = stringToInteger(line);
            enqueueRear(head, createNode(number));
            fout << "Enqueued (rear) : " << number;
            break;

        // dequeues an element from the front if queue wasn't empty
        case 3:
            // if length of list is 0 so delete operation can't be performed
            if (!head)
            {
                fout << "Dequeue is empty.";
            }
            else
            {
                number = dequeueFront(head);
                fout << "Dequeued (front) : " << number;
            }
            break;

        // dequeues an element from the rear if queue wasn't empty
        case 4:
            // if length of list is 0 so delete operation can't be performed
            if (!head)
            {
                fout << "Dequeue is empty.";
            }
            else
            {
                number = dequeueRear(head);
                fout << "Dequeued (front) : " << number;
            }
            break;

        default:
            fout << "Not a valid option.";
        }
        fout << endl;
    }

    fin.close();
    cout << "\nRead from file '214161008_q05_b_input.txt'.";
    fout.close();
    cout << "\nWritten to file '214161008_q05_b_output.txt'.";
}

// main deleteFromBeginningfunction execution begins here
int main()
{
    readFile();
    cout << endl;
    return 0;
}