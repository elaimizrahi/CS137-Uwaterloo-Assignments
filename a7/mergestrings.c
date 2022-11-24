 #include <stdio.h>
 #include <assert.h>
 #include <stdlib.h>
 #include <string.h>

int strappend(char *final, char *s, int a, int b, int count){
    for(int i = a; i < b; i++){
        final[count] = s[i];
        count++;
    }
    return count;
}




char* merge (char* s1, char* s2){
    int length1 = strlen(s1);
    int length2 = strlen(s2);
    int totalcount = 0;
        
    char *final = (char*)calloc((length1+length2+10),sizeof(char));
    for(int i = 0; i < length1 + length2; i++){
        final[i] = 0;
    }    
    int length3 = (int)strlen(final);
    int count = 0;
    int wordcount = 0;

    for(int i = 0; i < length1; i++){
        if(s1[i] == 32){
            wordcount++;
        }
    }
        
    for(int i = 0; i < length2; i++){
        if(s2[i] == 32){
            wordcount++;
        }
    }
    wordcount += 2;
    int index1 = 0;
    int index2 = 0;
    for(int i = 0; i < wordcount; i++){
        count++;
        if(count%2 == 1){
            int index3 = index1 + 1;
            if(index1 == 0){
                index3 = 0;
            }
            while(s1[index3] != 32 && index3 < length1 && s1[index3] != 0){               
                index3++;

            }
            if(s1[index3] == 0){
                totalcount = strappend(final, s1, index1, index3, totalcount);
                totalcount++;
                int count5 = 1;
                while(s2[index2-1] != 0){
                    final[totalcount] = s2[index2];
                    index2++;
                    totalcount++;
                    count5++;
                }
                final[totalcount-count5] = 32;

                final[totalcount] = 0;
                return final;
            }  
            index3++;

            totalcount = strappend(final, s1, index1, index3, totalcount);
            index1 = index3;
        }
        if(count%2 == 0){
            int index4 = index2 + 1;
            if(index2 == 0){
                index4 = 0;
            }
            while(s2[index4] != 32 && index4 < length2 && s2[index4] != 0){
                index4++;
            }
            if(s2[index4] == 0){
                totalcount = strappend(final, s2, index2, index4, totalcount);
                totalcount++;
                int count5 = 1;
                while(s1[index1-1] != 0){
                    final[totalcount] = s1[index1];
                    index1++;
                    totalcount++;
                    count5++;
                }
                final[totalcount-count5] = 32;

                final[totalcount] = 0;
                return final;
            }
            index4++;
            totalcount = strappend(final, s2, index2, index4, totalcount);

            index2 = index4;

        }

    }
    return final;
}

 int main(void)
 {
 char s1[] = "The brown jumps the dog";
 char s2[] = "quick fox over lazy";

 char *s = merge(s1, s2);
 assert(!strcmp(s, "The quick brown fox jumps over the lazy dog"));
 free(s);

 char s3[] = "the brown";
 char s4[] = "quick fox is sleeping today";
 s = merge(s3,s4);
 assert(!strcmp(s, "the quick brown fox is sleeping today"));
 free(s);

 char* s5 = "happy to you";
 char* s6 = "birthday";
 s = merge(s5,s6);
 assert(!strcmp(s, "happy birthday to you"));
 free(s);
 char* s7 = "hello a hello";
 char* s8 = "birthday";
 s = merge(s7,s8);
 assert(!strcmp(s, "hello birthday a hello"));
 free(s);
  char* s9 = "hello a hello whats up I dont know but I'm just typing";
 char* s10 = "birthday and stuff and things and stuff and things";
 s = merge(s9,s10);
 assert(!strcmp(s, "hello birthday a and hello stuff whats and up things I and dont stuff know and but things I'm just typing"));
 free(s);
 /*
  char* s11 = "hello a hello";
 char* s12 = "birthday";
 s = merge(s11,s12);
 assert(!strcmp(s, "hello birthday a hello"));
 free(s);
  char* s13 = "hello a hello";
 char* s14 = "birthday";
 s = merge(s13,s14);
 assert(!strcmp(s, "hello birthday a hello"));
 free(s);*/
 return 0;
 }