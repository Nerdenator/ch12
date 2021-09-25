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