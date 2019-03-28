#include<bits/stdc++.h>

using namespace std;

int search(vector<int>& nums, int target) {
    int n=nums.size();
    int l=0,r=n-1;
    
    while(l<r){
        cout << l << "," << r << endl;
        int piv=(l+r)/2;

        //if( nums[l] <= nums[piv] && nums[piv+1] <= nums[r]  ){
        if( nums[l]  <= nums[r]  ){
            if( target == nums[piv] ) return piv;
            else if(target >= nums[piv]){
                l= piv+1;
            }
            else{
                r = piv;
            }
        }
        else{
            if( nums[l] <= nums[piv] ){
                if( nums[l] <= target && nums[piv] >= target ){
                    r=piv;
                }
                else{
                    l=piv+1;
                }
            }
            else{
                if( nums[piv+1] <= target && nums[r] >= target ){
                    l=piv+1;
                }
                else{
                    r=piv;
                }
            }
        }

    }

    if(l==r && target == nums[l]) return l;

    return -1;
}

int main(void){
    
    vector<int> nums{4,3};

    cout << search(nums,3) << endl;
    
}