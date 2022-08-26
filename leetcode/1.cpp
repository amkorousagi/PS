#include <cstdio>
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        //nums 에 있는 두 개 숫자를 골라서 그 합을 본다. 모든 경우에 다 해본다.
        for(int i=0; i< nums.size();i++){
            int sum = nums[i];
            for(int j=0; j<nums.size();j++){
                if(i!=j){
                    sum += nums[j];
                    //std::printf("%d",sum);
                    if(target == sum){
                        vector<int> answer;
                        answer.push_back(i);
                        answer.push_back(j);
                        return answer;
                    }
                }
                //아닐 경우 sum을 초기화,
                //그렇지 않으면 "두 개"의 합이 아니게 된다
                sum = nums[i];
            }
        }
        vector<int> answer;
        return answer;
    }
};