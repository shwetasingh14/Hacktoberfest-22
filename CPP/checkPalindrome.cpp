#include<iostream>
using namespace std;
int main(){
	string str;
	cout<<"Enter the string: ";
	cin>>str;
	int n = str.size();
	bool res = true;
	int i=0,j=n-1;
	while(i<j){
		if(str[i]!=str[j]){
			res = false;
			break;
		}
		i++;
		j--;
	}
	if(res){
		cout<<"YES";
	}
	else{
		cout<<"NO";
	}
}
