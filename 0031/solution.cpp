#include<bits/stdc++.h>

using namespace std;

void nextPermutation(vector<int>& nums) {

    if(nums.size()==1){
        return;
    }

    vector<int> rest;

    int tmp_max;
    int target_i;

    for(int i=nums.size() - 1;i>=0;i--){

        if(rest.size()==0){
            tmp_max=nums[i];
            rest.push_back( nums[i] );
        }
        else{

            if(tmp_max > nums[i]){
                target_i=i;

                int target=nums[i];                
                auto itr = upper_bound(rest.begin(),rest.end(),target);

                nums[i]=*itr;
                *itr=target;

                break;
            }
            else{
                tmp_max = nums[i];
                rest.push_back( nums[i] );
            }

        }

    }

    if(rest.size() == nums.size()){
        sort(nums.begin(),nums.end());
    }
    else{
        vector<int> ans;

        for(int i=0; i <= target_i  ;i++){
            ans.push_back(nums[i]);
        }
        for(auto x:rest){
            ans.push_back(x);
        }
        nums = ans;
    }

}

int main(void){
    
    vector<int> nums{2,1};

    nextPermutation(nums);

    for(auto n:nums){
        cout << n << endl;
    }

    return 0;
}