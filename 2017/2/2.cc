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

  for (int i=0; i < v -> size(); i++) {
    for (int j=i+1; j < v -> size(); j++) {
      int smaller;
      int larger;
      if (v -> at(i) > v -> at(j)) {
	larger = v -> at(i);
	smaller = v -> at(j);
      }
      else {
	larger = v -> at(j);
	smaller = v -> at(i);
      }

      if (larger / smaller * smaller == larger)
	return larger / smaller;
    } 
  }
}

int main() {
  int total = 0;
  std::string line;
  while (getline(std::cin, line)) {
    total += processLine(line);
  }
  std::cout << total << std::endl;
}
