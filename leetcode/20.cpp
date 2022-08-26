class Solution {
public:
    bool isValid(string s) {
        vector<char> stack;
        
        for(int i=0; i<s.size();i++){
            switch(s[i]){
                case '(':
                    stack.push_back('(');
                    break;
                case ')':
                    if(stack.size()==0)
                        return false;
                    if(stack.back() == '(')
                        stack.pop_back();
                    else
                        return false;
                    break;
                case '{':
                    stack.push_back('{');
                    break;
                case '}':
                    if(stack.size()==0)
                        return false;
                    if(stack.back() == '{')
                        stack.pop_back();
                    else
                        return false;
                    break;
                case '[':
                    stack.push_back('[');
                    break;
                case ']':
                    if(stack.size()==0)
                        return false;
                    if(stack.back() == '[')
                        stack.pop_back();
                    else
                        return false;
                    break;
            }
        }
        //cout<<stack.size()<<endl;
        if(stack.size() == 0)
            return true;
        return false;
    }
};