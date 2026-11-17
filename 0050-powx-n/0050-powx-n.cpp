class Solution {
public:

    double helper(double x , int n){
        if(n==0){
            return 1.0;
        }
        double temp = helper(x , n/2);
        if(n%2==0){
            return temp * temp;
        }
        else{
            return x * temp * temp;
        }
    }
    double myPow(double x, int n) {

        long long N = n;
        if(n<0){
            return 1/helper(x , -N);
        }
        return helper(x , N);
        
    }
};