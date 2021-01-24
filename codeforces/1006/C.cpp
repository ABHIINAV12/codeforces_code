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

 
int32_t main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);	
	srand(time(0));
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
	int t=1; //cin>>t;
	while(t--){
		int n; cin>>n;
		int a[n]; f(i,0,n) cin>>a[i];
		int suff[n]; suff[n-1]=a[n-1];
		for(int i=n-2;i>=0;--i) suff[i]=suff[i+1]+a[i];
		int ret=0,here=0;
		f(i,0,n){
			here+=a[i];
			int l=i+1,r=n-1,val=-1;
			while(l<=r){
				int mid=l+r; mid/=2;
				if(suff[mid]==here){
					val=mid;
					break;
				}else if(suff[mid]<here){
					r=mid-1;
				}else l=mid+1;
			}
			if(val!=-1) ret=here;
		}
		cout<<ret;
	}
	return 0;
}

// ============== Notes =============== //
/*
	

*/
