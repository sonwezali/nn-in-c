/*********************************
 |  neural network in c playing  |
 |      rock paper scissor       |
 *********************************/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "nn.h"
extern Neuron defaultNeuron;
// #define Neuron() defaultNeuron --> i dont want this level of abstraction
#include "value.h"

char moves[][9] = {"rock\0", "paper\0", "scissors\0"};

float train[][3] = {
    {0, 0, 0},
    {0, 1, 1},
    {0, 2, 0},
    {1, 0, 0},
    {1, 1, 0},
    {1, 2, 1},
    {2, 0, 1},
    {2, 1, 0},
    {2, 2, 0}
};

float rand_float() {
    return 2 * ((float)rand()/(float)RAND_MAX);
}

int float_to_int(float x) {
    return (ceil(x) - x) < (x - floor(x)) ? (int)ceil(x) : (int)floor(x);
}

char* rand_move() {
    return moves[float_to_int(rand_float())];
}

/*
 * typedef struct {
 *     float* weights; // array of weights
 *     int nin;
 *     float bias;
 *     void (*printData)(float val);
 * } Neuron;
 */

int main() {
    srand(time(NULL));
    printf("%s\n", rand_move());
    Neuron n = {
        createNewWeights(5),
        5,
        0.78,
        &printNeuronWeights
    };

    (*n.printWeights)(n.weights, n.nin);

    Value testVal0 = {
        6.0,
        0.0,
        NULL
    };

    Value testVal1 = {
        2.0,
        0.0,
        &testVal0
    };

    printf("testVal0.data: %0.4f\n", (*(Value *)(testVal1.children)).data);

    return 0;
}

