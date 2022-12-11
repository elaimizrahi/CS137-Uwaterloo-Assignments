 #include <stdio.h>
 #include <stdlib.h>

 // Given. Do not change

 typedef struct cell {
 int i, j;
 int value;
 struct cell *next;
 } cell;

 typedef struct sparsematrix {
 cell *head;
 int rows, cols;
 } sparsematrix;

 //create a single cell
 cell *createCell(int i, int j, int value)
 {
 cell *c = malloc(sizeof(cell));
 c->i = i;
 c->j = j;
 c->value = value;
 c->next = NULL;
 return c;
 }

 //create a matrix
 sparsematrix *createMatrix(int rows, int cols)
 {
 sparsematrix *m = malloc(sizeof(sparsematrix));
 m->head = NULL;
 m->rows = rows;
 m->cols = cols;
 return m;
 }



 int MatrixLength(sparsematrix *sm)
  {
 int len = 0;
 cell *p = sm->head;
 // iterate over the nodes (items) until node is NULL
 // and count
 for (; p; p = p->next)
 len++;
 return len;
 }


 // To Complete
 void DestroyMatrix(sparsematrix *sm)
 {
    cell *nextcell = sm->head;
    cell *curcell = NULL;
    while(nextcell){
        curcell = nextcell;
        nextcell = nextcell->next;
        curcell->i = 0;
        curcell->j = 0;
        curcell->value = 0;
        free(curcell);
    }
    free(sm);
 }

 //remove the specified cell from matrix
 void removeCell(sparsematrix *sm, cell *c)
 {
    cell *prev = sm->head;
    while((prev->j)!=(c->j)-1 && (prev->i)!=(c->i)){
        prev = prev->next;
    }
    prev->next = c->next;
    c->next = NULL;
    free(c);
 }

 // get the number of rows in a matrix
 int getNumberOfRows(const sparsematrix *sm)
 {
    cell *cell = sm->head;
    while(cell->next){
        cell = cell->next;
    }
    return cell->i;
    
 }

 // get the number of cols in a matrix
 int getNumberOfCols(const sparsematrix *sm)
 {
    cell *cell = sm->head;
    while(cell->next){
        cell = cell->next;
    }
    return cell->j;
 }

 // returns a pointer to cel[i,j] otherwise NULL
 cell *find(const sparsematrix *sm, int i, int j)
 {
    cell *cell = sm->head;
    while(cell->i != i && cell->j != j){
        if(!(cell->next)){
            return NULL;
        }
        else{
            cell = cell->next;
        }
    }
    return cell;
 }

 // returns the value in cell[i,j]
 int getValue(const sparsematrix *sm, int i, int j)
 {
    cell *cell = sm->head;
    while(cell->i != i && cell->j != j){
            cell = cell->next;
        
    }
    return cell->value;
 }

 //set a value in [i,j]. Be careful of different cases.
 // review the test cases
 void setValue(sparsematrix *sm, int i, int j, int val)
 {
    cell *cell = createCell(i,j,val);        
    struct cell *prev = sm->head;            //printf("hi");

    if(!(sm->head)){
        sm->head = cell;
    }
    else{
        while((cell->i) >= (prev->i) && (cell->j) > prev->j){
            printf("hi\n");
            prev = prev->next;
        }
        cell->next = prev->next;
        prev->next = cell;
    }
 }
 //print a matrix
 void printm(const sparsematrix *m)
 {
 int i, j, val;
 for (i = 0; i < getNumberOfRows(m); i++)
 {
 for (j = 0; j < getNumberOfCols(m); j++)
 {
 val = getValue(m, i, j);
 printf("%d ", val);
 }
 printf("\n");
 }
 printf("\n");
 }
 // add matrix a and matrix b of the same size.
 //sparsematrix *add(const sparsematrix *a, const sparsematrix *b)
 //{
//
 //}
 // // For testing. Make sure to check for memory leaks using valgrind.

 int main(void)
 {
 sparsematrix *a = createMatrix(3, 4);
 setValue(a, 0, 0, 3);            printf("hi");

 setValue(a, 1, 1, 5);
 //setValue(a, 1, 2, 4);
 //setValue(a, 2, 3, 1);
 ////printf("%d\n", MatrixLength(a));
 //printm(a);
//
 //sparsematrix *b = createMatrix(3, 4);
 //setValue(b, 0, 3, 1);
 //setValue(b, 1, 1, -5);
 //setValue(b, 2, 0, 10);
 //printf("%d\n", MatrixLength(b));
 //printm(b);
 //sparsematrix *c = add(a, b);
 //printf("%d\n", MatrixLength(c));
 //printm(c);
 //setValue(c, 2, 0, 0);
 //printf("%d\n", MatrixLength(c));
 //printm(c);
 DestroyMatrix(a);
 //DestroyMatrix(b);
 //DestroyMatrix(c);
 return 0;
 }