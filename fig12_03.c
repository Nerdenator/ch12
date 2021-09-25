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
void delete( ListNodePtr *sPtr, char value );
int isEmpty ( ListNodePtr sPtr );
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
                    if ( delete (&startPtr, item) ) {   /* remove item */
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