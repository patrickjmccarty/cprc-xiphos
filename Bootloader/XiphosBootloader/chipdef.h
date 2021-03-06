#ifndef CHIPDEF_H
#define CHIPDEF_H

#include <avr/io.h>

#if defined (SPMCSR)
#define SPM_REG SPMCSR
#elif defined (SPMCR)
#define SPM_REG SPMCR
#else
#error "AVR processor does not provide bootloader support!"
#endif

#define APP_END (FLASHEND - (BOOTSIZE * 2))

#if (SPM_PAGESIZE > UINT8_MAX)
typedef uint16_t pagebuf_t;
#else
typedef uint8_t pagebuf_t;
#endif

#if defined(__AVR_ATmega1281__)
#include "mega1281.h"

#else
#error "no definition for MCU available in chipdef.h"
#endif

#endif
