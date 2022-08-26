#include <cstdio>
#include <cstdlib>
#include <stack>
#include <string>
#include <iostream>




using namespace std;

int main(){
    int sum =0;
   
    char prior;
    string s;
    cin >>s;
    stack<char> stack;
    for(int i = 0; i<s.length();i++){
        if(s[i] == '('){
            stack.push(s[i]);

        }
        else{
            if(prior == '('){
                stack.pop();
                sum = sum +  stack.size();
            }
            else{
                
                sum = sum +  1;
                stack.pop();
                
            }

        }
        prior = s[i];


    }
    cout<<sum;
    return 0;
}
