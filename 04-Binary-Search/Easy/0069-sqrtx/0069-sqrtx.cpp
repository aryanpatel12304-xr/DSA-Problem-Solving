class Solution {
public:
    int mySqrt(int x) {
        long s = 1;
        long e = x;
        int ans = 0;
        while(s<=e){
            long long mid = s + (e-s)/2;
            if(mid * mid > x){
                e = mid - 1;
            }
            else{
                ans = mid;
                s = mid + 1;
            }
        }
        return ans;
    }
};