class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n = nums.size();
        int s = 1;
        int e = *max_element(nums.begin() , nums.end());
        int ans = -1;
        while(s<=e){
            int mid = s + (e-s)/2;
            int sum = 0;
            for(int i = 0 ; i<n ; i++ ){
                int d = (nums[i]+mid-1)/mid;
                 sum = sum + d;
            }
            if(sum<=threshold){
                ans = mid;
                e = mid - 1;
            }
            else{
                s = mid + 1;
            }
        }
        return ans;
    }
};