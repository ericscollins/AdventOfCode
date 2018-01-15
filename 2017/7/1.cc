#include <iostream>
#include <string>
#include <unordered_map>
#include <regex>
#include <stdexcept>

// const std::string REGEX = "([a-z]*) \\(([0-9]*)\\)(?: -> ((?:[a-z]*(?:, )?)*))?";
const std::string REGEX = "[a-z]";


std::string findRoot(const std::unordered_map<std::string,std::string>& parents, std::string name) {
  try {
    return (findRoot(parents, parents.at(name)));
  }
  catch (const std::out_of_range& e) {
    return name;
  }
}

void parseInput(std::unordered_map<std::string,unsigned int>& weights,
		std::unordered_map<std::string,std::string>& parents) {
  std::string line;
  std::regex fullLineRE(REGEX);

  while(getline(std::cin, line)) {
    //std::smatch sm;
    
    //std::regex_match(line, sm, std::regex(REGEX));

    //std::string name = sm[0].str();
    //weights[name] = std::stoi(sm[1].str());
    
    //for (int i = 2; i < sm.size(); i++) {
    //  parents[sm[i].str()] = name;
    //}
  }
}


int main() {
  std::unordered_map<std::string,unsigned int> weights;
  std::unordered_map<std::string,std::string> parents;
  
  parseInput(weights,parents);
  //std::cout << findRoot(parents, parents.begin()->first) << std::endl;
}
