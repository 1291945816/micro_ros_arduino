
#include "micro_ros_qemu-riscv.h"


extern "C"
{
  #include <stdio.h>
  #include <stdbool.h>
  #include <sys/time.h>

  int clock_gettime(clockid_t unused, struct timespec *tp) __attribute__ ((weak));
  bool riscv_transport_open(struct uxrCustomTransport * transport) __attribute__ ((weak));
  bool riscv_transport_close(struct uxrCustomTransport * transport) __attribute__ ((weak));
  size_t riscv_transport_write(struct uxrCustomTransport * transport, uint8_t *buf, size_t len, uint8_t *errcode) __attribute__ ((weak));
  size_t riscv_transport_read(struct uxrCustomTransport * transport, uint8_t *buf, size_t len, int timeout, uint8_t *errcode) __attribute__ ((weak));

  #define micro_rollover_useconds 4294967295

  int clock_gettime(clockid_t unused, struct timespec *tp)
  {
    
    return 0;
  }

  bool riscv_transport_open(struct uxrCustomTransport * transport)
  {
    return true;
  }

  bool riscv_transport_close(struct uxrCustomTransport * transport)
  {
    return true;
  }

  size_t riscv_transport_write(struct uxrCustomTransport * transport, uint8_t *buf, size_t len, uint8_t *errcode)
  {
    return 0;
  }

  size_t riscv_transport_read(struct uxrCustomTransport * transport, uint8_t *buf, size_t len, int timeout, uint8_t *errcode)
  {

    return 0;
  }
}

