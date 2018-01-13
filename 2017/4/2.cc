#include <iostream>
#include <unordered_set>
#include <string>
#include <sstream>
#include <algorithm>

bool isPassphrase(std::string& s) {
  std::stringstream ss(s);
  std::string word;
  std::unordered_set<std::string> words;
  for (int i=0; ss >> word; i++) {
    std::sort(word.begin(), word.end());
    words.insert(word);
    if (i == words.size()) return false;
  }
  return true;
}

int main() {
  std::string line;
  unsigned int total = 0;
  while (getline(std::cin, line)) {
    if (isPassphrase(line)) total++;
  }

  std::cout << total << std::endl;
}
