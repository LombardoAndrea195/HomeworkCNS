#include <stdio.h>
/*
Usage ./Create_binary_file <outfile> <size>
*/
void main(int argc, char** argv){
    long long counter, argment;
    FILE* filepointer = fopen(*(argv+1), "w");
    srand(time(NULL));
    sscanf(*(argv+2), "%lld", &argment);  
    for(counter=0;counter<argment;counter++){
        fputc(rand()%255,filepointer);
    }
    fclose(filepointer);
}
