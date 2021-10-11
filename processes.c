#include  <stdio.h>
#include <stdlib.h>
#include  <string.h>
#include <time.h>
#include  <sys/types.h>

#define Buff 100

void ChildProcess(void);
void ParentProcess(void);
void Children(void);

void main(void) {
  time_t t;
  srandom((unsigned) time( & t));
  pid_t pid;
  pid = fork();

  if (pid == 0)
    ChildProcess();
  else
    ParentProcess();
}

void ChildProcess(void) {
  unsigned int rand = (random() % 29) + 1;
  unsigned int i;
  char buf[Buff];

  for (i = 1; i <= rand; i++) {
    sprintf(buf, "Child Pid: %d is going to sleep\n", getpid());
    write(1, buf, strlen(buf));
    sleep((random() % 9) + 1);
    sprintf(buf, "Child Pid: %d is awake\nWhere is my Parent: %d?\n", getpid(), getppid());
    write(1, buf, strlen(buf));
  }
}

void ParentProcess(void) {
  pid_t pid = fork();

  if (pid == 0)
    ChildProcess();
  else
    Children();
}

void Children(void) {
  int status;
  pid_t pid;
  int num_processes = 2;
  char buf[Buff];
  
  while (num_processes > 0) {
    pid = wait( & status);
    sprintf(buf, "Child Pid: %d has completed\n", pid);
    write(1, buf, strlen(buf));
    num_processes--;
  }
}

