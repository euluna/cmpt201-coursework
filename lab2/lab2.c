#include <stdio.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
  char input[1024];

  while (1) {
    printf("Enter programs to run.\n> ");
    fflush(stdout);

    if (fgets(input, sizeof(input), stdin) == NULL) {
      break; // EOF (Ctrl+D)
    }

    // Remove newline
    input[strcspn(input, "\n")] = 0;

    pid_t pid = fork();

    if (pid == 0) {
      // Child
      execl(input, input, NULL);
      perror("Exec failure");
      return 1;
    } else if (pid > 0) {
      // Parent
      waitpid(pid, NULL, 0);
    }
  }

  return 0;
}
