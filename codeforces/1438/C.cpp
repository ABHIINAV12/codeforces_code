#include<bits/stdc++.h> 
using namespace std;
#define int long long
#define ld long double
#define pb push_back
#define ff first
#define ss second
#define f(i,x,n) for(int i=x;i<(int)n;++i)
#define vi vector<int>
#define vvi vector<vector<int>>
#define vvvi vector<vector<vector<int>>>
#define pq priority_queue<int>
#define pqs priority_queue<int,vi,greater<int>>
#define vpii vector<pair<int,int>>
#define pii pair<int,int>
#define all(x) x.begin(),x.end()
#define sz(x) x.size()
#define mpi map<int,int>

int mod=1e9+7;

int dx[]={-1,-1,-1,0,0,1,1,1};
int dy[]={-1,0,1,-1,1,-1,0,1};


string fx(int a){
	string s;
	while(a!=0){
		s+='0'+a%10;
		a/=10;
	}
	reverse(all(s));
	return s;
}


int32_t main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);	
	int t=1; cin>>t;
	f(T,1,t+1){
		int n,m; cin>>n>>m;
		int a[n][m]; f(i,0,n) f(j,0,m) cin>>a[i][j];
		f(i,0,n){
			f(j,0,m){
				if((i+j+a[i][j])%2==1) ++a[i][j];
				cout<<a[i][j]<<" ";
			}
			cout<<"\n";
		}
  	}    
	return 0;
}