#include <stdio.h>
// William Berthouex
// Homework 2
// due 9/23/21
/* 1. Convert 0xFEBADC98 from hex to binary
   1111 1110 1011 1010 1101 1100 1001 1000

   2. Convert 10101111 01010011 10111001 10001010 from binary to hex
   0xAF53B98A

   3. Convert 0x0000AB from hex to decimal
   0000 0000 0000 0000 1010 1011
   2^7 + 0 + 2^5 + 0 + 2^3 + 0 + 2 + 1
   171

   4. Convert 11111110 from binary to decimal
   2^7 + 2^6 + 2^5 + 2^4 + 2^3 + 2^2 + 2 + 0
   254
 */

int prob259(int x, int y){
  // an expression that consists of the least significant byte of x and
  // the remaining bytes of y
  return (x & 0xFF) | (y & ~0xFF);
}

unsigned replace_byte(unsigned x, int i, unsigned char b) {
  int toReplace = i << 3;

  // Remove the bit at position i
  // by masking with 1's and complementing the result
  // so 0's are in the desired position
  x = ~(x | (0xFF << toReplace));

  // complement b
  b = ~b;
  
  // insert the complemented b and complement result
  // the desired bit has been replaced
  return ~(x | (b << toReplace));
}

int prob261A(int x){
  // any bit of x equals 1
  return !(!x);
}

int prob261B(int x){
  // any bit of x equals 0
  return (~x) || 0;
}

int prob261C(int x){
  // any bit in the least significant byte equals 1
  return (x & 0xFF) && 1; // least significant
}

int leftmost_one(unsigned x){
  // 2.66
  // no Loops
  // shift to the right until all bits left of the leftmost 1 are set to 1 themselves
  x |= (x >> 16);
  
  x |= (x >> 8);
  
  x |= (x >> 4);
  
  x |= (x >> 2);
  
  x |= (x >> 1);
  
  // shift left by one, use XOR to clear all other bits, leaving only the leftmost 1
  x ^= (x >> 1);
  return x;
}

int lower_one_mask(int n){
  // 2.68
  // create a bit vector with only a 1 followed by n - 1 0's
  int r = 0x1 << (n - 1);
  // shift right step by step to fill with 1's
  // just like in 2.66
  r |= (r >> 16);
  r |= (r >> 8);
  r |= (r >> 4);
  r |= (r >> 2);
  r |= (r >> 1);
  return r;
}

int main() {
  // problem 2.59
  printf("\nProblem 2.59:\n");
  int x = 0x89ABCDEF;
  int y = 0x76543210;
  printf("0x%X\n", prob259(x, y));

  // problem 2.60
  printf("\nProblem 2.60:\n");
  printf("0x%X\n", replace_byte(0x12345678, 2, 0xAB));
  printf("0x%X\n", replace_byte(0x12345678, 0, 0xAB));

  // problem 2.61
  printf("\nProblem 2.61:\n");
  printf("%d\n", prob261A(0x8));             // returns 1
  printf("%d\n", prob261B(-1));              // returns 0 
  printf("%d\n", prob261C(0x100));           // returns 0 

  // problem 2.66
  printf("\nProblem 2.66:\n");
  printf("0x%X\n", leftmost_one(0xFF00));
  printf("0x%X\n", leftmost_one(0x6600));

  // problem 2.68
  printf("\nProblem 2.68:\n");
  printf("0x%X\n", lower_one_mask(6));
  printf("0x%X\n", lower_one_mask(17));
  printf("0x%X\n", lower_one_mask(32));
}
