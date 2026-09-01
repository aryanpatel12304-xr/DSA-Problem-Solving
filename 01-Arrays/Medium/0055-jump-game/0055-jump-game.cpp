class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int x = 0;
        for(int i =  0 ; i<n ; i++){
            if(i>x){
                return 0;
            }
            x = max(x , i + nums[i]);
            if(i>=n-1){
                return true;
            }
        }
        return true;
    }
};