#include <math.h>
#include <stdio.h>

// max find the maximum between a and b, because:
// a + b + | a - b |
// if a > b then
// a + b + a - b = 2a
// else
// a + b + b - a = 2b
double max(double a, double b) { return 1 / 2. * (a + b + fabs(a - b)); }

int main(int argc, char *argv[]) {
  double b = 0.01242;
  double a = 0.04231;

  printf("%g\n", max(a, b));

  // check whether b is the maximum or not
  int c = ceil(max(a, b) / b);
  c = (c + 1) % c;
  // c should be 1 if a > b or else it should be 0
  printf("%d\n", c);
}
