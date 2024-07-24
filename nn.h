#ifndef NN_H
#define NN_H

typedef struct {
    float* weights; // array of weights
    int nin;
    float bias;
    void (*printWeights)(float* w, int nin);
} Neuron;

void printNeuronData(float data);
void printNeuronWeights(float* w, int nin);
float* createNewWeights(int nin);

#endif

