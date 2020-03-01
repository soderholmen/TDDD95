#include <vector>
#include <iostream>
#include <iterator>
#include <algorithm>
#include <numeric>
#include <math.h>
using namespace std;

typedef unsigned long long ull;

ull bise( ull left, ull right, ull max, vector<ull> &kids, int num_kids){
  if (left >= right){
    return left;
  }
  ull mid{(left + right)/2};
  ull c{0};
  
  for (int i = 0; i < num_kids; i++){
    if (kids[i] > mid)
      c += kids[i] - mid;
    if(c > max)
      break;
      }
  if(c > max){
    return bise( mid + 1, right, max, kids, num_kids);
      }
  else{
    return bise(left, mid, max, kids, num_kids);
    }
  return 0;
}

int main(){
  ull max;
  int num_kids;
  cin >> max;
  cin >> num_kids;
  vector<ull> kids(num_kids);
  copy(istream_iterator<ull>(cin), istream_iterator<ull>(), begin(kids));
  sort(kids.begin(), kids.end());
  ull left{bise(0, 2e9, max, kids, num_kids)};
  for (int i = 0; i < num_kids; ++i) {
    if (kids[i] > left) {
      max -= (kids[i] - left);
      kids[i] = left;
    }
  }

  ull res = 0;
  for (int i = num_kids - 1; i >= 0; --i) {
    if (max > 0) {
      max = max - 1;
      kids[i] = kids[i] - 1;
    }
    res += kids[i] * kids[i];
  }
  
  cout << res << endl;
  
  return 0;
}

