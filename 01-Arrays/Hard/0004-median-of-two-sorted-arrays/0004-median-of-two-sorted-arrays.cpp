class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
       int n = nums1.size();
       int m = nums2.size();
       vector<int>arr;
       int i = 0;
       int j=0;
        while(i<n && j<m){
            if(nums1[i]<=nums2[j]){
                arr.push_back(nums1[i]);
                i++;
            }
            else{
                arr.push_back(nums2[j]);
                j++;
            }
        }
        for(int x = i ; x<n ; x++){
            arr.push_back(nums1[x]);
        }
        for(int y = j ; y<m ; y++){
            arr.push_back(nums2[y]);
        }

        int a = arr.size();
        float ans = 0;
        if(a%2!=0){
            ans = arr[a/2];
        }
        else{
            ans = (arr[a/2] + arr[a/2 - 1])/2.0;
        }
        return ans;
    }
};