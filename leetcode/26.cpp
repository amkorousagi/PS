class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()==0){
            return 0;  
        }
        int prior = nums[0];
        for(auto it = nums.begin()+1;it!=nums.end();){
            if(prior == *it){
                nums.erase(it);
            }else{
                prior = *it;
                it++;
            }
        }
        return nums.size();
    }
};