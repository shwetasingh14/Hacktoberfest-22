#include<bits/stdc++.h>
using namespace std;

void file_i_o() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  #ifndef ONLINE_JUDGE
    freopen("Input.txt","r",stdin);
    freopen("Output.txt","w",stdout);
  #endif
}

int main(int argc, char** argv) {   
  file_i_o();
  //write your code here Als
  long long n;
  cin>>n;
  long long sum = n*(n+1)/2;
  long long input;
  while(cin>>input){
    sum-=input;
  }
  cout<<sum;
  return 0;
}