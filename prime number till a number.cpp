#include<bits/stdc++.h>
using namespace std;
int main(){
	cout << "This program prints prime number till particular range....\n";
	long long int num;
	cin >> num;
	long int j;
	for(long int i=2; i<=num; i++){
		for(j=2; j<=sqrt(i); j++){
			if(i%j == 0)
				break;
		}
		if(j > sqrt(i))
			cout << i << " ";
	}
}
