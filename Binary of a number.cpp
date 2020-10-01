#include<bits/stdc++.h>
using namespace std;
int main(){
	int num;
	cout << "Enter number for getting binary format of number : ";
	cin >> num;
	int arr[100];
	int i =0;
	int temp = num;
	while(num != 0){
		if(num%2 == 0)
			arr[i++] = 0;
		else
			arr[i++] = 1;
		num = num/2;
	}
	i = i-1;
	for(; i>=0; i--)
		cout << arr[i];
	
}
