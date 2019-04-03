class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m=matrix.size();
        if(m==0) return;
        int n=matrix[0].size();
        if(n==0) return;
        
        bool first_flag=true;
        int f_row,f_col;
       
        
        for(int i=0;i<m;i++){

            for(int j=0;j<n;j++){
                if(matrix[i][j]==0){
                    if(first_flag){
                        f_row=i;
                        f_col=j;
                        first_flag=false;
                    }
                    else{
                        matrix[f_row][j]=0;
                        matrix[i][f_col]=0;
                    }
                    
                }
            }

        }
        if(first_flag) return;
        /*
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++) cout << matrix[i][j] << " ";
            cout << endl;
        }
        */
        for(int i=0;i<m;i++){
            if(i==f_row) continue;
            if(matrix[i][f_col]==0){
                for(int j=0;j<n;j++){
                    if(j==f_col) continue;
                    else matrix[i][j]=0;
                }
            }
        }
        for(int j=0;j<n;j++){
            if(j==f_col) continue;
            if(matrix[f_row][j]==0){
                for(int i=0;i<m;i++){
                    if(i==f_row) continue;
                    else matrix[i][j]=0;
                }
            }
        }
        for(int i=0;i<m;i++) matrix[i][f_col]=0;
        for(int j=0;j<n;j++) matrix[f_row][j]=0;
        
        
        
    }
};