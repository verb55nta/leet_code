class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        
        int n=matrix.size();
        
        for(int i=0;i<n/2;i++){
            for(int j=i;j<n-1-i;j++){
                //cout << i << "," << j << endl;
                int x[4][2];
                x[0][0]=i,x[0][1]=j;
                x[1][0]=j,x[1][1]=n-1-i;
                x[2][0]=n-1-i,x[2][1]=n-1-j;
                x[3][0]=n-1-j,x[3][1]=i;
                
                int tmp_from=matrix[x[0][0]][x[0][1]];
                
                for(int cnt=1;cnt<4;cnt++){
                    //cout << x[cnt][0] << "," << x[cnt][1] << endl;
                    int tmp_to=matrix[x[cnt][0]][x[cnt][1]];
                    matrix[x[cnt][0]][x[cnt][1]] = tmp_from;
                    tmp_from=tmp_to;
                    
                }
                matrix[x[0][0]][x[0][1]] = tmp_from;
                
            }
        }
        
    }
};