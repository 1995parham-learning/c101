#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

// pipe and fork example shows how to use pipe and fork
// together so you can run a program and pipe its result
// (status code) into the parent process.

int main(int argc, char const *argv[]) {
  int c2p[2];
  int i;
  int stat;

  if (argc == 1) {
    fprintf(stderr, "please enter the command (with its arguments), that you want to run");
  }

  for (i = 1; i < argc; i++) {
    // create pipe to communicate with the executed command.
    pipe(c2p);

    if (fork() == 0) {
      // child code which is going to run the given command
      // and then wait for its response.
      if (fork() == 0) {
        if (execlp(argv[i], argv[i], NULL) == -1)
          exit(errno);
      }
      wait(&stat);
      write(c2p[1], &stat, sizeof(stat));
      exit(0);
    }

    read(c2p[0], &stat, sizeof(int));
    if (stat != 0) {
      printf("Not succsesful: %s %d\n", argv[i], stat);
    } else {
      printf("Succes! %s\n", argv[i]);
    }
  }
}
