class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count = 0;
        int ans = 0;;
        for(int i = 0 ; i<nums.size() ; i++){
            if(nums[i]==1){
                count++;
                if(count>ans){
                    ans = count;
                }
            }
            else if(nums[i]!=1){
                 count = 0;
            }
        }
        return ans;
    }
};