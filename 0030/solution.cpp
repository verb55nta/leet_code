class Solution {



public:
  vector<int> findSubstring(string s, vector<string>& words) {

    auto pa1 = [](const pair<string,int> p){ cout << p.first << "," << p.second << endl; };
    auto pa2 = [](const pair<int,string> p){ cout << p.first << "," << p.second << endl; };

    if(words.size()==0) return vector<int>(0);
    string tmp_s=words[0];
    if(tmp_s.size()==0) return vector<int>(0);

    auto w=words.size();
    auto n=tmp_s.size();
    auto s_n=s.size();

    //set<string> se_w;

    map<string,int> cor;

    for(auto ss:words){

      if( cor.find(ss) == end(cor) ) cor[ss]=1;
      else cor[ss]++;

    }

    vector< map<string,int> > m(n);

    for(int i=0;i<n;i++){
      for(auto ww:words) m[i][ww]=0;
    }

    //vector<set< pair<int,string> >> se(n);

    vector<int> ans;

    for(int i=0;i<n;i++){

      for(int j=0;j<w && i+n*j<s_n;j++){
	tmp_s=s.substr(i+n*j,n);
	if( m[i].find(tmp_s) != end(m[i]) ){
	  m[i][tmp_s]++;
	}

      }

      for(auto p:m[i]){
	//pa1(p);
	//se[i].insert( make_pair(p.second,p.first) );
      }
      //cout << i << endl;
      //for(auto p:se[i]) pa2(p);
      //cout << i << "," << (*begin(se[i])).first << endl;
      //if( (*begin(se[i])).first == 1 ) ans.push_back(i);.
      bool mat=true;

      for(auto p:m[i]){
	if( cor[p.first] != p.second ) mat=false;
      }

      if(mat) ans.push_back(i);

    }

    for(int i=0;i<n;i++){

      for(int j=1;n*j+i + n*(w-1)<s_n;j++){

	auto s_rem=s.substr(n*(j-1)+i,n);
	auto s_ins=s.substr(n*j+i + n*(w-1) ,n);

	//cout << i << "," << s_rem << "," << s_ins << endl;
	if( m[i].find(s_rem) != end(m[i]) ){

	  //se[i].erase( make_pair(m[i][s_rem],s_rem) );

	  m[i][s_rem]--;

	  //se[i].insert( make_pair(m[i][s_rem],s_rem) );
	}


	if( m[i].find(s_ins) != end(m[i]) ){

	  //se[i].erase( make_pair(m[i][s_ins],s_ins) );

	  m[i][s_ins]++;

	  //se[i].insert( make_pair(m[i][s_ins],s_ins) );

	}

	bool mat=true;

	for(auto p:m[i]){
	  if( cor[p.first] != p.second ) mat=false;
	}

	if(mat) ans.push_back(n*j+i);


	//cout << i << "," << (*begin(se[i])).first << endl;
	//if( (*begin(se[i])).first == 1 ) ans.push_back(n*j+i);

      }

    }

    return ans;
  }
};
