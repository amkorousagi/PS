#include <iostream>
#include <stack>
#include <vector>

using namespace std;
vector<long long> side(81,0);

long long recursive(long long count){
    side[1] = 1;
    side[2] = 1;
    if(side[count-1]!=0 && side[count-2] !=0){
        side[count] = side[count-1]+side[count-2];
        return side[count];
    }

    for(int i=3; i<=count;i++){
        side[i] = side[i-1]+side[i-2];
    }
    return side[count];
    /*
    stack<long long> s;
    long long result = 0;
    long long current = 0;
    s.push(count);
    while(s.size()!=0){
        current = s.top();
        s.pop();
        if(current == 1|| current==2){
            result +=1;
        }
        else if(current <=0){

        }
        else{
            s.push(current - 1);
            s.push(current - 2);
        }
    }
    */
    /*
        if(count == 1 || count ==2){
            return 1;
        }
        else if(count <= 0){
            return 0;
        }
        return recursive(count-1)+ recursive(count-2);
    */
    
    
}
int main(){
    long long count;
    cin>>count;
    if(count == 1){
        cout<<4;
    }
    else if(count == 2){
        cout<<6;
    }
    else{
        cout<<(4*recursive(count)+2*recursive(count-1));
    }
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}