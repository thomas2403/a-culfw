//#define TESTING
#ifdef TESTING
#define TTY_BUFSIZE 64
typedef unsigned char uint8_t;
#include <stdio.h>
#endif

#include <avr/interrupt.h>              // for cli
#include <avr/io.h>                     // for SREG
#include <stdint.h>                     // for uint8_t

#include "ringbuffer.h"

#ifndef ARM
#define restoreIRQ(sr)		SREG = sr
#endif

void
rb_reset(rb_t *rb)
{
  rb->getoff = rb->putoff = rb->nbytes = 0;
}

#ifdef TTY_BUFSIZE_TX
void
rbtx_reset(rbtx_t *rb)
{
	rb->getoff = rb->putoff = rb->nbytes = 0;
}
#endif

void
rb_put_int(rb_t *rb, uint8_t data, uint16_t size)
{
  uint8_t sreg;
  sreg = SREG;
  cli();
  if(rb->nbytes >= size) {
	  restoreIRQ(sreg);
    return;
  }
  rb->nbytes++;
  rb->buf[rb->putoff++] = data;
  if(rb->putoff == size)
    rb->putoff = 0;
  restoreIRQ(sreg);
}

void
rb_put(rb_t *rb, uint8_t data)
{
	rb_put_int(rb, data, TTY_BUFSIZE);
}

#ifdef TTY_BUFSIZE_TX
void
rbtx_put(rbtx_t *rb, uint8_t data)
{
	rb_put_int((rb_t *)rb, data, TTY_BUFSIZE_TX);
}
#endif


uint8_t
rb_get_int(rb_t *rb, uint16_t size)
{
  uint8_t sreg;
  uint8_t ret;
  sreg = SREG;
  cli();
  if(rb->nbytes == 0) {
	restoreIRQ(sreg);
    return 0;
  }
  rb->nbytes--;
  ret = rb->buf[rb->getoff++];
  if(rb->getoff == size)
    rb->getoff = 0;
  restoreIRQ(sreg);
  return ret;
}

uint8_t
rb_get(rb_t *rb)
{
	return rb_get_int(rb, TTY_BUFSIZE);
}

#ifdef TTY_BUFSIZE_TX
uint8_t
rbtx_get(rbtx_t *rb)
{
	return rb_get_int((rb_t *)rb, TTY_BUFSIZE_TX);
}
#endif


#ifdef TESTING
void
d_s(rb_t *rb, char *s)
{
  while(*s)
    rb_put(rb, *s++);
}

void
p(rb_t *rb)
{
  uint8_t c;
  while((c = rb_get(rb))) {
    putchar(c);
  }
  putchar('\n');
}


int
main(int ac, char **av)
{
  rb_t buffer;
  rb_reset(&buffer);
  //d_s(&buffer, "T40484269E72E;T40484369001F;");
  d_s(&buffer, "T40484269E743001F;T404847690118;");
  FHT_compress(&buffer);
  p(&buffer);
}
#endif
