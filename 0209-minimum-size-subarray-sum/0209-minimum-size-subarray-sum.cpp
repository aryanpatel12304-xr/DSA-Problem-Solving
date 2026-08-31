class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int i = 0 ;
        int j = 0;
        int ans = INT_MAX;
        int sum = 0;
        while(j<n){
            sum = sum + nums[j];
            j++;
            while(sum>=target){
                ans = min(ans , j-i);
                sum = sum - nums[i];
                i++;
            }
        }
        if(ans==INT_MAX){
            return 0;
        }
        return ans;
    }
};