//Gustaf Söderholm gusso811

#include <bits/stdc++.h>

using namespace std;



template<typename T1, typename T2>
struct set_with_pair_comparator
{
    bool operator() (const pair<T1, T2>& lhs,
                     const pair<T1, T2>& rhs) const
    {
      if (lhs.first == rhs.first)
        return lhs.second < rhs.second;
      else
        return lhs.first < rhs.first;
    }
};




struct Intervall{
public:
  
  Intervall(double left, double right, int index) :
    left{left}, right{right}, index{index} {}

  Intervall& operator=(Intervall other)
    {
      left = other.left;
      right = other.right;
      index = other.index;
      return *this;
    }
  
  
  const double get_left() const {return left;}
  const double get_right() const {return right;}
  const int get_index() const {return index;}
private:
  double left;
  double right;
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



