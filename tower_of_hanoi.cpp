#include <iostream>
#include <cmath>
#include <vector>
#include <tuple>

using namespace std;

//contains two solutions and a test function for Knuth's Tower of Hanoi Problem
long int RecursiveSolution(int n_discs) {
  if (n_discs < 0) { 
   throw "Number of Discs must be greater than or equal to zero"; 
  }
  else if (n_discs == 0) {
   return 0;
  }
  else {
   return 2 * RecursiveSolution(n_discs - 1) + 1;
  }
}

//uses std::pow()
long int ClosedFormSolution(int n_discs) {
  if (n_discs < 0) {
   throw "Number of Discs must be greather than or equal to zero";
  }
  else {
   return pow(2, n_discs) - 1;
  }
}

//test function
vector<tuple<long int, long int, long int>> test_function(int disc_limit) {  
  vector<tuple<long int, long int, long int>> returnVector;
  try {	 
   for(int i = 0; i <= disc_limit; i++) {
    tuple<long int, long int, long int> disc_run = make_tuple(i, RecursiveSolution(i), ClosedFormSolution(i));
    returnVector.push_back(disc_run);
    }   
  } 
 catch (const char* msg) { cerr << msg << endl; }
 return returnVector;
}

int main() {

unsigned int input;	
cout  << "Enter your maximum disc size: \n";
cin >> input;

for(auto& tuple: test_function(input)) {cout << "(" << get<0>(tuple) << ", " << get<1>(tuple) << ", " << get<2>(tuple) << ")\n";}	
}
