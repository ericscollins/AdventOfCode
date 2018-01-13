#include <iostream>
#include <unordered_map>
#include <utility>
#include <string>
#include <cmath>
#include <stdexcept>

typedef std::pair<int,int> Coord;
typedef std::pair<short,short> Direction;

struct CoordHash {
  // http://en.cppreference.com/w/cpp/utility/hash
  unsigned int operator()(const Coord& c) const {
    return std::hash<int>{}(c.first) ^ (std::hash<int>{}(c.second) << 1);
  }
};

void moveCoord(Coord& c, const Direction& d) {
  c.first += d.first;
  c.second += d.second;
}

void turn(Direction& d) {
  std::swap(d.first, d.second);
  if (!d.first)
    d.second = -d.second;
}

void moveCurrent(Coord& c, Direction& d) {
  if (c.first == c.second && c.first >=0) {
    moveCoord(c,d);
    turn(d);
  }
  else if (abs(c.first) == abs(c.second)) {
    turn(d);
    moveCoord(c,d);
  }
  else {
    moveCoord(c,d);
  }
}

unsigned int sumNeighbors(const std::unordered_map<Coord, unsigned int, CoordHash>& grid,
			  const Coord& current) {
  unsigned int total = 0;
  for(int dx = -1; dx < 2; dx++) {
    for (int dy = -1; dy < 2; dy++) {
      if (dx == dy && dx == 0) continue;
      try {
	total += grid.at(Coord(current.first+dx,current.second+dy));
      }
      catch (const std::out_of_range& e) {}
    }
  }
  return total;
}

unsigned int findFirstGreater(std::unordered_map<Coord, unsigned int, CoordHash>& grid,
			      const unsigned int& n, Coord& current, Direction& dir) {
  moveCurrent(current,dir);
  int m = sumNeighbors(grid, current);
  grid[current] = m;
  if (m > n) return m;
  return findFirstGreater(grid, n, current, dir);
}
			      
int main() {
  unsigned int n;
  std::cin >> n;
  
  std::unordered_map<Coord, unsigned int, CoordHash> grid;
  Coord current(0,0);
  Direction dir(1,0);
  grid[current]=1;
  
  std::cout << findFirstGreater(grid,n,current,dir) << std::endl;
}


  
