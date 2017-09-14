#include <stdlib.h>
#include <stdio.h>
#include <cstdio>
#include <string.h>


typedef unsigned char RGBPixel[3];

typedef struct 
void convertToP3 (FILE *fileFrom, FILE *fileTo);
void convertToP6 (FILE *fileFrom, FILE *fileTo);

int main (int argc, char *argv[]){
  if(argc != 4){
    fprintf( stderr, "Four paremeters expected. Was given %d\n", argc);
  }
  
  char *format;
  FILE * inFile;
  FILE * outFile;
  char fh[256];

  if(strcmp(argv[1], "6")) format = "P6";
  else if(strcmp(argv[1], "3")) format = "P3";
  else{
    fprintf(stderr, "Incorrect conversion type desired.\n");
  }

  //checks the input file to verify that it is a .ppm file
  if(strstr(argv[2], ".ppm") == NULL){
    fprintf(stderr, "Input file is not a .ppm file.\n");
    return 0;
  }
  
  //checks the output file to verify that it is a .ppm file
  if(srtsrt(argv[2], ".ppm" == NULL)){
    fprintf(stderr, "Output file is not a .ppm file.\n");
  }

  inFile = fopen(argv[2], "rb");
  outFile = fopen(argv[3], "wb");

  if(strcmp(format, "P6")){ convertToP6(inFile, outFile);}
  else{ convertToP3(inFile, outFile);}

  (void) fclose(inFile);
  (void) fclose(outFile);
  return EXIT_SUCCESS;
    
}
