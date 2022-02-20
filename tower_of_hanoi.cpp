#include <iostream>
#include <cmath>
#include <vector>
#include <tuple>

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
   return std::pow(2, n_discs) - 1;
  }
}

//test function
std::vector<std::tuple<long int, long int, long int>> test_function(int disc_limit) {  
  std::vector<std::tuple<long int, long int, long int>> returnVector;
  try {	 
   for(int i = 0; i <= disc_limit; i++) {
    std::tuple<long int, long int, long int> disc_run = std::make_tuple(i, RecursiveSolution(i), ClosedFormSolution(i));
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

for(auto& tuple: test_function(input)) {cout << "(" << std::get<0>(tuple) << ", " << std::get<1>(tuple) << ", " << std::get<2>(tuple) << ")\n";}	
}
