#include <iostream>
#include <vector>

int main() {
  int n;
  int steps;
  std::vector<int> jumps;
  while(std::cin >> n)
    jumps.push_back(n);
  for (steps=0, n=0; n >= 0 && n < jumps.size(); steps++)
    n += jumps[n]++;
  std::cout << steps << std::endl;
}
