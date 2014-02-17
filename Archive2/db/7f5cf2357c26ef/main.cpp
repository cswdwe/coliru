// inner block scopes
#include <iostream>
using namespace std;

int main () 
{
  int x = 10;
  int y = 20;
  
  { // Inner block's scope begins here
      
    int x;   // ok, inner scope.
    x = 50;  // sets value to inner x
    y = 50;  // sets value to (outer) y
    
    cout << "\n inner block:\n";
    cout << "x: " << x << endl;
    cout << "y: " << y << endl;
    
  } // Inner block's scope ends here
  
  cout << "\n outer block:\n";
  cout << "x: " << x << endl;
  cout << "y: " << y << endl;
  
}