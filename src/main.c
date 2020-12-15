#include "primes.h"
#include <stdio.h>
#include <time.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

int congruent_module_n(int number, int module){
  int congruent = 0;
  for( ; congruent < number ; ++congruent){
    if( ( number % module ) == ( congruent % module ) )  break;
  }
  return congruent;
}

int inverse_module_n(int expo, int module){
  int inverse = 0;
  for( ;  ; ++inverse){
    if( ( 1 % module ) == ( expo*inverse % module ) )  break;
  }
  return inverse;
}

int private_key_rsa(int p, int q){
  return inverse_module_n( 3, (p-1)*(q-1)  );
}

void encrypt_rsa(int * string, int n, int size_string){
  for(int i = 0; i <= size_string; ++i){
    string[i] = toupper( string[i] );
    string[i] = string[i] - 55;
    string[i] = pow(string[i], 3);
    string[i] = congruent_module_n(string[i], n);
  }
}

void decrypt_rsa(int * string, int size_string, int d, int n){
  for(int i = 0; i <= size_string; ++i){
    string[i] = pow(string[i], d);
    string[i] = congruent_module_n(string[i], n);
  }
}


int main(void) {
  int p = 5;
  int q = 11;
  int n = q * p;
  int d = private_key_rsa(p, q);
  int vet[3] = {'R', 'S', 'A'};
  
  printf(" ----data---- \np = %i\nq = %i\nn = %i\nd = %i", p,q,n,d);
  printf("\n'RSA' is the string\n");

  encrypt_rsa(vet, n, 2);

  for(int i = 0; i < 3; ++i) printf(" %i ", vet[i]);
  
  printf(" is the string encrypted\n");

  decrypt_rsa(vet, 2, d, n);


  for(int i = 0; i < 3; ++i) printf(" %i ", vet[i]);
  
  printf(" is the string decrypted\n");

  //printf("\n%i\n", inverse_module_n(3, 4*10));

	return 0;
}
