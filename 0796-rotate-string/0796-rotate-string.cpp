class Solution {
public:
    bool rotateString(string s, string goal) {
        int n = s.length();
        // for(int i = 0 ; i<n ; i++){
        //     for(int j = n-1 ; j>0 ; j-- ){
        //         swap(s[j] , s[j-1]);
        //     }
        //     if(s==goal){
        //         return true;
        //     }
        // }
        // return false;
        if(n!=goal.length()){
            return false;
        }
        string temp = s + s;
        if(temp.find(goal)!=string::npos){
            return true;
        }
        return false;
    }
};