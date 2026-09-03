/*
 * In The Name Of God
 * ========================================
 * [] File Name : filep.c
 *
 * [] Creation Date : 07-01-2016
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
 */
/*
 * Copyright (c) 2016 Parham Alvani.
 */
#include <stdio.h>

FILE *my_open(const char *name) { return fopen(name, "r+"); }

int main(int argc, char *argv[]) {
  FILE *fp = my_open("filep.c");
  if (fp == NULL) {
    perror("fopen");
    return 1;
  }
  fgetc(fp);
  /*
   * Peek at the stdio buffer state. The FILE layout is libc-private, so the
   * field names differ: BSD libc (macOS) keeps byte counts in _r/_w, while
   * glibc keeps begin/end pointers into the buffer.
   */
#if defined(__GLIBC__)
  printf("fgetc(): %ld\n", (long)(fp->_IO_read_end - fp->_IO_read_ptr));
  printf("fputc(): %ld\n", (long)(fp->_IO_write_end - fp->_IO_write_ptr));
#else
  printf("fgetc(): %d\n", fp->_r);
  printf("fputc(): %d\n", fp->_w);
#endif
}
