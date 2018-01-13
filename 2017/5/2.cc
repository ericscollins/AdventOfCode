#include <iostream>
#include <vector>

int main() {
  int n;
  int steps;
  int oldN;
  std::vector<int> jumps;
  
  while(std::cin >> n)
    jumps.push_back(n);

  for (steps=0, n=0; n >= 0 && n < jumps.size(); steps++) {
    oldN=n; 
    n += jumps[n];
    jumps[oldN] += (jumps[oldN] < 3) ? 1 : -1;
  }

  std::cout << steps << std::endl;
}
