#include <iostream>
#include <string>

char ZERO_CHAR = '0';

std::string getStrStdin() {
  std::string s;
  std::cin >> s;
  return s;
}

unsigned int char2int(char c) {
  return (unsigned int)(c - ZERO_CHAR); 
}

int calculate(const std::string& s, int i) {
  if (i == s.length()) {
    return 0;
  }

  return ((s[i] == s[(i+1)%s.length()]) ? char2int(s[i]) : 0) + calculate(s, i+1);
}

int main() {
  std::string s = getStrStdin();
  std::cout << calculate(s, 0) << std::endl;
  
}
