/*Last update by RAJENDRA KUJUR (214161008) on 31-08-2021 at 20:48*/

#include <iostream>
using namespace std;

// definition of circular linked list
struct CircularList
{
    char data;
    struct CircularList *next;
};

// create a node using input_char as a data field and next pointer to null and returns
struct CircularList *createNode(char input_char)
{
    struct CircularList *new_node;

    new_node = NULL;
    new_node = new CircularList();
    new_node->data = input_char;
    new_node->next = NULL;

    return new_node;
}

// calculates the length of given list pointed by head and returns
int length(struct CircularList *head)
{
    int length = 0;

    // if head is NULL returns zero
    if (!head)
    {
        return length;
    }
    // else update to 1
    length = 1;

    struct CircularList *traverse;
    traverse = head;

    while (traverse->next != head)
    {
        traverse = traverse->next;
        length++;
    }

    // returns the final length calculated
    return length;
}

// adds new_node at the end(end will be the node i.e. pointing to head currently) of the circular list which is pointed by head
void addToList(struct CircularList *&head, struct CircularList *new_node)
{
    // if head is NULL assign the new_node to head and update next pointer
    if (!head)
    {
        head = new_node;
        head->next = head;
        return;
    }

    // else create a temporary traverse node to traverse the list and add the new_node
    struct CircularList *traverse;
    traverse = head;

    while (traverse->next != head)
    {
        traverse = traverse->next;
    }

    // updation of pointers
    traverse->next = new_node;
    new_node->next = head;
}

// takes delete_node as an argumend and deletes the node from the circular list pointed by head
void deleteFromList(struct CircularList *&head, struct CircularList *delete_node)
{

    struct CircularList *traverse;
    traverse = head;

    // traverse the list until we reach to just before the node
    while (traverse->next != delete_node)
    {
        traverse = traverse->next;
    }
    // updation of pointers
    traverse->next = traverse->next->next;

    // free up the memory
    free(delete_node);
}

// Initiate the games and prints the required output, at the end returns the winner
char playGame(struct CircularList *head, int k)
{
    struct CircularList *current;
    struct CircularList *delete_node;
    current = head;

    // play the game continuously untill we have only one element left in the list
    while (length(current) > 1)
    {
        cout << current->data << " kills ";

        // skip the k-1 position in the list
        for (int count = 0; count < k - 1; count++)
        {
            current = current->next;
        }

        // updation of pointers accordingly
        delete_node = current->next;
        current->next = delete_node->next;
        current = current->next;

        cout << delete_node->data << endl;

        // frees up the space of the node that has to be deleted
        free(delete_node);
    }

    // return the final winner
    return current->data;
}

// main function execution begins here
int main()
{
    int length = 0, k = 0;

    cout << "Enter List Length : ";
    cin >> length;

    // declaration of list
    struct CircularList *head;
    head = NULL;

    char input_char;
    while (length--)
    {
        cout << "Enter List element : ";
        cin >> input_char;
        addToList(head, createNode(input_char));
    }

    cout << "Enter K : ";
    cin >> k;

    // calls the function to initiate the game
    char winner = playGame(head, k);
    cout << "Winner : " << winner << endl;
    return 0;
}
