#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

#define stack_item(s, i, t) (t*)_stack_item(s, i)

// use stack instead of struct stack*
typedef struct stack* stack;

// stack implementation with an array of void* items.
// it stores the current size of its array into cap
// and then increase it when array items' length (len) increased.
//
// please note that it only increases it size and it never
// shrinks.
struct stack {
  void **items;

  int cap;
  int len;
};

stack stack_new(void) {
  stack s = malloc(sizeof(struct stack));

  assert(s != NULL);

  s->items = malloc(10 * sizeof(void *));
  assert(s->items != NULL);

  s->len = 0;
  s->cap = 10;

  return s;
}

void stack_push(stack stack, void *item) {
  // it checks if the len index is less than the
  // maximum items the array can store.
  if (stack->len < stack->cap) {
    // if it's less, then it pushes the
    // item to the end of the array.
    stack->items[stack->len] = item;
    stack->len++;
  } else {
    // if the len is greater than or equal
    // to the maximum size (cap) then
    // it reallocs a new array which is twice
    // the size of the initial array.
    //
    // this will case a copy from old to newly allocated array.
    void **items = realloc(stack->items, 2 * (stack->cap) * sizeof(void *));
    assert(items != NULL);
    stack->items = items;
    stack->cap = 2 * stack->cap;
  }
}

void *_stack_item(stack s, int index) {
  if (index < s->len) {
    return s->items[index];
  }
  return NULL;
}

int main(int argc, char *argv[]) {
  int i;
  stack s;

  s = stack_new();

  printf("capacity: %d\n", s->cap);
  printf("length: %d\n", s->len);

  // here `i` variable has only one address
  // so storing it address is a bad idea.
  // your result array is 20 20 ... 20.
  for (i = 0; i < 20; i++)
    stack_push(s, &i);

  printf("capacity: %d\n", s->cap);
  printf("length: %d\n", s->len);

  printf("[10]: %d\n", *stack_item(s, 10, int));
}
