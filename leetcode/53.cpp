class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max = INT_MIN;
        for(int i=0; i<nums.size();i++){
            int sub_max = 0;
            for(int j=i; j<nums.size();j++){
                sub_max += nums[j];
                if(sub_max > max){
                    max = sub_max;
                }
            }
        }
        return max;
    }
};