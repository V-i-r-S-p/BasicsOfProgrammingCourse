//
// Created by Key on 08.04.2023.
//

#ifndef VECTORS_VECTOR_H
#define VECTORS_VECTOR_H

#include "stdlib.h"
#include "stdbool.h"

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

bool isEmpty(vector *v);

bool isFull(vector *v);

int getVectorValue(vector *v, size_t i);

void pushBack(vector *v, int x);

void test_pushBack_emptyVector();

void test_pushBack_fullVector();

void popBack(vector *v);

void test_popBack_notEmptyVector();

#endif //VECTORS_VECTOR_H
