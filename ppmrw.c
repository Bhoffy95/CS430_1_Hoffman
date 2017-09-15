#include <stdlib.h>
#include <stdio.h>
#include <cstdio>
#include <string.h>


typedef unsigned char RGBPixel[3];
#define Size 256;


void convertToP3 (FILE *fileFrom, FILE *fileTo);
void convertToP6 (FILE *fileFrom, FILE *fileTo);

int main (int argc, char *argv[]){
  if(argc != 4){
    fprintf( stderr, "Four paremeters expected. Was given %d\n", argc);
  }
  
  char *format;
  FILE * inFile;
  FILE * outFile;
  char bSize[256];

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

void convertToP6(FILE *inFile, FILE *outFile){
  //creates a buffer to store the comments
  char buffer[Size], *bSize;
  int width;
  int height;
  unsigned int maxColorVal;

  //get the "magic number" from the first byte in the stream
  int charTemp;
  charTemp = fgetc(inFile);
  int[2] mNum = {charTemp, NULL};
  charTemp=fgetc(inFile);
  mNum[1] = charTemp;
  fputc(mNum[0], outFile);
  fputc(mNum[1], outFile);
  fputc("\n", outFile);

  //get the comments and transfer them using the buffer array.
  while(strncmp(buffer, "#", 1) == 0){
    bSize = fgets(buffer, Size, inFile);
    if(srtncmp(buffer, "#", 1) == 0) fprintf(outFile, "%s", buffer);
    printf("%s", buffer);
    if(bSize == NULL) return;
  }
  
  width = fgetc(inFile);
  height = fgetc(inFile);

  //allocate space based on the height and width
  unsigned int *Pixmap;
  Pixamp = (unsigned int *)malloc(width * height * sizeof(int));
  //write the width and height values into the outFile
  fprintf(outFile, "%d %d\n", width, height);
  
  maxColorVal = fgets(buffer, Size, inFile);
  fprintf(outFile, "%d\n", maxColorVal);
  

  
  
}
