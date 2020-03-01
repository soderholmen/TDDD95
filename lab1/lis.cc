/* 
@Program name      : lis.cc

@Author            : Gustaf Söderholm (gusso811)

@Date created      : 20190214
*/


#include <bits/stdc++.h>

using namespace std;


int re(vector<int> values, int num_val, int *curr_max, vector<int> &index){

  if (num_val == 1)
    return 1;

  int res{1};
  int max{1};
  
   for (int i = 1; i < num_val; i++) 
    { 
      res = re(values, i, curr_max, index); 
      if (values[i-1] < values[num_val-1] && res + 1 > max){
	max = res + 1;
      }
    } 

    if (*curr_max < max) 
       *curr_max = max; 
   
    return max; 
}


int main(){
  int num_val;
  while(cin >> num_val){
 
  vector<int> values(0); 
    for( int i = 0; i < num_val; i++){
      int in; 
      cin >> in;
      values.push_back(in);
    }
 
  
  
    //int max{1};
  vector<vector<int>> index(0, vector<int>(0));




  for (int i = 0 ; i < num_val; i++){
    for (int j = 0; j < i ; j++){
      

    }


  }
  







  //re(values, num_val, &max, index);
  cout << max << endl;
  for (int i: index)
    cout << i << endl;
  }
  
  return 0;

}
