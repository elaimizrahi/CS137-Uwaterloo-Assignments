#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

typedef struct dlnode{
    int data;
    struct dlnode *next;
    struct dlnode *prev;

} dlnode;

typedef struct {
    dlnode *head;    //points to the first element otherwise NULL
    dlnode *tail;    //points to the last element otherwise NULL
    int len;    // number of elements
} ndlst;
//Pre: lst is valid
//prints the items in the list from start to end.
// Do not submit

void dlistPrint(ndlst *lst)
{
            //printf("headd%d\n", lst->head->next->data);

    dlnode *node = lst->head;
    // iterate over the nodes (items) until node is NULL
    // and print the data
    for (; node; node = node->next)
        printf("%d  ", node->data);
    printf("\n");
}


//Do not submit
void dlistPrintReverse(ndlst *lst)
{
    dlnode *node = lst->tail;
    // iterate over the nodes (items) until node is NULL
    // and print the data
    //printf("HI");
    for (; node; node = node->prev){
        printf("%d  ", node->data);
    }
    printf("\n");
    //printf("done\n");
}

//Pre: None
//Post: Creates a null list
struct ndlst *dlistCreate(void)
{
    ndlst *ret = malloc(sizeof(ndlst));
    ret->head = NULL;
    ret->tail = NULL;
    ret->len = 0;
    return ret;
}

//Pre: lst is a valid list
//Post: Destroys the list
void dlistDestroy(ndlst *lst)
{
    dlnode * nextnode = lst->head ;
dlnode * curnode = NULL ;
    while ( nextnode ){   
    curnode = nextnode ;
    nextnode = nextnode->next ;
free ( curnode );
}
free ( lst );
    
}

//Pre: lst is valid
//Post: returns the number of elements in the list
int dlistLength(ndlst *lst)
{
    return lst->len;
}

//Pre: lst is a valid list with length of at least n>=1
//Post: nth item removed
void dlistRemoveElem(ndlst *lst, int n)
{
    assert(n <= lst->len);
    int num;
    dlnode *removenode = lst->head ;
    //printf("headd%d\n", removenode->next->data);
    if(n == 1){
        lst->head = removenode->next;
        removenode->next->prev = NULL;
    }


    for ( num = 1; num < n ; num ++){
    //printf("%d\n", removenode->data);
    removenode = removenode->next ;
    }
        //printf("%d\n", removenode->data);
        dlnode *prevnode;
        dlnode *nextnode;    
    if(n == lst->len){
        lst->tail = removenode->prev;
        removenode->prev->next = NULL;
    }    

if(1 < n && n< lst->len){
        prevnode = removenode->prev;
    
//printf("wanted(9):%d\n", prevnode->next->data);
        nextnode = removenode->next;
    
//printf("wanted(9):%d\n", prevnode->next->data);
    if(prevnode->next  &&removenode->prev){
        prevnode->next = nextnode;
                //printf("wanted(9):%d\n", prevnode->next->data);

        nextnode->prev = prevnode;
    }
//printf("%d\n", nextnode->prev->data);
//printf("%d\n", prevnode->data);
}
//printf("geadD%d", lst->head->data);
//dlistPrint(lst);
lst->len--;
free(removenode);

}

// lst is a valid list
void dlistAddToFront(ndlst *lst, int elem)
{
    //dlistPrint(lst);
    dlnode *newnode = malloc(sizeof(dlnode));
    newnode->next = lst->head;    
    if(!(lst->tail)){
        lst->tail = newnode;
    }
    if(lst->head)lst->head->prev = newnode;
    lst->head = newnode;
    newnode->data = elem;
    newnode->prev = NULL;
    lst->len++;
       // printf("head: %d\n", newnode->data);



}

// lst is a valid list
void dlistAddToEnd(ndlst *lst, int elem)
{    

    if(!(lst->head)){
        dlistAddToFront(lst, elem);
    }
    else{        
        //printf("head2: %d\n", lst->head->data);
    
        //dlistPrint(lst);
        dlnode *newnode = malloc(sizeof(dlnode));
        newnode->next = NULL;        
        newnode->data = elem;
        lst->tail->next = newnode;
        newnode->prev = lst->tail;
        lst->tail = newnode;
        lst->len++;
        //printf("tail: %d\n", newnode->data);
        //printf("head2: %d\n", lst->head->data);

    }

    
}

