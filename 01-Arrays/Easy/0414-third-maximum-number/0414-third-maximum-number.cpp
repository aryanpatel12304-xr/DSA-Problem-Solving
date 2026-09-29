class Solution {
public:
    int thirdMax(vector<int>& nums) {
      int n = nums.size();
      long long l = nums[0];
      for(int i = 1 ; i<n ; i++){
        if(nums[i]>l){
            l = nums[i];
        }
      }
       if(n==1){
            return l;
        }
      long long  s = LLONG_MIN;
      for(int i = 0 ; i<n ; i++){
        if(nums[i]==l){
            continue;
        }
        else if(nums[i]>s){
            s = nums[i];
        }
      }
      if(s==LLONG_MIN){
        return l;
      }

      long long t = LLONG_MIN;
      for(int i = 0 ; i<n ; i++){
        if(nums[i]==l || nums[i]==s){
            continue;
        }
        else if(nums[i]>t){
            t = nums[i];
        }
      }
      if(t==LLONG_MIN){
        return l;
      }
      else{
        return t;
      }
    }
};