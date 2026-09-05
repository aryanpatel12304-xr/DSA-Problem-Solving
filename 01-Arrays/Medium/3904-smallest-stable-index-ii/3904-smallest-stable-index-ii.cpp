class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        // int n = nums.size();
        // for(int i = 0 ; i<n ; i++){
        //      int ans = max(ans , nums[i]);
        //      int ans2 = *min_element(nums.begin()+i, nums.end());

        //      int diff = ans - ans2;
        //      if(diff<=k){
        //         return i;
        //      }
        // }
        // return -1;

        vector<int>ans;
        int n = nums.size();
        int mini  = nums[n-1];
        ans.push_back(nums[n-1]);
       
        for(int i = n-2 ; i>=0 ; i--){
             mini = min(mini , nums[i]);
            ans.push_back(mini);
        }

    reverse(ans.begin() , ans.end());
        int maxi = -1;
        for(int i = 0 ; i<n ; i++){
             maxi = max(maxi , nums[i]);
            int diff = maxi - ans[i];
            if(k>=diff){
                return i;
            } 
        }
        return -1;
    }
};