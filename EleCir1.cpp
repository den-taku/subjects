#include <iostream>
using namespace std;

int main(){

  const float a1 = -0.3, b1 = -0.3, c1 = 0.6;
  const float a2 = -0.3, b2 = -0.3, c2 = 0.6;
  const float a3 =    1, b3 = -0.3, c3 = 0.6;

  int n = 0;

  //cout << a1 << b1 << c1 << endl;

  cout << "How many times do you want to see?" << endl;
  cout << ">> " << flush;
  cin >> n;

  //cout << n << endl;
  int data[n][2] = {0};

  for(int i = 0; i < n; i++){
    cout << "( " << data[i][0] << ", " << data[i][1] << " )" << endl;
  } 

  return 0;
}  
