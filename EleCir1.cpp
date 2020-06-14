#include <iostream>
using namespace std;

void f1(float data[], int n, int t, float size);
void f2(float data[], int n, int t, float size);
void f3(float data[], int n, int t, float size);

//Coefficients  |a->      <-b|c-> 
const float a1 = -0.3, b1 = -0.3, c1 = 0.6;
const float a2 = -0.3, b2 = -0.3, c2 = 0.6;
const float a3 =    1, b3 = -0.3, c3 = 0.6;

int main(){
  int n = 0;
  float V = 0;

    //cout << a1 << b1 << c1 << endl;

  cout << "How many times do you want to see?" << endl;
  cout << ">> " << flush;
  cin >> n;

  cout << "How much V do you first applicate?" << endl;
  cout << ">> " << flush;
  cin >> V; 

    //cout << n << endl;
  // initialize data (t, V(t))
  float data[2 * n] = {0};

  // initialize t  <- 1, 3, 5, 7, 9, ...
  for(int i = 0; i < n; i++){
    data[2 * i] += 2 * i + 1;
  }

  f1(data, n, 0, V);

  for(int i = 0; i < n; i++){
    cout << "( " << data[2 * i] << ", " << data[2 * i + 1] << " )" << endl;
  } 

  return 0;
}  

void f1(float data[], int n, int t, float size){
  //data[2 * t + 1] += c1 * size;
  for(int i = t; i < n; i++){
    data[2 * i + 1] += c1 * size;
  } 
  t++;
  if(t >= n){
    return;
  }
  f1(data, n, t, a1 * b1 * size);
  f2(data, n, t, a2 * c1 * size);
  f2(data, n, t, a3 * c1 * size);
}

void f2(float data[], int n, int t, float size){
  //data[2 * t + 1] += c2 * size;
  for(int i = t; i < n; i++){
    data[2 * i + 1] += c2 * size;
  }
  t++;
  if(t >= n){
    return;
  }
  f1(data, n, t, a1 * c2 * size);
  f2(data, n, t, a2 * b2 * size);
  f2(data, n, t, a3 * c2 * size);
}

void f3(float data[], int n, int t, float size){
  //data[2 * t + 1] += c3 * size;
  for(int i = t; i < n; i++){
    data[2 * i + 1] += c3 * size;
  }
  t++;
  if(t >= n){
    return;
  }
  f1(data, n, t, a1 * c3 * size);
  f2(data, n, t, a2 * c3 * size);
  f2(data, n, t, a3 * b3 * size);
}


