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

ld pie=3.141592653589793238462643383279;
int mod=1e9+7;

vi vt;

void st(int id,int curr,int l,int r){
  if(l==r){
    if(id==l)vt[curr]=1;
    return ;
  }
  int mid=(l+r)/2;
  if(id>=l && id<=mid) st(id,2*curr+1,l,mid);
  else st(id,2*curr+2,mid+1,r);
  vt[curr]=vt[2*curr+1]+vt[2*curr+2];
}


int gt(int curr,int l,int r,int lx){
  if(r<lx) return 0;
  if(l==r){
    if(l==lx) return vt[curr];
    return 0;
  }
  int mid=(l+r)/2;
  // no , par, com
  if(l>=lx) return vt[curr];
  else return gt(2*curr+1,l,mid,lx) + gt(2*curr+2,mid+1,r,lx);
}

int32_t main(){ 
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
   int n,q; cin>>n>>q;
   int b[32]={0};
   f(i,0,n){
   	int x; cin>>x;
   	int p=0; while(x!=1){
   		x/=2; ++p;
	   }
	   b[p]++;
   }
   while(q--){
   	int x; cin>>x;
   	int tmp[32]; f(i,0,32) tmp[i]=b[i];
   	int req=0;
   	for(int i=31;i>=0;--i){
   		int id=(x>>i)&1;
   		if(id!=0){
   			int take=0,here=1,j=i;
   			while(j>=0){
   				if(here<=tmp[j]){
   					take+=here; tmp[j]-=here; here=0; break;
				   }else{
				   	here-=tmp[j]; take+=tmp[j];
				   	here*=2; tmp[j]=0;
				   }
				  --j;	
			}
			if(here!=0) {
				req=-1; break;
			}else req+=take;
		}
	}
	cout<<req<<"\n";
   }
  return 0; 
}













