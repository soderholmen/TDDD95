//Gustaf Söderholm gusso811

#include <bits/stdc++.h>

using namespace std;



int main(){

  double amount;
  cin >> amount;

  vector<int> tree(amount); 
  map<int, int> count;

  
  for (int i = 0; i < amount; i++){
    int temp{0};
    scanf("%d", &temp);
    tree[i] = temp;
    count[temp]++; // Count how many times a node apperas in vector tree
  }

  // Get all leafs 
  set<int> leafs;
  for (int i = 1; i <= amount + 1; i++){
    if (count.find(i) == count.end()){
      leafs.insert(i);
    }
  }

  
  vector<int> out(amount);
  bool error{false};

  //If no leafs exist, error
  if (leafs.empty()){
    error = true;  
  }
  else{
    for (int i = 0; i < amount; i++){
      // If we try to cut of the biggest leaf, not allowed
      if (*leafs.begin() == amount + 1){
	error = true;
	break;
      }
      out[i] = *leafs.begin(); // Lowest leaf to be cut off
      leafs.erase(leafs.begin());

      // If node i in tree do not exist in vector i, node is now a leaf
      if (--count[tree[i]] == 0){
        leafs.insert(tree[i]);
      }
    }
  }
  if (!error){
    copy(out.begin(), out.end(),  ostream_iterator<size_t>(cout, "\n"));
  }
  else{
    cout << "Error" << endl;
  }
  return 0;
}
