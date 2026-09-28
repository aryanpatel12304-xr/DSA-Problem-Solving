class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int>arr;
        int n = nums.size();
        int s = 0;
        int e = n-1;
        int ans = -1;
        while(s<=e){
            int mid = s + (e-s)/2;
            if(nums[mid]==target){
                ans = mid;
                e = mid - 1;
            }
            else if(nums[mid]<target){
                s = mid + 1;
            }
            else{
                e = mid - 1;
            }
        }
        arr.push_back(ans);

        s = 0;
        e = n-1;
        ans = -1;
           while(s<=e){
            int mid = s + (e-s)/2;
            if(nums[mid]==target){
                ans = mid;
                s = mid + 1;
            }
            else if(nums[mid]<target){
                s = mid + 1;
            }
            else{
                e = mid - 1;
            }
        }
        arr.push_back(ans);
        return arr;
    }
};