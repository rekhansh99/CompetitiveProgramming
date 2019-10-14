#include<bits/stdc++.h>
using namespace std;
void printFib(long int num){
	int a = 0;
	int b = 1;
	long int val;
	cout << a << " " << b << " ";
	while(val <= num){
		val = a+b;
		a = b;
		b = val;
		if(b < num)
			cout << b << " ";
		else
			break;
	}
}
int main(){
	cout << "This program prints fibonnaci number till a final range...\n";
	long int num;
	cin >> num;
	printFib(num);
}
