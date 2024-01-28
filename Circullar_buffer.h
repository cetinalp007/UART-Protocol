// circular_buffer.h

#ifndef CIRCULAR_BUFFER_H
#define CIRCULAR_BUFFER_H

#include <stdint.h>
#include <stdbool.h>

// Circular buffer struct
struct CircularBuffer {
     uint8_t *ptrBuff; // dizinin ilk elemanını tutacak pointer
     uint32_t head; // en eski eleman pozisyonu
     uint32_t tail; // en yeni eleman pozisyonu
     uint32_t size; // dizi boyutu
     uint32_t count; // dizide güncel kaç eleman var
};

// Fonksiyon tanımları
void arrangeCircularBuffer(struct CircularBuffer* bufferStruct, uint8_t* buffer, uint32_t size);
void pushItemToBuff(struct CircularBuffer* bufferStruct, uint8_t item);
bool popItemFromBuff(struct CircularBuffer* bufferStruct, uint8_t *item);
bool pickItemFromBuff(struct CircularBuffer* bufferStruct, uint8_t *item, uint32_t offset);
bool isBufferEmpty(struct CircularBuffer* bufferStruct);
void deleteFromHead(struct CircularBuffer* bufferStruct);
uint32_t getHead(struct CircularBuffer* bufferStruct);
uint32_t getCount(struct CircularBuffer* bufferStruct);

#endif  // CIRCULAR_BUFFER_H

