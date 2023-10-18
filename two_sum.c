#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CAP 1000

typedef struct ofList ofList;
typedef struct Num Num;
unsigned int g_hash(unsigned int);
unsigned int g_unhash(unsigned int);  

// Overflow-list in case of identical hashes / keys. Linear search since it wont be much collisions.
typedef struct ofList {

    struct Num *num;

} ofList;

typedef struct Num {

    int val;
    int index;
    
    // In case of collision.
    struct ofList *of;

} Num;

typedef struct Numbers {

    unsigned int max_cap;

    Num **num;

} Numbers;

Numbers *create_table(int *arr, int size) {

    // Init new hashlist
    Numbers *numbers = malloc(sizeof(Numbers*));

    // Set capacity so we can calloc.
    numbers->max_cap = CAP;

    // Calloc and set all num to NULL
    numbers->num = calloc(numbers->max_cap, sizeof(Num *));
  
    // Make room for all the nums
    for(int i=0;i<CAP;i++) {
        numbers->num[i] = malloc(sizeof(Num *));
        numbers->num[i]->of = malloc(sizeof(ofList*));

        Num *n = malloc(sizeof(Num*));
        
        n->val = 0;
        numbers->num[i]->of->num = n;
    }

    /* Create the actual table.*/
    int i;
    int val;

    for(i=0;i<size;i++) {

        val = arr[i];

        // Collision check
        if(numbers->num[val]->val == val) {

            printf("Exist! \n");

            numbers->num[val]->of->num->val = val;
            numbers->num[val]->of->num->index = i;

            //printf("Col: %d with %d\n",numbers->num[val]->val, val );

        } else {
            numbers->num[val]->index = i;
            numbers->num[val]->val = val;
        }
    }

    return numbers;
}

void find_two_sum(Numbers *numbers, int find, int arrSize) {
    
    int temp;
    int index;

    for(int i=0;i<arrSize;i++) {

        // 77 - 17 = 60 so find 60.
        temp = find - numbers->num[i]->val;
        temp = temp < 0 ? temp*(-1) : temp;

        // Cant use this index again.
        index = numbers->num[i]->index;

        if(numbers->num[temp]->val > 0 && numbers->num[i]->val > 0) {
            
            if(index == numbers->num[temp]->index) { 
                printf("Found the pair for %d! Its %d @ ind: %d & %d @ ind: %d \n", find, temp, numbers->num[temp]->index, numbers->num[i]->val, numbers->num[temp]->of->num->index);
            } else { 
                printf("Found the pair for %d! Its %d @ ind: %d & %d @ ind: %d \n", find, temp, numbers->num[temp]->index, numbers->num[i]->val, numbers->num[i]->index);
            }
        }   
    }
}

int main(void) {

    int arr_i[] = {27,4,5,11,16,4,8};
    int arrSize = sizeof(arr_i) / sizeof(int);
    int * arrPtr = arr_i; 

    // Create hashtable from arr_i, really without the hash... But still
    Numbers *numbers = create_table(arrPtr, arrSize);

    for(int i = 0; i<numbers->max_cap; i++) {
        if(numbers->num[i]->val > 0) {
            printf("Val: %d index: %d \n", numbers->num[i]->val, numbers->num[i]->index);

            //Check collision list
            if(numbers->num[i]->of->num->val > 0) {
                printf("\t Val in collision list: %d index: %d \n", numbers->num[i]->of->num->val, numbers->num[i]->of->num->index);
            }
        }
    }
    
    find_two_sum(numbers,20, arrSize);

    for(int i=0;i<CAP;i++) {
        free(numbers->num[i]->of->num);
        free(numbers->num[i]->of);
        free(numbers->num[i]);
        
        
    }
    free(numbers->num);
    free(numbers);


}