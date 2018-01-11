#include <iostream>
#include <string>
#include <vector>

const char ZERO_CHAR = '0';
const char NINE_CHAR = '9';

unsigned int char2int(char c) {
  return (unsigned int)(c - ZERO_CHAR);
}

bool isNumeric(char c) {
  return c >= ZERO_CHAR && c <= NINE_CHAR;
}

std::vector<int>* parseLine(const std::string& s) {
  std::vector<int>* result = new std::vector<int>;
  int current = 0;

  for (int i=0; i < s.length(); i++) {
    if (isNumeric(s[i])) {
      current *= 10;
      current += char2int(s[i]);
    }
    else {
      result -> push_back(current);
      current = 0;
    }
  }

  result -> push_back(current);
  return result;
}


int processLine(const std::string& s) {

  std::vector<int>* v = parseLine(s);
  
  int largest = v -> at(0);
  int smallest = largest;

  for (int i = 1; i < v -> size(); i++) {
    int current = v -> at(i);
    if (current > largest) {
      largest = current;
    }
    else if (current < smallest) {
      smallest = current;
    }
  }

  delete v;
  
  return largest - smallest;
}

int main() {
  int total = 0;
  std::string line;
  while (getline(std::cin, line)) {
    total += processLine(line);
  }
  std::cout << total << std::endl;
}
