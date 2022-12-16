 #include <string.h>
 #include <stdio.h>
 #include <assert.h>
 #include <stdlib.h>

 //The function "reduce" as found in Chapter 13 of the course notes.
 /*
 void reduce(void *src, size_t n, size_t src_bytes, void *dest, void (*f) (void *, void *))
 {
    if (n == 1){
       f(src, dest);
       return;
    }

    reduce((char *)src+src_bytes, n-1, src_bytes, dest, f); 
    f(src, dest);
 }*/

void reverseConcatenate (void *lhs, void *rhs){
  strcat((char *)rhs, *(char **)lhs);

 }

 void concatenate (void *lhs, void *rhs)
 {   
   char *string = calloc(1001, sizeof(char));
   strcat(string, *(char **)lhs);
   strcat(string, rhs);
   strcpy(rhs, string);
   free(string);
 }
/*
  int main(void)
 {

 int n = 10;
 char *words[] = {"The", "Quick", "Brown", "", "Fox", "Jumps","Over", "The", "Lazy", "Dog"};
 char result[] = "TheQuickBrownFoxJumpsOverTheLazyDog";
 char backwards_result[] = "DogLazyTheOverJumpsFoxBrownQuickThe";

 char answer[1000]; // you may assume that the length of the
 answer[0] = '\0';
 reduce(words, n, sizeof(char *), answer, reverseConcatenate);
 assert(!strcmp(answer, backwards_result));

 answer[0] = '\0';
 reduce(words, n, sizeof(char *), answer, concatenate);
 assert(!strcmp(answer, result));

 return 0;
 }
*/
