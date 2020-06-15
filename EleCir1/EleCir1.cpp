#include <iostream>
#include <fstream>
using namespace std;

void f1(float data[], int n, int t, float size);
void f2(float data[], int n, int t, float size);
void f3(float data[], int n, int t, float size);

//Coefficients  |a->      <-b|c-> 
//const float a1 = -(1.0/3.0), b1 = -(1.0/3.0), c1 = (2.0/3.0);
//const float a2 = -(1.0/3.0), b2 = -(1.0/3.0), c2 = (2.0/3.0);
//const float a3 =        1.0, b3 = -(1.0/3.0), c3 = (2.0/3.0);

const float a1 = -0.333, b1 = -0.333, c1 = 0.666;
const float a2 = -0.333, b2 = -0.333, c2 = 0.666;
const float a3 =    1.0, b3 = -0.333, c3 = 0.666;

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

  ofstream values;
  values.open("values.csv", ios::out | ios::binary | ios::trunc);
  if(! values.is_open()){
    return EXIT_FAILURE;
  }
  for(int i = 0; i < n; i++){
    values << data[2 * i] << "," << data[2 * i + 1] << endl;
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


