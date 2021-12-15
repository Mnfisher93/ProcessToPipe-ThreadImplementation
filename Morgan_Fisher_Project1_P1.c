//** Morgan Fisher **//
//** Operating Sytems Project 1  **//
//** Part 1 **//
//** Refrences: Slides, Textbook **//

#include <stdio.h>
#include <stdlib.h> 
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>



int main() {

  //** This is used for each end of pipe **//
  int fd[2];
  //** pid datatype declaration **//
  pid_t pid;
  //** Create an array with the following numbers 3,8,12,21,1,7,23,18,15,10 **//

  int arr[] = {3,8,12,21,1,7,23,18,15,10};

  //** Create a pipe **//
  if (pipe(fd) == -1){

    fprintf(stderr,"Pipe failed");
     return 1;
  }

  //* Call the fork function to create child/parent process **//

  pid = fork();
  if (pid < 0){

    fprintf(stderr, "Fork Failed");
    return 1;

  }



  //** Sum first 5 value in your array in the child process **//
  if (pid == 0) {  /* child process */

  close(fd[0]);

  int sum1 = 0;
  for (int i = 0; i < 5; i++ ){
    sum1 += arr[i]; 
  }
  //** Write and Close other end of pipe **//
  write(fd[1], &sum1, sizeof(sum1));
  close(fd[1]);
              
  }

  //** Sum Rest of the 5 values in your array in the parent process **//
  else { /* parent process */
  
  close(fd[1]);

  int sum2 = 0;
  for (int i = 5; i < 10; i++ ){
    sum2 += arr[i]; 
  }
  //** Wait for child to finish **//
  wait(NULL);

  //** Sum the two results together, read sum1 **//
  int sum1;
  read(fd[0], &sum1, sizeof(sum1));
      sum2 += sum1;

      printf("%d\n", sum2);
                close(fd[0]);


  }


}
