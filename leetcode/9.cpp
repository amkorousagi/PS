#include <algorithm>
#include <string>
class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0){
            return false;
        }
        string str = to_string(x);
        reverse(str.begin(),str.end());
        if(x == stoll(str)){
            return true;
        }
        return false;
    }
};