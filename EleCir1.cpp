#include <iostream>
using namespace std;

int main(){
  int n = 0;

  cout << "How many times do you want to see?" << endl;
  cout << ">> " << flush;
  cin >> n;

  //cout << n << endl;
  int a[n][2] = {0};

  for(int i = 0; i < n; i++){
    cout << "( " << a[i][0] << ", " << a[i][1] << " )" << endl;
  } 

  return 0;
}  
