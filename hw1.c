#include <stdio.h>
#include <limits.h>

void ranges() {
  // Print minimum and maximum legal values
  printf("Signed CHAR\n");
  printf("Minimum value : %i\nMaximum value : %i\n", SCHAR_MIN, SCHAR_MAX);
  
  printf("\nUnsigned CHAR\n");
  printf("Minimum value : %u\nMaximum value : %u\n", 0, UCHAR_MAX);
  
  printf("\nSigned INT\n");
  printf("Minimum value : %i\nMaximum value : %i\n", INT_MAX, INT_MIN);
  
  printf("\nUnsigned INT\n");
  printf("Minimum value : %u\nMaximum value : %u\n", 0, UINT_MAX);
  
  printf("\nSigned SHORT\n");
  printf("Minimum value : %i\nMaximum value : %i\n", SHRT_MIN, SHRT_MAX);
  
  printf("\nUnsigned SHORT\n");
  printf("Minimum value : %u\nMaximum value : %u\n", 0, USHRT_MAX);
  
  printf("\nSigned LONG\n");
  printf("Minimum value : %ld\nMaximum value : %ld\n", LONG_MIN, LONG_MAX);
  
  printf("\nUnsigned LONG\n");
  printf("Minimum value : %lu\nMaximum value : %lu\n", 0, ULONG_MAX);
  
  printf("\nSigned LONG LONG\n");
  printf("Minimum value : %lld\nMaximum value : %lld\n", LLONG_MIN, LLONG_MAX);
  
  printf("\nUnsigned LONG LONG\n");
  printf("Minimum value : %llu\nMaximum value : %llu\n", 0, ULLONG_MAX);
  //END RANGES
}

int funSum1(int n) {
  int res = 0;
  // Use a FOR loop to sum numbers
  for (int i = 1; i <= n; i++) {
    if (i % 6 == 0 || i % 7 == 0) {
      res += i;
    }
  }
  return res;
}

int funSum2(int n) {
  int res = 0;
  // Use a WHILE loop to sum numbers
  while (n > 0) {
    if (n % 6 == 0 || n % 7 == 0) {
      res += n;
    }
    n--;
  }
  return res;
}

int funSum3(int n) {
  int res = 0;
  // Use a DO-WHILE loop to sum numbers
  do {
    if (n % 6 == 0 || n % 7 == 0) {
      res += n;
    }
    n--;
  }
  while (n > 0);
  return res;
}

int funSum4(int n) {
  // Use recursion to sum numbers
  if (n == 0) { return 0; }
  if (n % 6 == 0 || n % 7 == 0) {
    return n + funSum4(n - 1);
  }
  return funSum4(n - 1);
}


void types() {
  // Print the address of each variable
  char character1, character2, character3;
  short int shortVar1, shortVar2, shortVar3;
  int integer1, integer2, integer3;
  double decimal1, decimal2, decimal3;
  
  printf("&character1 = %p, %lu\n", &character1, &character1);
  printf("&character2 = %p, %lu\n", &character2, &character2);
  printf("&character3 = %p, %lu\n", &character3, &character3);
  printf("&shortVar1 = %p, %lu\n", &shortVar1, &shortVar1);
  printf("&shortVar2 = %p, %lu\n", &shortVar2, &shortVar2);
  printf("&shortVar3 = %p, %lu\n", &shortVar3, &shortVar3);
  printf("&integer1 = %p, %lu\n", &integer1, &integer1);
  printf("&integer2 = %p, %lu\n", &integer2, &integer2);
  printf("&integer3 = %p, %lu\n", &integer3, &integer3);
  printf("&decimal1 = %p, %lu\n", &decimal1, &decimal1);
  printf("&decimal2 = %p, %lu\n", &decimal2, &decimal2);
  printf("&decimal3 = %p, %lu\n", &decimal3, &decimal3);
}

// test code; do not modify
int main() {

  ranges();

  printf("funSum1(20) = %d\n", funSum1(20));
  printf("funSum2(20) = %d\n", funSum2(20));
  printf("funSum3(20) = %d\n", funSum3(20));
  printf("funSum4(20) = %d\n", funSum4(20));
  printf("\n");

  types();

  return 0;
}
