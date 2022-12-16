#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

#define slice_item(s, i, t) (t*)_slice_item(s, i)

// use slice instead of struct slice*
typedef struct slice* slice;

// slice implementation with an array of void* items.
// it stores the current size of its array into cap
// and then increase it when array items' length (len) increased.
//
// please note that it only increases it size and it never
// shrinks.
struct slice {
  void **items;

  int cap;
  int len;
};

slice slice_new(void) {
  slice s = malloc(sizeof(struct slice));

  assert(s != NULL);

  s->items = malloc(10 * sizeof(void *));
  assert(s->items != NULL);

  s->len = 0;
  s->cap = 10;

  return s;
}

void slice_push(slice slice, void *item) {
  // it checks if the len index is less than the
  // maximum items the array can store.
  if (slice->len < slice->cap) {
    // if it's less, then it pushes the
    // item to the end of the array.
    slice->items[slice->len] = item;
    slice->len++;
  } else {
    // if the len is greater than or equal
    // to the maximum size (cap) then
    // it reallocs a new array which is twice
    // the size of the initial array.
    //
    // this will case a copy from old to newly allocated array.
    void **items = realloc(slice->items, 2 * (slice->cap) * sizeof(void *));
    assert(items != NULL);
    slice->items = items;
    slice->cap = 2 * slice->cap;
  }
}

void *_slice_item(slice s, int index) {
  if (index < s->len) {
    return s->items[index];
  }
  return NULL;
}

int main(int argc, char *argv[]) {
  int i;
  slice s;

  s = slice_new();

  printf("capacity: %d\n", s->cap);
  printf("length: %d\n", s->len);

  // here `i` variable has only one address
  // so storing it address is a bad idea.
  // your result array is 20 20 ... 20.
  for (i = 0; i < 20; i++)
    slice_push(s, &i);

  printf("capacity: %d\n", s->cap);
  printf("length: %d\n", s->len);

  printf("[10]: %d\n", *slice_item(s, 10, int));
}
