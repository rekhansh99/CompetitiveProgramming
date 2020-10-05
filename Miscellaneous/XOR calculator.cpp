#include<bits/stdc++.h>
using namespace std;
int main(){
	int val = 0;
	int num;
	while(true){
		cin >> num;
		val = val ^ num;
		cout << val  << "\n";
	}
}
