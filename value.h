#ifndef VALUE_H
#define VALUE_H

typedef struct {
    float data;
    float grad;
    void* children; // Value pointer cast must be done
} Value;

#endif

