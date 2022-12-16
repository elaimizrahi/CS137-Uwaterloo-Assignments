#include <stdio.h>
#include <string.h>
 
int main()
{
    int a[100],b[100];
    int ans[200]={0};
    int i,j,tmp;
    char s1[101],s2[101];
    scanf(" %s",s1);
    scanf(" %s",s2);
    int l1 = strlen(s1);
    int l2 = strlen(s2);
    for(i = l1-1,j=0;i>=0;i--,j++)
    {
        a[j] = s1[i]-'0';
    }
    for(i = l2-1,j=0;i>=0;i--,j++)
    {
        b[j] = s2[i]-'0';
    }
    for(i = 0;i < l2;i++)
    {
        for(j = 0;j < l1;j++)
        {
            ans[i+j] += b[i]*a[j];
        }
    }
    for(i = 0;i < l1+l2;i++)
    {
        tmp = ans[i]/10;
        ans[i] = ans[i]%10;
        ans[i+1] = ans[i+1] + tmp;
    }
    for(i = l1+l2; i>= 0;i--)
    {
        if(ans[i] > 0)
            break;
    }
    printf("Product : ");
    for(;i >= 0;i--)
    {
        printf("%d",ans[i]);
    }
    return 0;
}
/*

// returns the multiplication of t1 and t2. No leading zeros to the left should be kept in the array.
struct linteger * vlintegerMult(struct linteger *t1, struct linteger *t2){
    struct linteger *mult = vlintegerCreate();
    struct linteger *temp1 = vlintegerCreate();
    struct linteger *temp2 = vlintegerCreate();
    int multiple = 0;
    int count1 = 1;
    int count2 = 2;

    (*temp1).length = 2;
    (*temp1).arr = realloc((*temp1).arr, (2)*sizeof(int));
    (*temp2).length = 2;
    (*temp2).arr = realloc((*temp2).arr, 2*sizeof(int));
    (*mult).arr = realloc((*mult).arr, (1)*sizeof(int));
    (*mult).length = 1;
    int num = 0;

    for(int i = (*t2).length-1; i >= 0; i--){
        for(int j = (*t1).length-1; j >= 0; j--){
            (*temp1).arr[0] = (*t1).arr[i]*(*t2).arr[j]/10;
            (*temp1).arr[1] = (*t1).arr[i]*(*t2).arr[j]%10;

            for(int k = 0; k < (*temp1).length; k++){
                printf("temp1: %d\n", (*temp1).arr[k]);
            }

            num = i-j;
            for(int k = 1; k < num+1; k++){
                (*temp1).arr = realloc((*temp1).arr, (2+k)*(sizeof(int)));
                (*temp1).length = 2+k;
                for(int l = 0; l < (*temp1).length-1; l++){
                    if(l == (*temp1).length-2){
                        (*temp1).arr[l+1] = 0;
                                printf("bye");

                    }
                    if(l != (*temp1).length-2){
                        (*temp1).arr[l] = (*temp1).arr[l+1];
                        printf("hi");
                    }
                }
            }
                       
            for(int k = 0; k < (*temp1).length; k++){
                printf("temp11: %d\n", (*temp1).arr[k]);
            }

            mult = vlintegerAdd(mult, temp1);
            for(int k = 0; k < (*mult).length; k++){
                printf("mult: %d\n", (*mult).arr[k]);
            }
            vlintegerDestroy(temp1);
            struct linteger *temp1 = vlintegerCreate();
            (*temp1).length = 2;
                (*temp1).arr = realloc((*temp1).arr, (2)*sizeof(int));


        }
    }


    return mult;
};*/