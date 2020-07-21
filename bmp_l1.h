/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef _BMP_L1_H_
#define _BMP_L1_H_

#ifdef __cplusplus
extern "C" {
#endif

/* Include system header files -----------------------------------------------*/
#include <stdint.h>

/* Include user header files -------------------------------------------------*/
/* Exported macro ------------------------------------------------------------*/
#define BMP_L1_WHITE            ((uint8_t)1)
#define BMP_L1_BLACK            ((uint8_t)0)

/* Exported function macro ---------------------------------------------------*/
/* Exported types ------------------------------------------------------------*/
typedef void * (*BMP_L1_Malloc_Function)(size_t);
typedef void   (*BMP_L1_free_Function)(void *);

/* Exported enum tag ---------------------------------------------------------*/
/* Exported struct/union tag -------------------------------------------------*/
/* Exported variables --------------------------------------------------------*/
/* Exported function prototypes ----------------------------------------------*/
extern void		 BMP_L1_setAllocFunc(BMP_L1_Malloc_Function, BMP_L1_free_Function);
extern uint8_t * BMP_L1_create      (uint32_t, uint32_t);
extern void      BMP_L1_free        (uint8_t *);
extern uint32_t	 BMP_L1_getWidth    (uint8_t *);
extern uint32_t  BMP_L1_getHeight   (uint8_t *);
extern uint32_t  BMP_L1_getFileSize (uint8_t *);
extern uint32_t  BMP_L1_getImageSize(uint8_t *);
extern uint32_t  BMP_L1_getOffset   (uint8_t *);
extern void      BMP_L1_setPixel (uint8_t *, uint32_t, uint32_t, uint8_t);
extern void      BMP_L1_getPixel (uint8_t *, uint32_t, uint32_t, uint8_t *);
extern void      BMP_L1_drawLine (uint8_t *, int32_t, int32_t, int32_t, int32_t, uint8_t);
extern void      BMP_L1_drawRect (uint8_t *, uint32_t, uint32_t, uint32_t, uint32_t, uint8_t);
extern void      BMP_L1_fill     (uint8_t *, uint8_t);
extern uint8_t * BMP_L1_copy        (uint8_t *);
extern uint8_t * BMP_L1_resize_bicubic(uint8_t *, uint32_t, uint32_t);

#ifdef __cplusplus
}
#endif

#endif /* _BMP_L1_H_ */

/***************************************************************END OF FILE****/
