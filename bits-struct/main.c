#include <stdio.h>
#include <string.h>

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

  // attrs can't be passed to a variadic printf directly (it isn't an
  // integer type), so copy its packed bits into one instead.
  unsigned int raw = 0;
  memcpy(&raw, &attrs, sizeof(attrs));
  printf("%X\n", raw);
}
