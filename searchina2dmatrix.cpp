class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        int m=matrix[0].size();
        int left=0;
        int high=(m*n)-1;
        
        while(left<=high){
            int mid=(left+high)/2;
            int row=mid/m;
            int col=mid%m;
            if(matrix[row][col]>target){
                high=mid-1;
            }else if(matrix[row][col]==target){
                return true;
            }else{
                left=mid+1;
            }
        }

        return false;

    }
};