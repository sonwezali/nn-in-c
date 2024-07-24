#include <stdio.h>
#include <stdlib.h>
#include "nn.h"

void printNeuronData(float data) {
    printf("neuron value: %0.4f\n", data);
}

void printNeuronWeights(float* w, int nin) {
    for (int i = 0; i < nin; i++) {
        printf("w%d: %0.4f\n", i, *(w + i));
    }
}

float* createNewWeights(int nin) {
    float* weights = (float*) malloc(sizeof(float) * nin);
    for (int i = 0; i < nin; i++) {
        *(weights + i) = ((float)rand()/(float)RAND_MAX) * 2 - 1; // a value between [-1, 1]
    }

    return weights;
}

/*
 * typedef struct {
 *     float* weights; // array of weights
 *     int nin;
 *     float bias;
 *     float data;
 *     float grad;
 *     void (*printData)(float val);
 * } Neuron;
 */

// Neuron defaultNeuron = {

