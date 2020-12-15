#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "random.h"

int is_prime(int number){
  int m = number;
  if( m < 2 || m % 2 == 0 ) return 0;
  for(int i = 2; i <= sqrt(m); ++i ){
    if( m % i == 0 ) return 0;
  }
  return 1;
}

int get_prime(int start, int end){
  
  int random = random_number(start, end);

  printf("%i\n", random);
  
  while(!is_prime(random)){
    random = random + 1;
  }
  
  return random;
  
}
