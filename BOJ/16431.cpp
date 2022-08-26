#include <stdio.h>
#include <stdlib.h>



int main(){
    int b_row, b_col, d_row, d_col, j_row, j_col;
    scanf("%d %d",&b_row,&b_col);
    scanf("%d %d", &d_row, &d_col);
    scanf("%d %d",&j_row, &j_col);
    int bj_row, bj_col;
    int dj_row, dj_col;
    int b_t;
    int d_t;
    bj_row = b_row - j_row;
    bj_col = b_col - j_col;
    dj_row = d_row - j_row;
    dj_col = d_col - j_col;


    if(abs(bj_row)<abs(bj_col) ){
        b_t = abs(bj_col);
    }
    else{
        b_t  =abs(bj_row);
    }

    d_t = abs(dj_row)+abs(dj_col);

    if(b_t>d_t){
        printf("daisy\n");
    }
    else if(b_t == d_t){
        printf("tie\n");
    }
    else{
        printf("bessie\n");
    }

    return 0;
}