void swap(dlnode *(*node), dlnode *(*prevnode)){
    //printf("%d\n", (*prevnode)->data);
    //printf("%d\n", (*node)->data);

    int big = (*prevnode)->data;
    int small = (*node)->data;
    //printf("big%d\n", big);
    //printf("small%d\n", small);
    (*prevnode)->data = small;
    (*node)->data = big;
    //printf("data: %d\n", (*prevnode)->data);
    //printf("data: %d\n", (*node)->data);
    (*node) = (*prevnode);
    if(!(*prevnode)->prev){
        return;
    }
    (*prevnode) = (*prevnode)->prev;


    //printf("data: %d\n", (*prevnode)->data);
    //printf("data: %d\n", (*node)->data);

}


// lst is a valid list to be sorted in ascending order
void dlistSort(ndlst *lst)
{
    dlnode *node = lst->head ;
    node = node->next;
    //printf("data %d\n", node->data);
    for(; node; node = node->next){
        //printf("1:%d\n", node->data);

        dlnode *prevnode = node->prev;
        //printf("2:%d\n", prevnode->data);
        while(node->data < prevnode->data){
            swap(&node, &prevnode); 
                //printf("data: %d\n", prevnode->data);
                //printf("data: %d\n", node->data);
        }
    }
}

// rotate the list n times to the left, assume, lst not empty
void dlistRotateLeft(ndlst *lst, int n)
{
    for(int i = 0; i < n; i++){
        int front = lst->head->data;
        dlistAddToEnd(lst, front);
        dlistRemoveElem(lst, 1);
    }
    
}

// rotate the list n times to the right, assume, lst not empty
void dlistRotateRight(ndlst *lst, int n)
{
    for(int i = 0; i < n; i++){
        int back = lst->tail->data;
        dlistAddToFront(lst, back);
        dlistRemoveElem(lst, lst->len);
    }
    
}

int main(void)
{
    ndlst *lst1 = dlistCreate();
        dlistPrint(lst1);
    assert(dlistLength(lst1) == lst1->len);
    assert(dlistLength(lst1) == 0);
    dlistAddToEnd(lst1, 10);
    dlistAddToFront(lst1, -20);
 dlistAddToFront(lst1, 0);
 dlistAddToEnd(lst1, 9);
 dlistAddToFront(lst1, -9);
 dlistAddToFront(lst1, 7);
 dlistAddToEnd(lst1, 40);
 assert(dlistLength(lst1) == lst1->len);
 assert(dlistLength(lst1) == 7);
 dlistPrint(lst1);
 dlistPrintReverse(lst1);
 dlistRemoveElem(lst1, 5);
 dlistRemoveElem(lst1, 1);
 dlistRemoveElem(lst1, 5);
 dlistAddToEnd(lst1, 100);
 assert(dlistLength(lst1) == lst1->len);
 assert(dlistLength(lst1) == 5);
 dlistPrint(lst1);
 dlistPrintReverse(lst1);
 dlistSort(lst1);
 dlistPrint(lst1);
 dlistRotateLeft(lst1, 2);
 dlistPrint(lst1);
 dlistRotateRight(lst1, 3);
 dlistPrint(lst1);
 dlistDestroy(lst1);
ndlst *lst2 = dlistCreate();
  dlistAddToFront(lst2, -9);
  dlistAddToFront(lst2, -23);
  dlistAddToFront(lst2, 3);
  dlistAddToFront(lst2, -100);
  dlistAddToFront(lst2, 5);
  dlistAddToFront(lst2, -10);
  dlistAddToFront(lst2, 93);
   dlistPrint(lst2);
 dlistRotateRight(lst2, 12);
 dlistRotateLeft(lst2, 5);
   dlistPrint(lst2);

 dlistSort(lst2);
   dlistPrint(lst2);

 dlistDestroy(lst2);
 return 0;
}

