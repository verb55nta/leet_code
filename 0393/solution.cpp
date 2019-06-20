class Solution {
public:
    bool validUtf8(vector<int>& data) {
        
        int p=0;

        while(p<data.size()){

            int next;

            if( data[p]<=0x7f ){
                next=0;
            }
            else if( data[p]>=0xc0 && data[p]<= 0xdf ){
                next=1;
            }
            else if( data[p]>=0xe0 && data[p]<= 0xef ){
                next=2;
            }
            else if( data[p]>=0xf0 && data[p]<= 0xf7 ){
                next=3;
            }
            else{
                return false;
            }            
            for(int i=0;i<next;i++){
                p++;
                if(p>=data.size()) return false;
                if( !(data[p]>=0x80 && data[p]<=0xbf) ) return false;
            }
            p++;

        }
        
        return true;

    }
};