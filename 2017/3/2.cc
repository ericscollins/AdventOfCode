#include <iostream>

int calculate(int n) {
  if (n == 1) {
    return 1;
  }
}

int main() {
  int n;
  std::cin >> n;

  std::cout << calculate(n) << std::endl;
}
