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
std::vector<int>  SieveOfEratosthenes(int n) 
{ 
    // Create a boolean array "prime[0..n]" and initialize 
    // all entries it as true. A value in prime[i] will 
    // finally be false if i is Not a prime, else true. 
    bool prime[n+1]; 
    memset(prime, true, sizeof(prime)); 
  
    for (int p=2; p*p<=n; p++) 
    { 
        // If prime[p] is not changed, then it is a prime 
        if (prime[p] == true) 
        { 
            // Update all multiples of p greater than or  
            // equal to the square of it 
            // numbers which are multiple of p and are 
            // less than p^2 are already been marked.  
            for (int i=p*p; i<=n; i += p) 
                prime[i] = false; 
        } 
    } 
  	vector<int>v;
    // Print all prime numbers 
    for (int p=2; p<=n; p++) 
       if (prime[p]) 
          v.pb(p);
     return v;      
} 
int productSubSeqCount(vector<int> &arr, int k) 
{ 
    int n = arr.size(); 
    int dp[k + 1][n + 1]; 
    memset(dp, 0, sizeof(dp)); 
  
    for (int i = 1; i <= k; i++) { 
        for (int j = 1; j <= n; j++) { 
     
            // number of subsequence using j-1 terms 
            dp[i][j] = dp[i][j - 1]; 
    
            // if arr[j-1] > i it will surely make product greater 
            // thus it won't contribute then 
            if (arr[j - 1] <= i && arr[j - 1] > 0) 
  
                // number of subsequence using 1 to j-1 terms 
                // and j-th term 
                dp[i][j] += dp[i/arr[j-1]][j-1] + 1; 
        } 
    } 
    return dp[k][n]; 
} 
int main() {
	fastio;
	vector<int>v=SieveOfEratosthenes(1000009);
	int q;
	cin>>q;
	while(q--)
	{
		int n,i,j,count;
		cin>>n;
		count=n-2;
		int root=sqrt(n);
		bool visited[n+2]={false};
		vector<int>issue;
		for(i=2;i<=root;i++)
		{
			if(n%i==0)
			{

				count--;
				if(i*i!=n)
					count--;
				continue;
			}
		}
		for(i=0;i<n;i++)
		{
			if(v[i]>=n)
				break;
			if(n%v[i]!=0)
			{
				int times=n/v[i],currno=v[i];
				for(j=0;j<times;j++)
				{
					currno*=v[i];
					issue.pb(v[i]);
					if(currno>=n)
						break;
				}
			}
		}
		for(i=0;i<issue.size();i++)
		{
			cout<<issue[i]<<" ";
		}
		cout<<endl;
		count-=productSubSeqCount(issue,n);

		cout<<count<<endl;
	}
	return 0;
}