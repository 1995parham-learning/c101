/*
 * In The Name Of God
 * ========================================
 * [] File Name : mfh.c
 *
 * [] Creation Date : 31-12-2015
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
 */
/*
 * Copyright (c) 2015 Parham Alvani.
 */
#include <stdio.h>
#include <stdlib.h>

struct date {
  int year;
  int month;
  int day;
};

int int_cmp_asc(const void *i1, const void *i2) {
  struct date a = *(struct date *)i1;
  struct date b = *(struct date *)i2;

  if (a.year != b.year)
    return a.year - b.year;
  else {
    if (a.month != b.month)
      return a.month - b.month;
    else
      return a.day - b.day;
  }
}

int int_cmp_dsc(const void *i1, const void *i2) {
  struct date a = *(struct date *)i1;
  struct date b = *(struct date *)i2;

  if (a.year != b.year)
    return b.year - a.year;
  else {
    if (a.month != b.month)
      return b.month - a.month;
    else
      return b.day - a.day;
  }
}

int main(int argc, char *argv[]) {
  int n, m;
  int i;
  struct date *dates;

  if (scanf("%d", &n) != 1 || n < 0) {
    fprintf(stderr, "invalid count\n");
    return 1;
  }
  dates = malloc(n * sizeof(struct date));

  for (i = 0; i < n; i++) {
    if (scanf("%d %d %d", &dates[i].year, &dates[i].month, &dates[i].day) !=
        3) {
      fprintf(stderr, "invalid date\n");
      return 1;
    }
  }

  if (scanf("%d", &m) != 1)
    m = 0;
  if (m == 1)
    qsort(dates, n, sizeof(struct date), int_cmp_asc);
  else if (m == -1)
    qsort(dates, n, sizeof(struct date), int_cmp_dsc);

  for (i = 0; i < n; i++) {
    printf("%d/", dates[i].year);
    printf("%d/", dates[i].month);
    printf("%d\n", dates[i].day);
  }
  return 0;
}
