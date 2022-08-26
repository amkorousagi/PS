#include <bits/stdc++.h>
using namespace std;
int visit[501][501];
int m[501][501];
int row,col;

int vector_x[] = {0,0,1,0,-1};
int vector_y[] = {0,-1,0,1,0};

int search(int x,int y){
    if(x==1&&y==1){
        return 1;
    }
    
    if(visit[y][x]==-1){
        visit[y][x] =0;
        for(int i=1; i<=4; i++){
            int next_x = x + vector_x[i];
            int next_y = y + vector_y[i];

            if(m[next_y][next_x]>m[y][x] && next_x>0&&next_x <=col && next_y >0 &&next_y <= row){
                visit[y][x] += search(next_x,next_y); 
            }
            
        }
    }
    return visit[y][x];
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    //cin>>row>>col;
    scanf("%d %d",&row,&col);
    for(int i=1; i<=row;i++){
        for(int j=1; j<=col;j++){
            //cin>>m[i][j];
            scanf("%d",&m[i][j]);
            visit[i][j] = -1;
        }
    }

    //cout<<search(1,1);
    printf("%d",search(col,row));



    return 0;
}