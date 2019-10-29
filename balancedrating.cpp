/******************************************
* AUTHOR : Lokesh goel*
* NICK : InsaneNerd *
* INSTITUTION : NIT Kurukshetra *
******************************************/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MAX 1000000000
#define N 100005
#define pii pair<int,int>
#define vp vector<pair<int,int > >
#define mod 1000000007
#define pb push_back
#define mp make_pair
#define gsz(x) ((int)(x).size())
#define F first
#define S second
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"
#define ms(x,v) memset(x,v,sizeof(x))
int main() {
	fastio;

	int n,sum=0,i,j,arr[14000],newarr[14000];
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>arr[i];
		newarr[i]=arr[i]/2;
		sum+=newarr[i];
	}
	if(sum==0)
	{
		for(i=0;i<n;i++)
		{
			cout<<newarr[i]<<endl;
		}
	}
	else if(sum<0)
	{
		int diff=0-sum;

		for(i=0;i<n;i++)
		{
			if((arr[i]+1000000000)%2==1&&arr[i]>0)
			{
				newarr[i]++;
				diff--;
				if(diff==0)
					break;
			}
		}
		for(i=0;i<n;i++)
		{
			cout<<newarr[i]<<endl;
		}
	}
	else
	{
		int diff=sum;
		//cout<<"diff "<<diff<<endl;
		for(i=0;i<n;i++)
		{
			if((arr[i]+10000000)%2==1&&arr[i]<0)
			{
				//cout<<"Yes"<<endl;
				newarr[i]--;
				diff--;
				if(diff==0)
					break;
			}
		}
		for(i=0;i<n;i++)
		{
			cout<<newarr[i]<<endl;
		}
	}
	

	return 0;
}