#ifndef SD_STM32_HEADER
#define SD_STM32_HEADER

#include "main.h"
#include "diskio.h"
#include <stdint.h>
#include "sd_stm32.h"
#include <string.h>
#include "ff_gen_drv.h"

extern SPI_HandleTypeDef hspi1;
#define SD_SPIDriver	  hspi1

#define TRUE  1
#define FALSE 0
#define bool  char
#define BYTE  char

/* Definitions for MMC/SDC command */
#define CMD0    (0x40+0)    /* GO_IDLE_STATE */
#define CMD1    (0x40+1)    /* SEND_OP_COND */
#define CMD8    (0x40+8)    /* SEND_IF_COND */
#define CMD9    (0x40+9)    /* SEND_CSD */
#define CMD10    (0x40+10)    /* SEND_CID */
#define CMD12    (0x40+12)    /* STOP_TRANSMISSION */
#define CMD16    (0x40+16)    /* SET_BLOCKLEN */
#define CMD17    (0x40+17)    /* READ_SINGLE_BLOCK */
#define CMD18    (0x40+18)    /* READ_MULTIPLE_BLOCK */
#define CMD23    (0x40+23)    /* SET_BLOCK_COUNT */
#define CMD24    (0x40+24)    /* WRITE_BLOCK */
#define CMD25    (0x40+25)    /* WRITE_MULTIPLE_BLOCK */
#define CMD41    (0x40+41)    /* SEND_OP_COND (ACMD) */
#define CMD55    (0x40+55)    /* APP_CMD */
#define CMD58    (0x40+58)    /* READ_OCR */

/*-----------------------------------------------------------------------*/
/* Device Timer Interrupt Procedure  (Platform dependent)                */
/*-----------------------------------------------------------------------*/
/* This function must be called in period of 10ms                        */

void sdcard_systick_timerproc(void);
DSTATUS SD_disk_initialize(BYTE drv);
DSTATUS SD_disk_status(BYTE drv);
DRESULT SD_disk_read(BYTE pdrv, BYTE* buff, DWORD sector, UINT count);
DRESULT SD_disk_write(BYTE pdrv, const BYTE* buff, DWORD sector, UINT count);
DRESULT SD_disk_ioctl(BYTE drv, /* Physical drive nmuber (0) */
BYTE ctrl, /* Control code */
void *buff /* Buffer to send/receive control data */
);

#endif

