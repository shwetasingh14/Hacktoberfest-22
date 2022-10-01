//Encryption of text using ceasar cipher

#include<iostream>
#include<string.h>

using namespace std;

int main(){
	int key,i,len;
	string text,encrypt;
	
	cout<<"Enter key size\n";
	cin>>key;
	cout<<"Enter text to encrypt\n";
	cin>>text;
	len = text.length();
	cout<<"String length : "<<len<<endl;
	cout<<"Encrypted text is : ";
	
	for(i=0;i<len;i++){
		encrypt[i] = text[i] + key;
		cout<<encrypt[i];
	}
}
