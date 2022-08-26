#include <bits/stdc++.h>

using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie();
    cout.tie();

    int male[6]={0,};
    int female[6]={0,};
    int n_s, max_room;

    scanf("%d %d",&n_s,&max_room);
    for(int i=0;i<n_s;i++){
        int sex, grade;
        scanf("%d %d",&sex, &grade);
        if(sex==0){
            female[grade-1]++;
        }
        else{
            male[grade-1]++;
        }
    }
    int sum =0;
    
    sum = (int)ceil((male[0]+male[1]+female[0]+female[1])/(float)max_room);
    
    for(int i=2; i<6;i+=2){
        sum += (int)ceil((male[i]+male[i+1])/(float)max_room) + (int)ceil((female[i]+female[i+1])/(float)max_room);
    
    }
    printf("%d",sum);


    return 0;
}