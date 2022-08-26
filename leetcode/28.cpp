class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.size()==0){
            return 0;
        }
        if(haystack.size() < needle.size()){
            return -1;
        }
        for(int i=0; i<haystack.size();i++){
            if(needle == haystack.substr(i,needle.size())){
                return i;
            }
        }
        return -1;
    }
};