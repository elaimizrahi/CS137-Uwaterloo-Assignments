#include <stdlib.h>
#include <stdio.h>
typedef struct llnode {
    int data;
    struct llnode *next;
} llnode;
  
typedef struct ll {
    llnode *head;
} ll;

// struct ll *list_create() 
ll *generateList(int n) {
    struct ll *lst = malloc(sizeof(ll));
    llnode *prevnode = malloc(sizeof(llnode));
    lst->head = prevnode;
    prevnode->data = 0;
    prevnode ->next = NULL;
    for (int i = 1; i <= n; i++) {
        struct llnode *curnode = malloc(sizeof(struct llnode));
        curnode->data = i;
        curnode->next = NULL;
        prevnode->next = curnode;
        prevnode = curnode;
    }
    return lst;

}

void llPrint(ll *l) {
    for(llnode *cur = l->head; cur; cur=cur->next) printf("%d->", cur->data);
    printf("NULL");
}
  int main() {
    ll *myList = generateList(5);
    llPrint(myList); // prints "0->1->2->3->4->5->NULL"
}
