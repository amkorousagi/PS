#include <stdio.h>
#include <stdlib.h>


int main(){
   
    
    int n;
    scanf("%d",&n);

    char* cake = (char*)malloc(sizeof(char)*n);
    scanf("%s",cake);
    int s =0;
    int k =0;
    int* n_s = (int*)malloc(sizeof(int)*n);
    int *n_k = (int*)malloc(sizeof(int)*n);
    int max_start = -1;

    for(int i=0; i<n; i++){
        if(cake[i] == 's'){
            s++;
        }
        else{
            k++;
        }
        n_s[i] = s;
        n_k[i] = k;
    }


    if(n_s[n/2 -1] == n/4){
        max_start = 0;
    }
    
    if(max_start == -1){

    for(int i=0; i<n/2; i++){
        if(n_s[i+n/2-1] - n_s[i-1] == n/4 ){
            max_start = i;
        }
    }

    }
   
   if(max_start == 0){
       printf("1\n%d",n/2);
   }
   else{
       printf("2\n%d %d",max_start, max_start + n/2);
   }
    free(cake);
    free(n_s);
    free(n_k);

    return 0;
}