#include<bits/stdc++.h>
using namespace std;
int main(){
	long int test;
	cin >> test;
	for(int loop=0; loop<test; loop++){
		long int num;
		cin >> num;
		long int temp;
		int val = 0;
		int count = 0;
		for(int i=0; i<num; i++){
			cin >> temp;
			count = 0;
			for(int j=1; j<sqrt(temp); j++){
				if(temp%j == 0)
					count += 2;
			}
			if((int)sqrt(temp)*(int)sqrt(temp) == temp)
				count++;
			val = val^count;
		}
		cout << val << "\n";
	}
}
