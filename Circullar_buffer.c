// circular_buffer.c
#include <stdio.h>
#include <stdlib.h>
#include "Circular_buffer.h"

// Circular buffer arrange function
void arrangeCircularBuffer(struct CircularBuffer* bufferStruct, uint8_t* buffer, uint32_t size) {
        //buffer =(uint8_t*)malloc(size * sizeof(uint8_t));
    bufferStruct->ptrBuff = buffer;
    bufferStruct->head = 0;
    bufferStruct->tail = 0;
    bufferStruct->size = size;
    bufferStruct->count = 0;
}

// Push item to circular buffer function
void pushItemToBuff(struct CircularBuffer* bufferStruct, uint8_t item) {
    if (bufferStruct->count < bufferStruct->size - 1) {
        bufferStruct->ptrBuff[bufferStruct->tail] = item;
        bufferStruct->tail = (bufferStruct->tail + 1) % bufferStruct->size;
        bufferStruct->count++;
    } else {
        // Buffer is full, handle accordingly (e.g., overwrite, ignore, or other actions)
        // Here, we do nothing in case of overflow.
    }
}

// Pop item from circular buffer function
bool popItemFromBuff(struct CircularBuffer* bufferStruct, uint8_t *item) {
    if (bufferStruct->count > 0) {
        *item = bufferStruct->ptrBuff[bufferStruct->head];
        bufferStruct->head = (bufferStruct->head + 1) % bufferStruct->size;
        bufferStruct->count--;
        return false; // Veri çekme başarılı
    } else {
        return true; // Tampon boş, veri çekme başarısız
    }
}

// Pick item from circular buffer with offset function
bool pickItemFromBuff(struct CircularBuffer* bufferStruct, uint8_t *item, uint32_t offset) {
    if (bufferStruct->count > 0 && offset < bufferStruct->count) {
        uint32_t pickIndex = (bufferStruct->head + offset) % bufferStruct->size;
        *item = bufferStruct->ptrBuff[pickIndex];
        return false; // İşlem başarılı
    } else {
        return true; // İşlem başarısız
    }
}

// Check if buffer is empty function
bool isBufferEmpty(struct CircularBuffer* bufferStruct) {
    return (bufferStruct->count == 0);
}

// Delete item from head function
void deleteFromHead(struct CircularBuffer* bufferStruct) {
    if (bufferStruct->count > 0) {
        bufferStruct->head = (bufferStruct->head + 1) % bufferStruct->size;
        bufferStruct->count--;
    }
}

// Get head index function
uint32_t getHead(struct CircularBuffer* bufferStruct) {
    return bufferStruct->head;
}

// Get count function
uint32_t getCount(struct CircularBuffer* bufferStruct) {
    return bufferStruct->count;
}






