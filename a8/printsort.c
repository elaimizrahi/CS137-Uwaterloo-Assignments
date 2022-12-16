 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>

 void printsorted(char* word, int len){

    int letters[26] = {0};
    for(int i = 0; i < len; i++){
        int a = word[i]-97;
        if(0 < a && a < 26)letters[a]++;
    }

    int count = 0;
    for(int i = 0; i <= len+1; i++){    
        int max = 0;
        for(int j = 0; j < 26; j++){
            //printf("letters:%d\n", letters[j]);
            //printf("letters1:%d\n", letters[max]);
            if(letters[j] > letters[max]){
                max = j;
                //printf("max1:%d\n", max);

            }
        }
        //printf("max2:%d\n", max);
        int newmax = letters[max];
        for(int j = 0; j < newmax; j++){
            printf("%c", max+97);
            i++;

        }
        letters[max] = 0;
    }
    printf("\n");
 }


/*
 int main(void)
 {
 printsorted("hello world!!!", strlen("hello world!!!"));
 printsorted("what's up??", strlen("what's up??"));
 printsorted("spamm and stuff and things", strlen("spamm and stuff and things"));
 printsorted("_", strlen("_"));
 printsorted("epot; wel kq3:4903url/we, 3", strlen("epot; wel kq3:4903url/we, 3"));
 printsorted(" ", strlen(" "));
 return 0;
 }*/