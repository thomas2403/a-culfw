#ifndef __ringbuffer_H_
#define __ringbuffer_H_

#ifndef TESTING
#include <stdint.h>                     // for uint8_t

#include "board.h"                      // for TTY_BUFSIZE
#endif

#if TTY_BUFSIZE < 256
typedef struct
{
  uint8_t putoff;
  uint8_t getoff;
  uint8_t nbytes;       // Number of data bytes
  char buf[TTY_BUFSIZE];
} rb_t;
#else
typedef struct
{
  uint16_t putoff;
  uint16_t getoff;
  uint16_t nbytes;       // Number of data bytes
  char buf[TTY_BUFSIZE];
} rb_t;
#endif

#ifdef TTY_BUFSIZE_TX
typedef struct
{
	uint16_t putoff;
	uint16_t getoff;
	uint16_t nbytes;       // Number of data bytes
	char buf[TTY_BUFSIZE_TX];
} rbtx_t;
#endif

void rb_put(rb_t *rb, uint8_t data);
uint8_t rb_get(rb_t *rb);
void rb_reset(rb_t *rb);

#ifdef TTY_BUFSIZE_TX
void rbtx_put(rbtx_t *rb, uint8_t data);
uint8_t rbtx_get(rbtx_t *rb);
void rbtx_reset(rbtx_t *rb);
#endif

#endif
