class Solution {
public:
    int majorityElement(vector<int>& nums) {
       
       // ----Brute---

        // int s = nums.size();
        // for(int i = 0 ; i<nums.size() ; i++){
        //     int count = 0;
        //     for(int j = 0 ; j<nums.size() ; j++){
        //         if(nums[i]==nums[j]){
        //             count++;
        //         }

        //     }
        //     if(count>s/2){
        //          return nums[i];
        //     }
        // }
        // return -1;


        // ---Better---

    //   map<int,int>ans;
    //   for(int i = 0 ; i<nums.size() ; i++){
    //     ans[nums[i]]++;
    //   }
    //   for(auto it : ans){
    //     if(it.second >(nums.size()/2)){
    //         return it.first;
    //     }
    //   }
    //   return -1;

    

        // ---- Optimal ----

      int count = 0;
      int ans = -1;
      for(int i = 0 ; i<nums.size() ; i++){
        if(count==0){
            ans = nums[i];
       
        }
        if(ans == nums[i]){
            count++;
        }
        else{
            count--;
        }
      }
      return ans;
    }
};