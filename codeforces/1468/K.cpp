//Abhinav ---IIIT_A
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ld long double
#define pb push_back
#define ff first
#define ss second
#define f(i,x,n) for(int i=x;i<(int)n;++i)
#define vpii vector<pair<int,int>> 
#define vi vector<int>
#define vpii vector<pair<int,int>> 
#define mpii map<pair<int,int>,int>
#define mpivpii map<int,vector<pair<int,int>>> 
#define pii pair<int,int> 
#define all(x) x.begin(),x.end()
#define sz(x) x.size()
#define mpi map<int,int>
#define vvi vector<vector<int>>

ld pie=3.141592653;
int mod=1e9+7;

int dx4[]={-1,1,0,0};
int dy4[]={0,0,1,-1};

map<char,int> mp;

void solve(){
	string s; cin>>s;
	int x=0,y=0;
	for(auto it : s){
		int id=mp[it];
		x+=dx4[id]; y+=dy4[id];
		if(x!=0 || y!=0){
			int xx=0,yy=0;
			for(auto it1 : s){
				int id1=mp[it1];
				int nx=xx+dx4[id1], ny=yy+dy4[id1];
				if(nx!=x || ny!=y) {
					xx=nx; yy=ny;
				}
			}
			if(xx==0 && yy==0){
				cout<<x<<" "<<y<<"\n";
				return ;
			}		
		}
	}
	cout<<"0 0\n";
}


int32_t main(){ 
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  mp['L']=0;
  mp['R']=1;
  mp['U']=2;
  mp['D']=3;
	int t=1; cin>>t;
 	while(t--) solve();
  return 0; 
}













