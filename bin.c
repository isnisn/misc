/*
* This program converts a decimal number to binary and vice versa.
* author: Andreas Nilsson
* an224qi@student.lnu.se
*/

#include <stdio.h>
#include <string.h>

void convertToBin(int n);
void convertToDec(int n);

// Convert a decimal number to binary
void convertToBin(int n) {

  if(n > 0) {
    int x = 1024; // 10-bit conversion
    
    printf("%d = ", n);
    for(int i = 1024; i > 0; i >>= 1) {
        if(n > n % i) {
            printf("1");
            n = n % i;
            
        } else {
            printf("0");
        }
    }
    printf("\r\n");
  }
}

// Convert a binary number to decimal
void convertToDec(int n) {
  
  // Max 29 char + 1 for null terminator
  char str[30];
  
  sprintf(str,"%d", n); // Convert int to string and store in str

    for(int i = 0; i < strlen(str); ++i) {
      printf("%c", str[i]);
    }
}

int main() {

  // Convert every num in interval [1,20] to binary
  for(int i = 1; i < 20; i++) {
    convertToBin(i);
    //convertToDec(1100100101);
  }
    return 0;
  
}
