class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        
        int dir[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
        
        if(matrix.size()==0) return vector<int>(0);
        
        int mat_row=matrix.size();
        int mat_col=matrix[0].size();
        
        vector<int> ans;
        
        vector< vector<bool> > check( mat_row,vector<bool>(mat_col,false) );
        int row=0;
        int col=0;
        
        int push_cnt=0;
        
        for(int i=0;;i++){
            
            while( row >= 0 && row< mat_row && col >= 0 && col < mat_col && 
                  check[row][col]==false ){
                
                
                //cout << row << "," << col << endl;
                
                ans.push_back( matrix[row][col] );
                check[row][col]=true;
                push_cnt++;
                row+=dir[i%4][0];
                col+=dir[i%4][1];
                
            }
            if(push_cnt >= mat_row*mat_col) return ans;
            row-=dir[i%4][0];
            col-=dir[i%4][1];
            row+=dir[(i+1)%4][0];
            col+=dir[(i+1)%4][1];
            
            
        }
        return ans;
    }
};