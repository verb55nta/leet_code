#include<bits/stdc++.h>

using namespace std;

int main(void){
    
    //vector<int> nums={2,3,1,1,4};
    vector<int> nums={3,2,1,0,4};

    int n=nums.size();

    if(n==1){
        cout << "Yes" << endl;
        return 0;
    }

    vector<int> dp(n,0);

    dp[0]=1;

    for(int i=0;i<n;i++){

        if( dp[i]==1){
            for(int j=i;j<=i+nums[i] && j<n;j++){
                dp[j]=1;
            }
        }

    }

    for(auto x:dp){
        cout << x << ",";
    }
    cout << endl;
    
    if(dp[n-1]){
        cout  << "Yes" << endl;
        return 0;
    }

    cout << "No" << endl;

    return 0;

}