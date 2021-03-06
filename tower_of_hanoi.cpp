#include <iostream>
#include <cmath>
#include <vector>
#include <tuple>

//contains two solutions and a test function for Knuth's Tower of Hanoi Problem
unsigned long long int RecursiveSolution(unsigned int n_discs) {
  if (n_discs == 0) {
   return 0;
  }
  //added to cap the recursion at a safe number of layers
  else if (n_discs > 64) {
   throw "Number of Discs Exceeds Cap of 64: ";
  }
  else {
   return 2 * RecursiveSolution(n_discs - 1) + 1;
  }
}

//uses std::pow()
unsigned long long int ClosedFormSolution(unsigned int n_discs) {
  //added to cap the recursion at a safe numver of layers	
  if (n_discs > 64) {  
   throw "Number of Discs Exceeds Cap of 64: ";
  }
  else {
   return std::pow(2, n_discs) - 1;
  }
}

//test function
std::vector<std::tuple<int, unsigned long long int, unsigned long long int>> test_function(int disc_limit) {  
 std::vector<std::tuple<int, unsigned long long int, unsigned long long int>> returnVector;	 
 for(int i = 0; i <= disc_limit; i++) {
  try {
    std::tuple<int, unsigned long long int, unsigned long long int> disc_run = std::make_tuple(i, RecursiveSolution(i), ClosedFormSolution(i));
    returnVector.push_back(disc_run);
    }    
  catch (const char* msg) { 
    std::cerr << msg << i << " Discs Provided" << std::endl;
  }
 }
 return returnVector;
}

int main() {

 unsigned int input;	
 std::cout  << "Enter your maximum disc amount between 0 and 64: \n";
 std::cin >> input;

 for(auto& tuple: test_function(input)) {
  std::cout << "(" << std::get<0>(tuple) << ", " << std::get<1>(tuple) << ", " << std::get<2>(tuple) << ")\n";
 }	
}
