class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
    //  for(int i = 0 ; i<nums.size() ; i++){
    //     for(int j = i+1 ; j<nums.size() ; j++){
    //         if(nums[i]+nums[j]==target){
    //             return {i,j};
    //         }
    //     }
    //  }
    //  return {};

    //******Optimall********

    map<int,int>ans;
    for(int i = 0 ; i<nums.size() ; i++){
        int n = nums[i];
        int need = target - n;
        if(ans.find(need)!=ans.end()){
            return { ans[need] , i};
        }
        ans[n] = i;
    }
    return {-1,-1};
  
    
    }
};