/******************************************
* AUTHOR : Lokesh goel*
* NICK : InsaneNerd *
* INSTITUTION : NIT Kurukshetra *
******************************************/
#include <bits/stdc++.h>
using namespace std;
#define ll long long

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"


int main() {
	fastio;
	ll a,b,n;
	cin>>a>>b>>n;	
	ll int i,j=0,k;
	vector<int>total(32003,1),prime(100000);
	for(i=2;i<=180;i++)
	{
		if(total[i]==1)
		{
			for(j=2;j*i<=32000;j++)
			{

				total[i*j]=0;
			}
		}
	}
	ll res=0,root=sqrt(b)+1;
	j=0;
	for(i=2;i<=root;i++)
	{
		if(total[i]==1)
		{
			prime[j++]=i;
		}
	}
	for(i=a;i<=b;i++)
	{
		ll temp=i;
		ll ans=1;
		j=0;
		k=prime[j];
		while(1)
		{
			if(k*k>temp)
			{
				break;
			}
			ll int count=0;
			k=prime[j];
			if(k==0)
				break;
			while(temp%k==0)
			{
				count++;
				temp/=k;
			}
			j++;
			ans=ans*(count+1);
		}
		if(temp!=1)
		{
			ans*=2;
		}
		if(ans==n)
			res++;
	}
	cout<<res<<endl;
	return 0;
}