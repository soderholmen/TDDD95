
#include <bits/stdc++.h>

using namespace std;
typedef double ull;


struct Intervall{
public:
  
  Intervall(ull left, ull right, int index) :
    left{left}, right{right}, index{index} {}

  Intervall& operator=(Intervall other)
    {
      left = other.left;
      right = other.right;
      index = other.index;
      return *this;
    }
  
  
  const ull get_left() const {return left;}
  const ull get_right() const {return right;}
  const int get_index() const {return index;}
private:
  ull left;
  ull right;
  int index;
  
  
};

struct intervall_comparator
{
    bool operator() (const Intervall& lhs,
                     const Intervall& rhs) const
    {
      if (lhs.get_left() == rhs.get_left())
        return lhs.get_right() < rhs.get_right();
      else
        return lhs.get_left() < rhs.get_left();
    }
};


int main(){
  pair<ull, ull> inter;
  cout.precision(12);

  while(cin >> inter.first){
    cin >> inter.second;
    int num_intr{0};
    cin >> num_intr;
    set<Intervall, intervall_comparator > covers;
    for( int i = 0; i < num_intr; i++){
      
      ull left;
      ull right;
      cin >> left >> right;
      covers.insert(Intervall(left, right, i));
    }
    Intervall temp(*covers.begin());

    vector<int> index{temp.get_index()};
    bool error{false};
    
    if ((*covers.begin()).get_left() > inter.first ){
      error = true;
    }
    else{
     
      covers.erase(covers.begin());
      for (int i = 1; i < num_intr; i++){
	if ((*covers.begin()).get_left() <= inter.first){
	  if ((*covers.begin()).get_right() > temp.get_right()){
	    temp = (*covers.begin());
	    index.pop_back();
	    index.push_back(temp.get_index());
	  }
	  if (!covers.empty())
	    covers.erase(covers.begin());
	}
	else if ((*covers.begin()).get_left() <= temp.get_right()){
	  if(temp.get_right() >= inter.second)
	    break;
	  inter.first = temp.get_right();
	  temp = (*covers.begin());
	  covers.erase(covers.begin());
	  index.push_back(temp.get_index());
	  
	}
	else if(temp.get_right() >= inter.second){
	  break;
	}
	else{
	  error = true;
	  break;
	}
      }
      if (temp.get_right() < inter.second){
      	error = true;
      }
     
    }
     if (error){	  
	cout << "impossible" << endl;
      }else{
	cout << index.size() << endl;
	cout << index[0];
	for (int i = 1; i < index.size(); i++)
	  cout << " " << index[i];
	cout << endl;
       
      }
  }
}


