/* 
@Program name      : pth.cc

@Author            : Gustaf Söderholm (gusso811)

@Date created      : 20190209
*/

#include <bits/stdc++.h>

using namespace std;


int main(){
  double x;
  while (true) {
    cin >> x;
    
    double y{fabs(x)};
    //cout << x << endl;
    if (x==0)
      break;
    
    for (double i = 32; i > 0; i--) {
      double b{pow(y, (1/i))};
      double diff{abs(round(b)-b)}; 
      if (diff < 1e-11){
	if( x < 0){
	  if ( ((int)i)%2 != 0){
	    cout << i << endl;
	    break;
	  }
	  
	}
	else{
	  cout << i << endl;
	  break;
	}
	
	
      }
    }
  }
}
