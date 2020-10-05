#include<bits/stdc++.h>
using namespace std;
int main(){
	cout << "Prime number for your range";
	long long int left, right;
	cout << "\nEnter your left and right range....\n";
	cin >> left >> right;
	if(left < 2)
		left  = 2;
	if(right < left || right < 2){
		cout << "Invalid Input..!";
		exit(0);
	}
	for(int i = left; i <= right; i++){
		int j = 0;
		
		for(j=2; j<=sqrt(i) ; j++){
			if(i%j == 0)
				break;
		}
		if(j > sqrt(i))
			cout << i << " ";
	}
}
