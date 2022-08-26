class Solution {
public:
    int binary_search(vector<int>& nums, int start, int end, int target){
        if(start >= end){
            if(nums[start]<target){
                return start+1;
            }
            return start;
        }
        int mid = (start+end)/2;
        if(nums[mid]<target){
            //타겟미만인 부분을 제거
            return binary_search(nums, mid+1, end, target);
        }else if(nums[mid]>target){
            //타겟 초과인 부분을 제거
            return binary_search(nums, start, mid-1, target);
        }else{
            return mid;
        }
        return -1;
    }
    
    int searchInsert(vector<int>& nums, int target) {
        return binary_search(nums,0,nums.size()-1,target);
    }
};