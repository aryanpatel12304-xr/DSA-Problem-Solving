class Solution {
public:
    int findNonMinOrMax(vector<int>& nums) {
        int n = nums.size();
        if(n<=2){
            return -1;
        }
        int l = nums[0];
        for(int i = 1   ; i<n ; i++){
            if(nums[i] > l){
                l = nums[i];
            }
        }

        int s = nums[0];
        for(int i = 1   ; i<n ; i++){
            if(nums[i] < s){
                s = nums[i];
            }
        }

        for(int i = 0 ; i<n ; i++){
            if(nums[i]!=l && nums[i]!=s){
                return nums[i];
            }
        }

        return -1;

    }
};