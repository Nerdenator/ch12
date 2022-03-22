/* Fig 12.3: fig12_03.c
    Operating and maintaining a list */
#include <stdio.h>
#include <stdlib.h>

/* self-referential structure */
struct listNode {
    char data; /* each listNode contains a character */
    struct listNode *nextPtr;   /* pointer to next node */
};  /* end structure listNode */

typedef struct listNode ListNode;   /* synonym for struct listNode */
typedef ListNode *ListNodePtr;  /* Synonym for ListNode */

/* prototypes */
void insert( ListNodePtr *sPtr, char value );
char delete( ListNodePtr *sPtr, char value );
int isEmpty( ListNodePtr sPtr );
void printList( ListNodePtr currentPtr );
void instructions ( void );

int main( void )
{
    ListNodePtr startPtr = NULL; /* initially there are no nodes */
    int choice; /* user's choice */
    char item;  /* char entered by user */

    instructions(); /* display the menu */
    printf("? ");
    scanf("%d", &choice);

    /* loop while user does not choose 3 */
    while ( choice != 3 ) {
        switch (choice) 
        {
            case 1:
                printf( "Enter a character: " );
                scanf( "\n%c", &item );
                insert( &startPtr, item );  /* insert item into list */
                printList( startPtr );
                break;

            case 2: /* delete an element */
                /* if the list is not empty */
                if ( !isEmpty( startPtr ) ) {
                    printf( "Enter character to be deleted: " );
                    scanf( "\n%c", &item );
                    
                    /* if character is found, remove it */
                    if ( delete(&startPtr, item) ) {   /* remove item */
                        printf( "%c deleted.\n", item );
                        printList( startPtr );
                    }   /* end if */
                    else {
                        printf( "%c not found.\n\n", item);
                    }   /* end else */
                }   /* end if */
                else {
                    printf( "List is empty.\n\n" );
                }   /* end else */
                break;

            default:
                printf( "Invalid choice.\n\n" );
                instructions();
                break;
        }   /* end switch */

        printf( "? " );
        scanf( "%d", &choice );
    }   /* end while */

    printf( "End of run.\n" );
    return 0;   /* indicates successful termination */
}   /* end main */

/* display program instructions to user */
void instructions( void ) 
{
    printf( "Enter your choice:\n"
        "   1 to insert an element into the list.\n"
        "   2 to delete an element from the list.\n"
        "   3 to end.\n" );
}   /* end function instructions */

/* Insert a new value into the list in sorted order */
void insert ( ListNodePtr *sPtr, char value)
{
    ListNodePtr newPtr; /* pointer to new node */
    ListNodePtr previousPtr;    /* pointer to the previous node in the list */
    ListNodePtr currentPtr; /* pointer to current node in list */
    newPtr = malloc( sizeof( ListNode ) );
    if ( newPtr != NULL ) { /* is space available ? */
        /* Putting stuff from command prompt into new node */
        newPtr->data = value;   /* place value in node */
        newPtr->nextPtr = NULL; /* node does not link to another node */

        previousPtr = NULL;
        currentPtr = *sPtr; /* *sPtr is pointer at start of list */

        /* loop to find the correct location in the list. won't run first time as currentPtr is *sPtr and its nextPtr is NULL */
        while ( currentPtr != NULL && value > currentPtr->data ) {
            previousPtr = currentPtr;   /* walk to ... */
            currentPtr = currentPtr->nextPtr;   /* ... next node */
        }   /* end while */

        /* insert new node at beginning of list */
        if ( previousPtr == NULL ) {
            newPtr->nextPtr = *sPtr;
            *sPtr = newPtr;
        }   /* end if */
        else {  /* insert new node between previousPtr and currentPtr */
            previousPtr->nextPtr = newPtr;
            newPtr->nextPtr = currentPtr;
        }   /* end else */
    }   /* end if */
    else {
        printf( "%c not inserted. No memory available.\n", value );
    }   /* end else */
}   /* end function insert */


/* Delete a list element */
char delete( ListNodePtr *sPtr, char value)
{
    ListNodePtr previousPtr;    /* pointer to a previous node in list */
    ListNodePtr currentPtr; /* pointer to current node in list */
    ListNodePtr tempPtr;    /* temporary node pointer */

    /* delete first node */
    if( value == (*sPtr) ->data ) {
        tempPtr = *sPtr;    /* hold onto node being removed */
        *sPtr = ( *sPtr)->nextPtr;  /* de-thread the node */
        free( tempPtr );    /* free the de-threaded node */
        return value;
    }   /* end if */
    else {
        previousPtr = *sPtr;
        currentPtr = ( *sPtr )->nextPtr;

        /* loop to find the correct location in the list */
        while ( currentPtr != NULL  && currentPtr->data != value) {
            previousPtr = currentPtr;   /* walk to ... */
            currentPtr = currentPtr->nextPtr;   /* ... next node */
        }   /* end while */

        /* delete node at currentPtr */
        if ( currentPtr != NULL ) {
            tempPtr = currentPtr;
            previousPtr->nextPtr= currentPtr->nextPtr;
            free(tempPtr);
            return value;
        }   /* end if */
    }   /* end else */
    
    return '\O';
}   /* end function delete */

/* Return 1 if the list is empty, 0 otherwise */
int isEmpty( ListNodePtr sPtr )
{
    return sPtr == NULL;
} /* end function isEmpty */

/* Print the list */
void printList( ListNodePtr currentPtr ) 
{
    /* if list is empty */
    if ( currentPtr == NULL ) {
        printf( "List is empty.\n\n" );
    }   /* end if */
    else {
        printf( "The list is:\n" );

        /* while not the end of the list */
        while ( currentPtr != NULL ) {
            printf( "%c --> ", currentPtr->data );
            currentPtr = currentPtr->nextPtr;
        } /* end while */
        printf( "NULL\n\n" );
    }
}