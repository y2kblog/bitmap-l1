# Introduction
This library is a open source L1 format (2 color: Black/White) bitmap library.
L1 format is suitable for embedded systems because it does not consume much memory.
You can create/delete bitmap images, get the color of a point, draw points/lines/rectangles, etc.
This library also includes bicubic interpolation function.  
The library consists of only two files: `bmp_l1.c` and `bmp_l1.h`.  

#### File size
<img src="https://latex.codecogs.com/gif.latex?4&space;\lceil&space;\dfrac{w}{32}&space;\rceil&space;h&space;&plus;&space;62&space;\&space;{\rm[bytes]\&space;,&space;where}\&space;w:{\rm&space;width&space;[pixel]},&space;h:{\rm&space;height[pixel]}" title="4 \lceil \dfrac{w}{32} \rceil h + 62 \ {\rm[bytes]\ , where}\ w:{\rm width [pixel]}, h:{\rm height[pixel]}" />
<!-- 4 \lceil \dfrac{w}{32} \rceil h + 62 \ {\rm[bytes]\ , where}\ 
 w:{\rm width [pixel]}, h:{\rm height[pixel]} -->

# Test
`test.c` is test program.  
After downloading this repository, you can run the test program by executing the following command.  
```
gcc -o program test.c bmp_l1.c && ./program
```
