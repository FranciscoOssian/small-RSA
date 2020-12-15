#include <stdlib.h>

int random_number(int start, int end){
  int r = rand() % end + start;
  int b = r;
  return b;
}
