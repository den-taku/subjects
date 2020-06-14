#include <iostream>
using namespace std;

void f1(int** data, int n, int t, float size);
void f2(int** data, int n, int t, float size);
void f3(int** data, int n, int t, float size);

//Coefficients  |a->      <-b|c-> 
const float a1 = -0.3, b1 = -0.3, c1 = 0.6;
const float a2 = -0.3, b2 = -0.3, c2 = 0.6;
const float a3 =    1, b3 = -0.3, c3 = 0.6;

int main(){
  int n = 0;

    //cout << a1 << b1 << c1 << endl;

  cout << "How many times do you want to see?" << endl;
  cout << ">> " << flush;
  cin >> n;

    //cout << n << endl;
  // initialize data (t, V(t))
  int data[n][2] = {0};

  // initialize t  <- 1, 3, 5, 7, 9, ...
  for(int i = 0; i < n; i++){
    data[i][0] += 2 * i + 1;
  }

  for(int i = 0; i < n; i++){
    cout << "( " << data[i][0] << ", " << data[i][1] << " )" << endl;
  } 

  return 0;
}  

void f1(int** data, int n, int t, float size){
  data[t][1] += c1 * size;
  t++;
  if(t >= n){
    return;
  }
  f1(data, n, t, a1 * b1 * size);
  f2(data, n, t, a2 * c1 * size);
  f2(data, n, t, a3 * c1 * size);
}

void f2(int** data, int n, int t, float size){
  data[t][1] += c2 * size;
  t++;
  if(t >= n){
    return;
  }
  f1(data, n, t, a1 * c2 * size);
  f2(data, n, t, a2 * b2 * size);
  f2(data, n, t, a3 * c2 * size);
}

void f3(int** data, int n, int t, float size){
  data[t][1] += c3 * size;
  t++;
  if(t >= n){
    return;
  }
  f1(data, n, t, a1 * c3 * size);
  f2(data, n, t, a2 * c3 * size);
  f2(data, n, t, a3 * b3 * size);
}


