class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // int n = nums.size();
        // vector<int>ans;
        // for(int i = 0 ; i<n ; i++){
        //     int pro = 1;
        //     for(int j = 0 ; j<n ; j++){
        //         if(i == j){
        //             continue;
        //         }
        //         else{
        //             pro = pro * nums[j];
        //         }
        //     }
        //     ans.push_back(pro);
        // }
        // return ans;
         int n = nums.size();
        vector<int>ans(n);
     ans[0] = 1;
     for(int i = 1 ; i<n ; i++){
        ans[i] = ans[i-1] * nums[i-1];
     }

     int suffix = 1;
     for(int i = n-1 ; i>=0 ; i--){
        ans[i] = ans[i] * suffix;
        suffix = suffix * nums[i];
     }
     return ans;
    }
};