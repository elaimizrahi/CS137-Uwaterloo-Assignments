 #include <stdio.h>
 #include <assert.h>
 #include <string.h>
 #include <stdlib.h>



int shortestRepeatingPrefix(char s[]){
    int length = 0;
    int length2 = (int)strlen(s);
    if(length2 < 2){
        return length2;
    }
    char *comp = (char*)calloc((length2+1),sizeof(char));
    for(int i = 0; i < length2; i++){
        comp[i] = 0;
    }    
    int length3 = (int)strlen(comp);


    for(int i = 0; i < length2; i++){
        strncpy(comp, s, i+1);
        int index = 0;
        int count = 0;
        int length3 = (int)strlen(comp);
        for(int j = i+1; i <  length2; j++){   
            //printf("index0:%d\n", index);            
            if(index > length3-1){
                index = 0;
                //printf("index1:%d\n", index);
            }     
            //printf("sj:%d\n", s[j]);         
            //printf("compi:%d\n", comp[index]); 
            if(s[j] == comp[index]){
                count++;
                index++;
                //printf("index2:%d\n", index);
                //printf("count:%d\n", count);
            }
            else {
                //printf("break\n");
                break;
            }
        }
        int returnvalue = 0;
        for(int k = 0; comp[k] != 0; k++){
            //printf("comp[%d]:%d\n",k, comp[k]);
            returnvalue++;
        }
            //printf("returnvalue:%d\n", returnvalue);

        if(count == (length2) - i-1){
            //printf("index3:%d\n", index);
            //printf("length:%d\n", strlen(comp));
            printf("count:%d\n", returnvalue);
            free(comp);
            return returnvalue;
        }

    }
    //printf("none %d\n", length);

    free(comp);
    return strlen(s);

}

 int main()
 {
 char s1 [] = "hihihihi";
 assert(shortestRepeatingPrefix(s1) == 2);

 char s2 [] = "aaaaa";
 assert(shortestRepeatingPrefix(s2) == 1);

 char s3 [] = "qwerty";
 assert(shortestRepeatingPrefix(s3) == 6);

 char s4 [] = "abcabcabc";
 assert(shortestRepeatingPrefix(s4) == 3); 
 char s5 [] = "applesandhoney";
 assert(shortestRepeatingPrefix(s5) == 14); 
 char s6 [] = "a";
 assert(shortestRepeatingPrefix(s6) == 1); 
 char s7 [] = "abab";
 assert(shortestRepeatingPrefix(s7) == 2); 
 char s8 [] = "helloohelloohelloohelloohelloohelloo";
 assert(shortestRepeatingPrefix(s8) == 6); 
 char s9 [] = "ba";
 assert(shortestRepeatingPrefix(s9) == 2);
 
  char s10 [] = "RaceCar";
 assert(shortestRepeatingPrefix(s10) == 7);

 return 0;
 }

