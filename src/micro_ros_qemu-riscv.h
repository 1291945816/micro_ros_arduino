
#ifndef MICRO_ROS_QEMU_RISCV
#define MICRO_ROS_QEMU_RISCV


#include <uxr/client/transport.h>

// In GNU C < 6.0.0 __attribute__((deprecated(msg))) is not supported for enums, used in rmw/types.h
#if __GNUC__ < 6
#define aux__attribute__(x) __attribute__(x)
#define __attribute__(x)
#endif

#include <rmw_microros/rmw_microros.h>

#if __GNUC__ < 6
#undef __attribute__
#define __attribute__(x) aux__attribute__(x)
#endif

// 采用  默认协议支持

extern "C" 	bool riscv_transport_open(struct uxrCustomTransport * transport) ;
extern "C" 	bool riscv_transport_close(struct uxrCustomTransport * transport) ;
extern "C" 	size_t riscv_transport_write(struct uxrCustomTransport * transport, uint8_t *buf, size_t len, uint8_t *errcode) ;
extern "C" 	size_t riscv_transport_read(struct uxrCustomTransport * transport, uint8_t *buf, size_t len, int timeout, uint8_t *errcode) ;
extern "C" 	int clock_gettime(clockid_t unused, struct timespec *tp);

// 配置默认的协议支持
static inline void set_microros_transports(){
	rmw_uros_set_custom_transport(
		true,
		NULL,
		riscv_transport_open,
		riscv_transport_close,
		riscv_transport_write,
		riscv_transport_read
	);
}







#endif  // MICRO_ROS_QEMU_RISCV
