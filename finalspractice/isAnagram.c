 #include <stdio.h>
 #include <stdbool.h>
 #include <assert.h>
 #include <stdlib.h>

 #define len 'z'-'a'+1

 bool isAnagram(const char *s, const char *t){
    int str[26] = {0};
    int i = 0;
    while(s[i] != '\0'){
                //printf("%d\n", str[i]);

        int a = (int)(s[i] -97);
                //printf("a: %d\n", a);

        if(0<=a && a <26)str[a]++;
        i++;
    }
    i = 0;
    while(t[i] != '\0'){
                printf("%d", str[i]);

        int a = (int)(t[i]-97);
        if(0<=a && a < 26)str[a]--;
        i++;
    }
    for(int i = 0; i < 26; i++){
        printf("str: %d\n", str[i]);
        if(str[i] != 0){
            return false;
        }
    }

    return true;
 }

 int main(void)
 {
char s[] = "gabagool"; 
assert(!isAnagram("a gentleman", "elegant men"));
 assert(isAnagram("election results", "lies - let's recount"));
 assert(!isAnagram("election results", "lies - let recount"));
 assert(isAnagram("the hilton", "hint: hotel"));
 assert(!isAnagram("the hilton", "hint: a hotel"));
 return 0;
 }
