/*
 * In The Name Of God
 * ========================================
 * [] File Name : SharedMemoryProducer.c
 *
 * [] Creation Date : 21-12-2014
 *
 * [] Last Modified : Mon 12 Jan 2015 05:17:43 PM IRST
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
 */
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <unistd.h>

const size_t SIZE = 4096;

int main(int argc, char *argv[]) {
  int fd = shm_open("firstSharedMemory", O_CREAT | O_RDWR, 0644);
  if (fd == -1) {
    perror("shm_open");
    return 1;
  }
  /* a freshly created shm object is 0 bytes until truncated to size */
  if (ftruncate(fd, SIZE) == -1) {
    perror("ftruncate");
    return 1;
  }
  void *ptr = mmap(NULL, SIZE, PROT_WRITE, MAP_SHARED, fd, 0);
  if (ptr == MAP_FAILED) {
    perror("mmap");
    return 1;
  }
  sprintf((char *)ptr, "Hello world of linux IPC\n");
  printf("I write !!!!\n");
}
