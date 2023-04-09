//
// Created by Key on 08.04.2023.
//

#ifndef VECTORS_VECTOR_H
#define VECTORS_VECTOR_H

#include "stdlib.h"

typedef struct vector {
    int *data; // указатель на элементы вектора
    size_t size; // размер вектора
    size_t capacity; // вместимость вектора
} vector;

vector createVector(size_t n);

void reserve(vector *v, size_t newCapacity);

void clear(vector *v);

void shrinkToFit(vector *v);

void deleteVector(vector *v);

#endif //VECTORS_VECTOR_H
