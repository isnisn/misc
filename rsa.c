#include <stdlib.h>
#include <math.h>
#include <stdio.h>


int gcd(int a, int h) {
    
    int temp;
    while (1) {
        temp = a % h;
        if (temp == 0)
            return h;
        a = h;
        h = temp;
    }
}

int main(void) {

    // Choose two random primes.
    int p = 398737894234, q = 234234234237;

    // Find the first part of public key
    int n = p * q;

    // Next part of public key
    int e = 2;
    int phi = (p-1)*(q-1);

    while(e < phi) {
        if(gcd(e,phi) == 1)
            break;
        else
        e++;
    }
    
    // Private key (d stands for decrypt)
    // choosing d such that it satisfies
    // d*e = 1 + k * totient
    int k = 2; // A constant value
    int d = (1 + (k * phi)) / e;
 
    // Message to be encrypted
    int msg = 876542;
 
    printf("Message data = %d", msg);
 
    // Encryption c = (msg ^ e) % n
    int c = pow(msg, e);
    c = fmod(c, n);
    printf("\nEncrypted data = %d", c);
 
    // Decryption m = (c ^ d) % n
    int m = pow(c, d);
    m = fmod(m, n);
    printf("\nOriginal Message Sent = %d", m);

    return 0;
}