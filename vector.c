#include "vector.h"
#include "stdio.h"

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


int main() {
    vector v = createVector(SIZE_MAX);

    return 0;
}