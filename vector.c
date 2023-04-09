#include "vector.h"
#include "stdio.h"
#include "assert.h"


vector createVector(size_t n){
    vector v;
    v.size = 0;

    v.capacity = n > 1 ? n : 1;
    v.data = malloc(sizeof(int) * v.capacity);

    if (v.data == NULL){
        fprintf(stderr, "Bad alloc");
        exit(1);
    }

    return (vector) {v.data, v.size, v.capacity};
}

void reserve(vector *v, size_t newCapacity){
    v->capacity = newCapacity;
    v->size = v->size < newCapacity ? v->size : newCapacity;

    if (newCapacity == 0)
        v->data = NULL;
    else {
        v->data = realloc(v->data, sizeof(int) * newCapacity);

        if (v->data == NULL){
            fprintf(stderr, "bad alloc");
            exit(1);
        }
    }
}

void clear(vector *v){
    v->size = 0;
}

void shrinkToFit(vector *v){
    reserve(v, v->size);
}

void deleteVector(vector *v){
    free(v->data);
    *v = (vector) {NULL, 0, 0};
}

void outputVector(vector v){
    for (int i = 0; i < v.size; i++) {
        printf("%d ", v.data[i]);
    }

    printf("\n");
}

bool isEmpty(vector *v){
    return v->size == 0;
}

bool isFull(vector *v){
    return v->size == v->capacity;
}

int getVectorValue(vector *v, size_t i){
    return v->data[i];
}

void pushBack(vector *v, int x){
    if (v->size == v->capacity){
        reserve(v, v->capacity * 2);
    }

    v->data[(v->size)++] = x;
}

void test_pushBack_emptyVector(){
    vector v = createVector(0);
    pushBack(&v, 10);

    assert(getVectorValue(&v, 0) == 10);
    assert(v.capacity == 1);
    assert(v.size == 1);
}

void test_pushBack_fullVector(){
    vector v = createVector(5);
    v.size = 5;
    pushBack(&v, 10);

    assert(getVectorValue(&v, 5) == 10);
    assert(v.capacity == 10);
    assert(v.size == 6);
}

void popBack(vector *v){
    if (isEmpty(v)){
        fprintf(stderr, "Trying delete from empty vector");
        exit(1);
    }

    (v->size)--;
}

void test_popBack_notEmptyVector() {
    vector v = createVector(0);
    pushBack(&v, 10);

    assert(v.size == 1);

    popBack(&v);
    assert(v.size == 0);
    assert(v.capacity == 1);
}

int* atVector(vector *v, size_t index){
    if (index > v->size){
        fprintf(stderr, "IndexError: a[%d] is not exists", index);
        exit(1);
    }

    return v->data + index;
}

int* back(vector *v){
    return v->data + (v->size - 1);
}

int* front(vector *v){
    if (v->size == 0) {
        fprintf(stderr, "IndexError: a[0] is not exists");
        exit(1);
    }

    return v->data;
}

void test_atVector_notEmptyVector() {
    vector c = createVector(1);

    pushBack(&c, 1);
    pushBack(&c, 2);
    int *ref = atVector(&c, 0);

    assert(*ref == 1);
    assert(*(ref + 1) == 2);
}

void test_atVector_requestToLastElement() {
    vector c = createVector(1);

    pushBack(&c, 1);
    pushBack(&c, 2);
    int *ref = atVector(&c, 1);

    assert(*ref == 2);
    assert(*(ref + -1) == 1);
    assert(c.capacity == 2);
}

void test_back_oneElementInVector() {
    vector c = createVector(1);

    pushBack(&c, 5);
    int *ref = back(&c);

    assert(*ref == 5);
}

void test_front_oneElementInVector() {
    vector c = createVector(1);

    pushBack(&c, 5);
    int *ref = front(&c);

    assert(*ref == 5);
}
