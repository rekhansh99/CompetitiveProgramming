#include<bits/stdc++.h>
using namespace std;
int gcd(int a, int b){
	if(b == 0)
		return a;
	return gcd(b, a%b);
}
int main(){
	int a, b;
	cout << "Finding GCD of two number\n" << "Enter two number  : \n";
	cin >> a >> b;
	cout << "Number : " << a << " & " << b;
	cout << "\nGCD : "<< gcd(a, b);
}
