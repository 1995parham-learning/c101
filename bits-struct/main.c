#include <stdio.h>

// attrs struct has bit-size for each of its fields.
struct attrs {
  unsigned char p1 : 1;
  unsigned char p2 : 1;
  unsigned char p3 : 1;
  unsigned char p4 : 5;
};

int main(int argc, char *argv[]) {
  printf("attrs structu size in bytes: %ld\n", sizeof(struct attrs));

  struct attrs attrs;
  attrs.p1 = 1;
  attrs.p2 = 1;
  attrs.p3 = 1;
  attrs.p4 = 31;
  printf("%X\n", attrs);
}
