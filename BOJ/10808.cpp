#include <iostream>
#include <string>
#include <iomanip>
#include <vector>


using namespace std;
int main(){
    string s;
    cin>>s;
    int index;
    vector<int> v(26,0);
    
    for(int i=0;i<s.length(); i++){
        index = s[i] - 'a';
        v[index]++;
    }
    
    cout.setf(ios::left);
    
    for(int i=0;i<v.size();i++){
       
        if(v.size()-1==i){
            printf("%d",v[i]);
        }
        else{
            printf("%d ",v[i]);
        }
    }


    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}