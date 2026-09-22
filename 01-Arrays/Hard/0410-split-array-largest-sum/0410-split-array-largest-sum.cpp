class Solution {
public:
    int students(vector<int>& arr , int pages){
        int st = 0;
        int p = 0;
        for(int i = 0 ; i<arr.size() ; i++){
            if(p + arr[i] <= pages){
                p = p + arr[i];
            }
            else{
                st++;
                p = arr[i];
            }
        }
        return st;
    }
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        int sum = 0;
        int ans = -1;
        for(int i = 0 ; i<n ; i++){
            sum = sum + nums[i];
        }
        int e = sum;
        int s = *max_element(nums.begin()  , nums.end());

        if(k>n){
            return -1;
        }

        while(s<=e){
            int mid = s + (e-s)/2;
            int count = students(nums , mid);
            if(count<k){
                e = mid - 1;
            }
            else{
                s = mid + 1;
            }
        }
        return s;
    }
};