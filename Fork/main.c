#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  pid_t pid = fork();

  if (pid == 0) {
    printf("I am child process\n");
    return -1;
  } else {
    int return_value;

    if (wait(&return_value) < 0)
      perror("wait() failed\n");

    printf("child proccess id is: %d\n", pid);
    printf("child proccess is die(%d)\n", WIFEXITED(return_value));
    printf("with return value %d\n", (signed char)WEXITSTATUS(return_value));
    printf("we are sorry....\n");
  }
}
