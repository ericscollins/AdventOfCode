#include<iostream>
#include<cmath>

const double ERROR_MARGIN = 0.00000000001;

int determineLayer(int n) {
  double root = sqrt((double) n);
  double wholeD;
  double fraction = modf(root, &wholeD);      
  int wholeI = (int) wholeD;

  if (fraction < ERROR_MARGIN) {
    return wholeI / 2;
  }
  
  return ((wholeI % 2 == 0) ? wholeI : (wholeI + 1)) / 2;
}


int main() {
  int n;
  std::cin >> n;

  int layer = determineLayer(n);
  int sideLength = layer * 2 + 1;
  int maxDist = sideLength / 2;
  int distBetweenCorners = sideLength - 1;

  int corner = pow(sideLength, 2); 

  while (abs(corner - n) > maxDist) 
    corner -= distBetweenCorners;

  int dist2Corner = abs(corner - n);

  std::cout << (layer * 2 - dist2Corner) << std::endl;
}
