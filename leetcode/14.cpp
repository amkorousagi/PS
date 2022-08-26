class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string res;
        char current;
        bool is_same = true;
        for(int i=0;;i++){
            if(strs[0].size()==0){
                return res;
            }
            if(strs[0].size() <= i){
                return res;
            }
            current = strs[0][i];
            for(int j=1;j<strs.size();j++){
                if(strs[j].size() <= i){
                    return res;
                }
                if(current != strs[j][i]){
                    is_same = false;
                    break;
                }
            }
            if(is_same){
                res.push_back(current);
            }else{
                break;
            }
        }
        return res;
    }
};