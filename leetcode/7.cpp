#include <algorithm>
#include <string>

using namespace std;
class Solution {
public:
    int reverse(int x) {
        string str = to_string(x);
        //0 <n
        //[0,n) 0~n-1
        switch(str[0]){
            case '-':
                ::reverse(str.begin()+1,str.end());
                break;
            default :
                ::reverse(str.begin(),str.end());
                break;
        }
        long answer = stol(str);
        if(answer > INT_MAX || answer <INT_MIN){
            return 0;
        }
        return stoi(str);
    }
};