#include<bits/stdc++.h>

using namespace std;

void add(int n,int l,int r,string s,vector<string>& ans){
    
    if(l==n && r==n){
        ans.push_back(s);
    }
    else{
        if(l>r && l<n){
            add(n,l+1,r,s+'(',ans);
            add(n,l,r+1,s+')',ans);
        }
        else if( l==n){
            add(n,l,r+1,s+')',ans);
        }
        else {
            add(n,l+1,r,s+'(',ans);
        }
    }


}

vector<string> generateParenthesis(int n){

    vector<string> str;

    string s;

    add(n,0,0,s,str);

    return str;

}

int main(void){
    
    int n;
    cin>>n;

    vector<string> s=generateParenthesis(3);

    for(auto ss:s){
        cout << ss << endl;
    }

    return 0;
}