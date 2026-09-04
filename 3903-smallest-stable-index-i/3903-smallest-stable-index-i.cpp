class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = -1 ; 
        int ans2 = -1;
        for(int i = 0 ; i<n ; i++){
            ans = max(ans , nums[i]);
            ans2 = *min_element(nums.begin()+i , nums.end());
            int f_ans = ans - ans2;
            if(f_ans<=k){
                return i;
            }
        }
        return -1;
    }
};