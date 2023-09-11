class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& matrix) {
        int m = matrix.size(); // no. of rows
        int n = matrix[0].size(); //no. of column
        int maxi = 0 , cnt =0;
        int index = 0; // if no row found still retrun 0
        for(int i =0 ; i<m ;i++){
               cnt = 0;
            for(int j =0 ;j<n; j++){
                if(matrix[i][j] ==1){
                    cnt++;
                }
            }
            if(cnt > maxi ){
                index = i;
            }
            maxi = max(maxi, cnt);
          
        }
    
    return {index , maxi};
    }
};