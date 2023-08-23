/**
 * Machine learning example. 
 * In this example we will try to find the best weight for a linear function.
 * author: Andreas Nilsson
 * an224qi@student.lnu.se
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Training data
int train[][6] = {
    {0,0},
    {1,1},
    {2,4},
    {3,6},
    {4,8},
    {5,10},
    {6,12}
};

// Number of training examples
#define train_count sizeof(train) / sizeof(int)

// Random float between 0 and 1
float rand_float() {
    return (float)rand() / (float)RAND_MAX;
}

// Cost function
float cost(float w) {
    float result = 0.0f; // Cost
    
    for(size_t i = 0; i < train_count; ++i) {

        float x = train[i][0]; // Input val
        float y = w*x; // Computed training result
        float d = y - train[i][1]; // Diff between computed training result and expected result.
        result += d*d;  
    }
    
    result /= train_count;
    
    return result;
}

int main()
{
    srand(time(NULL));
    float w = rand_float()*10.0f;

    float eps = 1e-3; 
    float rate = 1e-1;

    for(size_t i = 0; i < 40; ++i) {
        float dcost = (cost(w + eps) - cost(w)) / eps; // Finite difference, approximates the derivative.
        w -= rate * dcost; // Update weight
        printf("w: %f dcost: %f Cost: %f, \n", w, dcost, cost(w)); // Print current weight, derivative and cost.
    }

    printf("\n y = %fx\n\n", w); // Print the final weight.

    return 0;
}