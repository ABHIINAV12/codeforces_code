//  You're not going to master the rest of your life in one day.
//  Just relax. Master the day. 
//  Then just keep doing that every day.
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
#define sz(x) (int)x.size()
#define mpi map<int,int>
#define d1(x,y) cout<<x<<" ----------------------------- "<<y<<"\n"

int mod=1e9+7;

int fx(vector<int> &a){
	sort(all(a));
	int ret=0; f(i,1,sz(a)) ret+=a[i]-a[0];
	int curr=ret; f(i,1,sz(a)){
		int dec=a[i]-a[i-1]; dec*=(sz(a)-i);
		curr-=dec; ret+=curr;
	}
	return ret;
}
 
int32_t main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);	
	srand(time(0));
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
	int t=1; //cin>>t;
	while(t--){
		int n; cin>>n; int a[n]; f(i,0,n) cin>>a[i];
		int curr=0; int val=n;
		f(i,0,n){
			if(a[i]>=curr){
				val+=a[i]-curr;
				curr=a[i];
			}else{
				val+=curr-a[i];
				curr=a[i];
			}
			if(i!=(n-1)) ++val;
		}
		cout<<val;
	}

	return 0;
}

// ============== Notes =============== //
/*
	

*/
