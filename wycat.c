/*
 * wycat.c
 * Author: Lucas Manker
 * Date: Feb 17, 2020
 *
 * COSC 3750, Homework 4
 *
 * simple version of the cat utility.
 * it reads files and standard input and prints to standard output.
 *
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

int main(int argc, char** argv){
   const int bufferSize = 4096;
   if(argc < 2){
      char* buffer;
      size_t n = bufferSize;
      buffer = malloc(n);
      int num;
      num = getline(&buffer, &n, stdin);
      fwrite(buffer, sizeof(char), num, stdout);
   }
   else{
      int i;
      for(i = 1; i < argc; i++){
         if(!strcmp(argv[i], "-")){
            char* buffer;
            size_t n = bufferSize;
            buffer = malloc(n);
            int num;
            num = getline(&buffer, &n, stdin);
            fwrite(buffer, sizeof(char), num, stdout);
         }
         else{
            FILE *fptr;
            fptr = fopen(argv[i],"r");
            if(!fptr){
               const char *eStr = argv[i];
               perror(eStr);
            }
            else{
               char buffer[bufferSize];
               int numread = fread(buffer, sizeof(char), bufferSize, fptr);
               fwrite(buffer, sizeof(char), numread, stdout);
               fclose(fptr);
            }
         }
      }
   }
   return 0;
}
