#include <stdlib.h>
#include <stdio.h>
#include <time.h>

//Author: Camrin Coco and Jackson Wiese
//Purpose: Jacobsthal equation
//Date: 2023.11.14

long long Jacobsthal (int n);

/**
 * This program computes the n-th Jacobsthal number using recursion.
 * It also reports how long the program takes to execute.
 *
 */
int main(int argc, char **argv) {

  if (argc != 2) {
    fprintf(stderr, "Usage: %s n\n", argv[0]);
    exit(1);
  }
  int n = atoi(argv[1]);

  time_t start, end;
  start = time(NULL);
  //TODO: call your function here
  long long result = Jacobsthal(n);
  end = time(NULL);

  int time = (end - start);

  printf("Jacobsthal(%d) = %lld\n", n, result);

  printf("Computation Time: %d seconds\n", time);

  return 0;
}

long long Jacobsthal(int num) {

  if (num == 0){
      return 0;
  }

  if (num == 1){
      return 1;
  }

  return (Jacobsthal(num - 1) + (2 * Jacobsthal(num - 2)));
}



