#include <vector>
#include <iostream>
#include <iterator>
#include <algorithm>
#include <numeric>
#include <math.h>
using namespace std;


int main(){
  double candy;
  int num_kids;
  cin >> candy;
  cin >> num_kids;
  vector<double> kids(num_kids);
  //copy(istream_iterator<int>(cin), istream_iterator<int>(), begin(kids));
  double d = 0;
  for ( int i = 0; i < num_kids; i++){
    scanf("%lf", &d);
    kids[i] = d;
  }
  sort(kids.rbegin(), kids.rend());

  for ( int j = 0; j < candy; j++){
    kids[0] = kids[0]-1;
    sort(kids.rbegin(), kids.rend());

    if (kids[0] == 0)
      break;
    //auto i = max_element(kids.begin(), kids.end());
    //*i = *i - 1;
    //if (*i == 0)
    //kids.erase(i, i);
  }
  
  transform(kids.begin(), kids.end(),kids.begin(), [](int i){return pow(i, 2);});
  cout << accumulate(kids.begin(), kids.end(), 0) << endl;
   
  return 0;
}
