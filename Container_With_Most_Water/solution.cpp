class Solution {
public:
    int maxArea(vector<int>& height) {
        int max_vol=0;
        for(int i=0;i<height.size();i++){
            for(int j=i+1;j<height.size();j++){
                if( min(height[i],height[j]) * (j-i) > max_vol ){
                    max_vol=min(height[i],height[j]) * (j-i);
                }
            }
        }
        return max_vol;
    }
};