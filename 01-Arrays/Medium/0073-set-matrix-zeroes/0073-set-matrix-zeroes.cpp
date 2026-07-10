class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
    //   int row = matrix.size();
    //   int col = matrix[0].size();
    //   for(int i = 0 ; i<row ; i++){
    //     for(int j = 0 ; j<col ; j++){
    //         if(matrix[i][j]==0){
    //             for(int x = 0 ; x<col ; x++){
    //                 if(matrix[i][x]!=0){
    //                     matrix[i][x]=INT_MIN;
    //                 }
    //             }
    //             for(int y = 0 ; y<row ; y++){
    //                 if(matrix[y][j]!=0){
    //                     matrix[y][j]=INT_MIN;
    //                 }
    //             }
    //         }
    //     }
    //   }
    //   for(int i = 0 ; i<row ; i++){
    //     for(int j = 0 ; j<col ; j++){
    //         if(matrix[i][j]==INT_MIN){
    //             matrix[i][j] = 0;
    //         }
    //     }
    //   }
    //   return ;
    //******Optimal******

     int row = matrix.size();
      int col = matrix[0].size();
      vector<int>r(row , 0);
      vector<int>c(col,0);
      for(int i = 0 ; i<row ; i++){
        for(int j = 0 ; j<col ; j++){
            if(matrix[i][j]==0){
                r[i] = 1;
                c[j] = 1;
            }
        }
      }

      for(int i = 0 ; i<row ; i++){
        for(int j = 0 ; j<col ; j++){
            if(r[i]==1 || c[j]==1){
                matrix[i][j] = 0;
            }
        }
      }

      return;

    }
};