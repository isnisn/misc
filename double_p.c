#include <stdio.h>

/*
*   
*/

void print(char**);

void swap(char **out) {
    *out = "This is my second string";
}

int main(void) {

    char * right = "Right";
    char * left = "Left";

    char **out;

    out = &right;

    printf("%s has addr: %p and pointed to by 'out' with address: %p\n", *out, *(&out), &out);

    out = &left;

    printf("%s addr: %p \n", *out, *(&out));

}