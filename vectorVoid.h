
#ifndef VECTORS_VECTORVOID_H
#define VECTORS_VECTORVOID_H

#include <limits.h>
typedef struct vectorVoid {
    void *data;
    size_t size;
    size_t capacity;
    size_t baseTypeSize;

} vectorVoid;

#endif //VECTORS_VECTORVOID_H
