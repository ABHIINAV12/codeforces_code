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
	int t; cin>>t;
	while(t--){
		int n; cin>>n;
		int a[n]; f(i,0,n) cin>>a[i];
		int sum=0; f(i,0,n) sum+=a[i];
		int mx=0; f(i,0,n) mx=max(mx,a[i]);
		int k=max(((sum+n-2)/(n-1)),mx);
		int val=k*(n-1)-sum;
		cout<<val<<"\n";
	}
	return 0;
}

// ============== Notes =============== //
/*
	Since nephew emptying the box i he's chosen and wants to make all other n−1 box equal then it means that at least the sum of all array a should be divisible by (n−1) and the number of blocks in each other box should be at least ⌈sumn−1⌉ (ceiling function).

On the other side, since nephew chooses i (not you), then he can choose a box which is not a maximum max, and since he makes empty the only box i, then the final number in each other block should be at least max.

In total, the resulting number of blocks in each of n−1 other boxes should be at least k=max(⌈sumn−1⌉,max) and we need to add at least (n−1)⋅k−sum elements to the initial array.

We can always reach this lower bound if we will put each block in the box with the current minimum number of blocks.

*/
