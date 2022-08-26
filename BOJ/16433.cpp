#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool ** space;
int n;
int r,c;


void cross();
void carrot_upper();
void carrot_down();
void show_carrot();

int main(){
   
    scanf("%d %d %d",&n,&r,&c);
    space = (bool**)malloc(sizeof(bool*)*n);
    for(int i=0 ;i<n; i++){
        space[i] = (bool*)malloc(sizeof(bool)*n);
    }
    
    for(int i=0; i<n; i++){

        for(int j=0; j<n; j++){
            space[i][j] = false;
        }
    }
   

   
    cross();

    

    carrot_upper();
    

    carrot_down();
    show_carrot();

    free(space);
    return 0;
}

void cross(){
    for(int i = r-1; i>=0; i-=2){
        space[i][c-1] = true;
    }
    for(int i = r-1; i<n; i+=2){
        space[i][c-1] = true;
    }
    for(int i = c-1; i>=0; i-=2){
        space[r-1][i] = true;
    }
    for(int i = c-1; i<n; i+=2){
        space[r-1][i] = true;
    }
}

void carrot_upper(){
    for(int i= r-2; i>=0;i--){
        for(int j=0; j<n; j++){
            if(j ==  c-1) continue;
            space[i][j] = !(space[i+1][j]);
            //printf("%d %d : %d\n",i,j,(int)space[i][j]);
        }
    }
}
void carrot_down(){

    for(int i= r; i<n;i++){
        for(int j=0; j<n; j++){
            if(j ==  c-1) continue;
            space[i][j] = !(space[i-1][j]);
        }
    }
}
void show_carrot(){
    for(int i = 0; i<n; i++){
        for(int j=0; j<n; j++){
            if(space[i][j] == true)
                printf("v");
            else
            {
                printf(".");
            }
            
        }
        printf("\n");
    }

}