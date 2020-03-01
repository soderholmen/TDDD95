#include <vector>
#include <iostream>
#include <iterator>
#include <algorithm>
#include <math.h>
using namespace std;


double tree(int left, int right, double between, double amount, double wet, vector<int> &trees, vector<vector<double> > &memo){

  if (memo[left][right] == -1){
    
    if (left + right == 0)
      return 0;

    else if (right == 0){
      int pos = trees[amount - left];
      //trees.erase(trees.begin(), trees.begin()+1);
      double dis{abs( (((amount/2)-left) * between) - pos)};
      memo[left][right] = tree(left-1, right, between, amount, wet, trees, memo) + dis; 
    }
    else if (left == 0){
      int pos = trees[amount - right];
      //trees.erase(trees.begin(), trees.begin()+1);
      double dis{pow((pow((pos - (((amount/2)-right) * between)),2)+pow(wet,2)),0.5)};
      memo[left][right] = tree(left, right-1, between, amount, wet, trees, memo) + dis; 
    }
    else{
      int pos = trees[amount - (left+right)];
      //trees.erase(trees.begin(), trees.begin()+1);
      double disright{pow((pow((pos - (((amount/2)-right) * between)),2)+pow(wet,2)),0.5)};
      double disleft{abs( (((amount/2)-left) * between) - pos)};
      memo[left][right] = min(tree(left-1, right, between, amount, wet, trees, memo) +disleft,
					tree(left, right-1, between, amount, wet, trees, memo) + disright);  
    }

  }

  return memo[left][right];
}


double calcHyp(double a, double b){


  return pow((pow(a,2)+pow(b,2)),0.5);
  
}


int main(){

  cout.precision(12);
  double amount;
  double len;
  double wet;
  cin >> amount;
  cin >> len;
  cin >> wet;
  vector<int> trees(amount);
  copy(istream_iterator<int>(cin), istream_iterator<int>(), begin(trees));
  sort(begin(trees), end(trees)); //Sorting the drop-off positions

  double between{len/((amount/2)-1)}; //dist between holes 
  
  vector<vector<double> > memo((amount/2)+1, vector<double>((amount/2)+1, -1));
  
  double sum{tree(amount/2, amount/2, between, amount, wet, trees, memo)}; 
  cout << sum << endl;
return 0;
}
