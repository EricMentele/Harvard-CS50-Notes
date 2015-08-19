
/*
linkedList.c
Eric Mentele
07/04/15

Allows a user to create and manipulate a linked list.
*/

// TODO: "Setting the number correctly and bigger than one through six for node val"

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

// global data
typedef struct node
{
    int val;
    struct node* next;
}
node;

node* head = NULL;

//prototypes
int getNumber();
node* createNode(int newVal);
void addNode(int value);
void append(int value);
void insert(int value, int position);
void extract(int position);
void viewList(void);
void quit(void);



int main(void)
{

    // ask user what they want to do each time.
    do {
    	printf("Please choose one of the following options by entering it's number:\n"
    		"1: Add node to beginning of list.\n"
    		"2: Add node to the end of the list.\n"
    		"3: Insert a node after the specified position.\n"
    		"4: Remove node at specified position.\n"
    		"5: View the list.\n"
    		"6: Quit the program.\n"
            "Option: ");

        // get choice from user
        int choice = getNumber();

        // perform action based on choice.
        switch(choice)
        {
            // data for functions
            int number;
            int index;
            // based on choice obtain necessary numbers from user and run function.

            case 1://                                                   ADD NODE
                // add node to beginning using value.
                printf("Please enter the number you would like to add to the beggining of the list:\n""Number: ");
                number = getNumber();
                addNode(number);
                break;
            case 2://                                                    APPEND
                // add node to the end using value.
                printf("Please enter the number you would like to add to the end of the list.\n""Number: ");
                number = getNumber();
                append(number);
                break;
            case 3://                                                    INSERT
                // insert node using position and value
                if(head == NULL)
                {
                    printf("List empty\n");
                }
                printf("Please enter the position you would like to insert at.\n""Position: ");
                index = getNumber();
                printf("Please enter the number you would like to insert.\n""Number: ");
                number = getNumber();
                insert(number, index);
                break;
            case 4://                                                    REMOVE
                // remove using index
                printf("Please enter the position of the node you would like to remove\n""Position: ");
                index = getNumber();
                extract(index);
                break;
            case 5://                                                     VIEW
                // view linked list
                viewList();
                break;
            case 6://                                                     QUIT
            	// quit
            	quit();
            default:
                printf("Improper input\n");
                break;
        }
    } while(1);
return 0;
}
//                                                                    GET NUMBER
int getNumber() {
    int nitems, number;
    nitems = scanf("%i", &number);
    if (nitems == EOF || 0) {
        printf("Not a number or too large");
        number = 6;
    }
return number;
}
//                                                                    CREATE NODE
node* createNode(int newVal) {
    node* new = malloc(sizeof(node));
    assert(new != NULL);
    new->val = newVal;
    new->next = NULL;
    return new;
}
//                                                                     ADD NODE
void addNode(int value) {
    // create a new node.
    node* newNode = createNode(value);
    // point it to head.
    newNode->next = head;
    // point head to it.
    head = newNode;
}
//                                                                      APPEND
void append(int value) {
    // traverse to the end of the list create a new node and set end nodes pointer to that node.
    node* seeker = head;
    while(seeker->next != NULL) {
        seeker = seeker->next;
    }
    seeker->next = createNode(value);
}
//                                                                      INSERT
// seek to position after insertion point and insert node.
void insert(int value, int position)
{
    // seek position after insertion point and save position prior.
    node* seeker = head;
    node* prepInsert;
    for(int i = 0; i < position; i++)
    {
        //check if we are at the end of the list
        if(seeker == NULL)  {
            printf("End of list\n");
            return;
        }
        // traverse list until position reached
        else {
            // keep track of last position.
            if (i == position - 2 || 0)
            prepInsert = seeker;
            if (i == position - 1)
            {
                prepInsert->next = createNode(value);
                prepInsert = prepInsert->next;
                prepInsert->next = seeker;
                return;
            }
            seeker = seeker->next;
        }
    }
}
//                                                                     REMOVE
// seek and destroy node.
void extract(int position) {
    // target node to remove and track nodes to connect.
    node* scout;
    node* seeker = head;
    node* preTracker;

    for (int j = 0; j < position; j++) {
        // check for end of list.
        if(seeker == NULL) {
            printf("End of list.\n");
            return;
        }
        else {
            if(j == position - 2) {
                // next position is target, activate preTracker
                preTracker = seeker;
            }
            else if (j == position - 1) {
                // target found activate scout.
                scout = seeker->next;
                // connect pre tracker to scout
                preTracker->next = scout;
                // destroy target
                free(seeker);
            }
        seeker = seeker->next;
        }
    }
}
//                                                                      VIEW
void viewList(void) {
    // set up observer to print list values.
    node* observer = head;
    // have observer print value of current node then traverse until NULL.
    while (observer != NULL) {
        printf("%i\n", observer->val);
        observer = observer->next;
    }
}
//                                                                      QUIT
void quit(void)
{
    node* seeker = head;
    while(seeker->next != NULL) {
        seeker = seeker->next;
        free(head);
        head = seeker;
    }
    free(seeker);

	exit(1);
}