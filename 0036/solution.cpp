class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<int> flag(10,0);
        for(int i=0;i<9;i++){
            for(char c:board[i]){
                
                if( c >= '1' && c<= '9' ){
                    
                    if( flag[ c-'0' ]>0 ) return false;
                    else flag[ c-'0' ]++;
                    
                }
                
            }
            vector<int>(10,0).swap(flag);
        }
        
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                char c=board[j][i];
                if( c >= '1' && c<= '9' ){
                    
                    if( flag[ c-'0' ]>0 ) return false;
                    else flag[ c-'0' ]++;
                    
                }
                
            }
            vector<int>(10,0).swap(flag);
        }
        
       for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                
                for(int k=0;k<3;k++){
                    for(int l=0;l<3;l++){
                        
                        char c = board[3*i+k][3*j+l];
                        if( c >= '1' && c<= '9' ){
                    
                        if( flag[ c-'0' ]>0 ) return false;
                        else flag[ c-'0' ]++;
                        }
                    
                    }
                        
                }
                vector<int>(10,0).swap(flag);
            }
                
                
        }

        
        return true;
    }
};