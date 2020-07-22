#include <stdio.h>
#include <stdlib.h>
#include "bmp_l1.h"

int main(void)
{
  FILE *fp;
  size_t writtenSize;
  uint8_t *pbmp, *pbmp_resize;

  // Set allocate functions
  BMP_L1_setAllocFunc(malloc, free);

  // Create image (100pixel x 100pixel)
  pbmp = BMP_L1_create(100, 100);
  if(pbmp == NULL) {
    printf("Failed to create image\n");
    return -1;
  }

  // Fill image White
  BMP_L1_fill(pbmp, BMP_L1_WHITE);

  // Draw line (20,50) - (70,60)
  BMP_L1_drawLine(pbmp, 20, 50, 70, 60, BMP_L1_BLACK);

  // Draw rectangle (10,20) - (30,30)
  BMP_L1_drawRect(pbmp, 10, 20, 30, 30, BMP_L1_BLACK);

  // Draw text
  BMP_L1_drawText(pbmp, "ABC", BMP_L1_FONT_6X10, 10, 80, BMP_L1_BLACK);

  // Save image
  fp = fopen("output.bmp", "wb");
  if (fp == NULL) {
      printf("Failed to open file\n");
      return -1;
  }
  writtenSize = fwrite((uint8_t *)pbmp, sizeof(uint8_t), BMP_L1_getFileSize(pbmp), fp); 
  if( (writtenSize * sizeof(uint8_t)) != BMP_L1_getFileSize(pbmp)) {
    printf("Failed to write image\n");
    return -1;
  }
  fclose(fp);


  // Resize image (200pixel x 70pixel)
  pbmp_resize = BMP_L1_resize_bicubic(pbmp, 200, 70);
  if(pbmp_resize == NULL) {
    printf("Failed to create resize image\n");
    return -1;
  }

  // Save resize image
  fp = fopen("output_resize.bmp", "wb");
  if (fp == NULL) {
      printf("Failed to open file\n");
      return -1;
  }
  writtenSize = fwrite((uint8_t *)pbmp_resize, sizeof(uint8_t), BMP_L1_getFileSize(pbmp_resize), fp); 
  if( (writtenSize * sizeof(uint8_t)) != BMP_L1_getFileSize(pbmp_resize)) {
    printf("Failed to write image\n");
    return -1;
  }
  fclose(fp);

  BMP_L1_free(pbmp);
  BMP_L1_free(pbmp_resize);
  return 0;
}
