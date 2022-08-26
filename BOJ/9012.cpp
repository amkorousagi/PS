#include <cstdio>
#include <cstdlib>
#include <stack>
using namespace std;



int main(){
    
    int n;
    char str[100];
    
    scanf("%d",&n);
    
    for(int i=0;i<n; i++){
        scanf("%s",str);
        bool success = true;
        stack<char> s;
        for(int j=0;;j++){
            if(str[j]=='('){
                s.push('(');
            }
            else if(str[j] == ')'){
                if (s.size() !=0  && s.top() == '(')
                    s.pop();
                else{
                    printf("NO\n");
                    success = false;
                    break;
                }
            }
            else{
                break;
            }

        }
        if( s.size() == 0 && success == true ){
            printf("YES\n");
            
        }
        else if(success == true){
            printf("NO\n");
        }
        
    }
    
    return 0;
}

