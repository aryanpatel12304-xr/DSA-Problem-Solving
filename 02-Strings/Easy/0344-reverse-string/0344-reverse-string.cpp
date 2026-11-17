class Solution {
public:

    void dummy(vector<char>&s , int st , int e){
        if(st>=e){
            return;
        }
        swap(s[st] , s[e]);
        dummy(s , st+1 , e-1);
    }
    void reverseString(vector<char>& s) {
        int n = s.size();
        int st = 0;
        int e = n-1;
        dummy(s , st , e);
    }
};