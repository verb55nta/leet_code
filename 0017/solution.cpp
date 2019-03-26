#include<bits/stdc++.h>

using namespace std;

vector<string> dig_map = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

vector<string> letterCombinations(string digits) {

    vector<string> str;
    
    if(digits.size()==0){
        return str;
    }
    
    char _c = digits[0];

    for(char c: dig_map[ _c - '0' ] ){
    
        vector<string> tmp_str = letterCombinations(digits.substr(1));
        if(tmp_str.size()==0) tmp_str.push_back("");
    
        for(string s:tmp_str){
            string _s="";
            _s+=c;
            _s+=s;
            str.push_back(_s);
        }
        
    }
    
    return str;

}

int main(void){
    
    string digits;    
    cin>>digits;

    //digits="2";
    /*
    dig_map[2] += "abc";
    dig_map[3] += "def";
    dig_map[4] += "ghi";
    dig_map[5] += "jkl";
    dig_map[6] += "mno";
    dig_map[7] += "pqrs";
    dig_map[8] += "tuv";
    dig_map[9] += "wxyz";
    */
    
    vector<string> s=letterCombinations(digits);

    for(auto ss:s){
        cout << ss << endl;
    }

    return 0;
    
}