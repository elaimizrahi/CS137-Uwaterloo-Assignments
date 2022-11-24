 #include <string.h>
 #include <assert.h>
 #include <stdbool.h>
 #include <stdio.h>

bool isPalindrome(int a, int b, char *s, int len){
    printf("a: %d, b: %d\n", a, b);
    int count = 0;
    for(int k = 0; k < len-a; k++){
        printf("b-k%d\n", (b-k));
        printf("k+a%d\n", (a+k));
        printf("count1: %d\n", count);
        if(k+a < len && b-k >= 0){
            printf("pass");
            if(s[k+a] == s[b-k]){
                printf("add\n");
                            count++;
        }
        }

    }
    if(count == b-a+1){
        printf("TRUE a: %d, b: %d\n", a, b);
        return true;
    }
        printf("FALSE a: %d, b: %d\n", a, b);

    return false;
 }


 bool recursive(char *s, int a, int b, int len){
    if(b-a < 2){printf("ghi");
        return false;
    }
    if(b-a == 2){
        if(s[b] == s[a]){
            return true;
        }            

        return false;
    }

printf("a: %d, b: %d\n", a, b);
int count = len;
    for(int i = 1; i < b; i++){    

        printf("i: %d", i);



        if(isPalindrome(a,len-i,s, len)){

            /**/
            if(count == len-i){
                printf("FALSE\n");
                return true;
            }
            if(len-i == len-1){
                                printf("TRUE\n");

                return true;
            }
            printf("count2: %d", len-i);            if(len-i == len-2){
                return false;
                
            }
            if(count+i == len+1){
                printf("ho");
                if(s[count] == s[len-1]){
                    return true;
                }
            }

 
            return recursive(s, len-i+1, len-1, len);

        }           
        count--;   
        
        printf("count3: %d", count);
        //return recursive(s,a,len-i-1, len);
    }
    return false;

 }

 bool is_semidrome(char *s){
    int len = strlen(s);
    int firstcount = 0;
    //if(isPalindrome(3,5,s,len)){
    //}



    int i = 0;
    if(len < 2){
        return false;
    }
    if(len == 2){
        if(s[0] == s[1]){
            return true;
        }
        return false;
    }

    return recursive(s, 0, len-1, len);
    //return false;
 }

 int main(void)
 {
    assert(is_semidrome("popeye"));
assert(is_semidrome("racecar"));
 assert(is_semidrome("bab"));
 assert(!is_semidrome(""));
 assert(!is_semidrome("a"));
 assert(!is_semidrome("popeyeb"));
 assert(is_semidrome("pp"));
 assert(is_semidrome("bababaca"));
 assert(is_semidrome("babbb"));
 assert(is_semidrome("popeye"));
    //assert(!is_semidrome("popbeye"));
    assert(is_semidrome("popbbeye"));
    assert(!is_semidrome("popeyeb"));
    assert(is_semidrome("racecar"));
    assert(!is_semidrome("aab"));
    assert(is_semidrome("aba"));
    assert(is_semidrome("abba"));
    assert(!is_semidrome(""));
    assert(!is_semidrome("a"));
    assert(is_semidrome("aa"));
    assert(!is_semidrome("ab"));
    assert(is_semidrome("bababaca"));
    assert(is_semidrome("ababab"));
 return 0;
 }
