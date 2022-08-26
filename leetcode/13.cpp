class Solution {
public:
    int roman(char c){
        switch(c){
            case 'I' : return 1;
            case 'V' : return 5;
            case 'X' : return 10;
            case 'L' : return 50;
            case 'C' : return 100;
            case 'D' : return 500;
            case 'M' : return 1000;
            default : return 0;
        }
    }
    
    int romanToInt(string s) {
        int prior = roman(s[0]);
        int current;
        int sum = 0;
        for(int i=1; i<s.size();i++){
            current = roman(s[i]);
            if(prior >= current){
                sum += prior;
            }else{
                sum -= prior;
            }
            prior = current;
            
        }
        sum += prior;
        return sum;
    }
};