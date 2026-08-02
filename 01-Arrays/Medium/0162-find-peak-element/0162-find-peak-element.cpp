class Solution {
public:
    int findPeakElement(vector<int>& nums) {
    //     int n = nums.size();
    //     for(int i = 0 ; i<n ; i++){
    //         if((i==0 || nums[i-1]<nums[i])&&(i==n-1 || nums[i+1]<nums[i])){
    //             return i;
    //         }
    //     }
    //    return -1;

    int n = nums.size();
    int s = 0;
    int e = n-1;
    while(s<e){
        int mid = (s+e)/2;
        if(nums[mid]<nums[mid+1]){
            s = mid + 1;
        }
        else{
            e  = mid;
        }
    }
    return s;
    }
};