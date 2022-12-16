  #include <stdio.h>
  #include <stdlib.h>

 struct lnode{
    int val; 
    struct lnode *next;
 };
 struct nlst{
    struct lnode *head;
    int len;
 };

 //Pre: None
 //Post: Creates a null intlst
 struct nlst *listCreate(void){
    struct nlst *list = malloc(sizeof(struct nlst));
    list->head = NULL;
    list->len = 0;
    return list;
 }

 //Pre: lst is a valid list ( even null )
 //Post: Destroys the list
 void listDestroy(struct nlst *lst){
    struct lnode *prev = lst->head;
    struct lnode *cur = NULL;
    while(prev){
        cur = prev;
        prev = prev->next;
        free(cur);
    }
    free(lst);
 }


 // lst is a valid list
 void listAddToFront(struct nlst *lst, int elem){
    struct lnode *node = malloc(sizeof(struct lnode));
    node->val = elem;
    node->next = lst->head;
    lst->head = node;
    lst->len++;
    //printf("head: %d", lst->head->val);
 }

 //Pre: lst is a valid list with length of at least n
 //Post: nth item removed
 struct nlst *listRemoveElem(struct nlst *lst, int n){
    struct lnode *node = lst->head;
    struct lnode *prev = lst->head;
    node = node->next;
    for(int i = 0; i < n; i++){
        prev = node;
        node = node->next;
    }
    prev->next = node->next;
    node->next = NULL;
    free(node);
    return lst;
 }

 //Pre: lst is valid
 //Post: returns the number of elements in the list
 int listLength(struct nlst *lst){
    return lst->len;
 }

 //Pre: lst is valid
 //Post: returns a reversed copy of it.
 struct nlst *listReverseCopy(struct nlst *lst){
    struct nlst *newlist = malloc(sizeof(struct nlst));
    newlist->head = NULL;
    newlist->len = 0;
    struct lnode *rev = lst->head;
    while(rev){
        struct lnode *node = malloc(sizeof(struct lnode));
        node->val = rev->val;
        node->next = newlist->head;
        newlist->head = node;
        newlist->len++;
        rev = rev->next;
    }
    return newlist;
 }


 //Pre: lst is valid
 //prints the items in the list from start to end.
 void listPrint(struct nlst *lst){            //printf("hi");

   if(!(lst->head)){
       return;
   }
    struct lnode *node = lst->head;
    while(node->next){        
        printf("%d->", node->val);
        node = node->next;
    }
    printf("%d", node->val);
    printf("\n");
 }


 //Pre: lst is valid
 //mutates a a list after multiplying each element by an int factor.
 void listScaleFactor(struct nlst *lst, int factor){
    struct lnode *node = lst->head->next;
    while(node){
        node->val = (node->val) * factor;
        node = node->next;
    }
 }


 int main(void)
 {
 struct nlst *lst1 = listCreate();
 listAddToFront(lst1, 10);
 listAddToFront(lst1, -20);
 listAddToFront(lst1, 0);
 listAddToFront(lst1, 9);
 listAddToFront(lst1, -9);
 listAddToFront(lst1, 7);
 listAddToFront(lst1, 40);
 printf("length = %d\n", listLength(lst1));
 listPrint(lst1);
 listRemoveElem(lst1, 5);
 listPrint(lst1);
 listScaleFactor(lst1, 10);
 listPrint(lst1);
 struct nlst *lst2 = listReverseCopy(lst1);
 listDestroy(lst1);
 listPrint(lst2);
 listDestroy(lst2);
 return 0;
 }