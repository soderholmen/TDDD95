//Gustaf Söderholm gusso811

#include <bits/stdc++.h>

using namespace std;

struct Compare {
    constexpr bool operator()(pair<int, int> const & a,
                              pair<int, int> const & b) const noexcept
    { return  a.second < b.second; }
};

  

int main(){

  int size;
  int amount;
  int access;


  cin >> size;
  cin >> amount;
  cin >> access;
  vector<int> accesses(0);
  vector<int> cache(0);
  int swaps{0};
  //vector<set<int>> q;
  bool cachefull{false};
  for (int i = 0; i < access; i++){
    int input;
    scanf("%d", &input);
    
    //if (find(cache.begin(), cache.end(), input) == cache.end()){
    if (cache.size() < size){
      swaps++;
      cache.push_back(input);	
    }else{
      if (cachefull || find(cache.begin(), cache.end(), input) == cache.end()){
	cachefull = true;
	accesses.push_back(input);
      }
      
    }
    
  }
  for (int i = 0; i < accesses.size(); i++){
    if ( find(cache.begin(), cache.end(), accesses[i]) == cache.end()){
      swaps++;
      int temp{0};
      int remove{0};
      if ( find(accesses.begin(), accesses.end(), cache[0]) == accesses.end()){
	remove = 0;
      }else{
	int dist{distance( accesses.begin(), find( accesses.begin(), accesses.end(), cache[0] ))};
	for ( int j = 1; j < size; j++){
	  if ( find(accesses.begin(), accesses.end(), cache[j]) == accesses.end()){
	    remove = j;
	    break;
	  }else{
	    temp = distance( accesses.begin(), find( accesses.begin(), accesses.end(), cache[j] ) );
	    if ( temp < dist){
	      dist = temp;
	      remove = j;
	    }
	  }
	}
      }
      cache[remove] = accesses[i];
      accesses.erase(accesses.begin(), accesses.begin()+1);
    }
  }
  cout << swaps << endl;
  return 0;
}
