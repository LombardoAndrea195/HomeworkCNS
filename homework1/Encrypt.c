#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/time.h>
/*

	Formato :  <fileinput> <fileouput> <block-cipher-modes> <cryptographic-algorithm> <size-key>

*/
#define SIZE 512
int main(int argc, char*argv[]) {
    if(argc<5){
        fprintf(stderr,"Errore in numero di parametri passati\n");
        exit(1);
    }
    else{
        struct timeval tv1, tv2, tv3, tv4;
	
        double total_time,total_time1 ;
        char* stringa;
	char* stringa1;
       /* char* vappoggio;
        vappoggio=malloc(sizeof(char)*512);
        if(vappoggio==NULL){
            perror("error in malloc");
        }*/
        stringa=malloc(sizeof(char)*SIZE);
        if(stringa==NULL){
            fprintf(stderr,"Errore in malloc\n");
            exit(EXIT_FAILURE);
        }
	stringa1=malloc(sizeof(char)*SIZE);
        if(stringa1==NULL){
            fprintf(stderr,"Errore in malloc\n");
            exit(EXIT_FAILURE);
        }
        strcpy(stringa,"openssl enc ");
        //puts("inserisci da stdin la parola 'Encryption' o 'Decryption' ");
        //scanf(" %[^\n]",vappoggio);
       // fflush(stdin);
        if( strcmp(argv[4],"aes")==0){
            if(strcmp(argv[3],"cbc")==0){
                if( strcmp(argv[5],"256")==0)
                    strcat(stringa,"-aes-256-cbc ");
                if( strcmp(argv[5],"128")==0)
                    strcat(stringa,"-aes-128-cbc ");
                if( strcmp(argv[5],"192")==0)
                    strcat(stringa,"-aes-192-cbc ");
            }
            if(strcmp(argv[3],"ofb")==0){
                if( strcmp(argv[5],"256")==0)
                    strcat(stringa,"-aes-256-ofb ");
                if( strcmp(argv[5],"128")==0)
                    strcat(stringa,"-aes-128-ofb ");
                if( strcmp(argv[5],"192")==0)
                    strcat(stringa,"-aes-192-ofb ");

            }
            if(strcmp(argv[3],"ctr")==0){
                if( strcmp(argv[5],"256")==0)
                    strcat(stringa,"-aes-256-ctr ");
                if( strcmp(argv[5],"128")==0)
                    strcat(stringa,"-aes-128-ctr ");
                if( strcmp(argv[5],"192")==0)
                    strcat(stringa,"-aes-192-ctr ");
            }
            if(strcmp(argv[3],"ecb")==0){
                if( strcmp(argv[5],"256")==0)
                    strcat(stringa,"-aes-256-ecb ");
                if( strcmp(argv[5],"128")==0)
                    strcat(stringa,"-aes-128-ecb ");
                if( strcmp(argv[5],"192")==0)
                    strcat(stringa,"-aes-192-ecb ");

            }

        }
        if( strcmp(argv[4],"des")==0){
            if(strcmp(argv[3],"cbc")==0)
                strcat(stringa,"-des-cbc ");
            if(strcmp(argv[3],"ofb")==0)
                strcat(stringa,"-des-ofb ");
            if(strcmp(argv[3],"ecb")==0)
                strcat(stringa,"-des-ecb ");

        }
        if( strcmp(argv[4],"blowfish")==0){
            if(strcmp(argv[3],"cbc")==0)
                strcat(stringa,"-bf-cbc ");
            if(strcmp(argv[3],"ofb")==0)
                strcat(stringa,"-bf-ofb ");
            if(strcmp(argv[3],"ecb")==0)
                strcat(stringa,"-bf-ecb ");
        }
	strcpy(stringa1,stringa);
//        if(strcmp(vappoggio,"Encryption")==0)
        strcat(stringa," -e -in ");
  //      if(strcmp(vappoggio,"Decryption")==0)
        strcat(stringa1," -d -in ");
        strcat(stringa,argv[1]);
        strcat(stringa," -out ");
        strcat(stringa,argv[2]);
	strcat(stringa1,argv[2]);
        strcat(stringa1," -out ");
        strcat(stringa1,argv[1]);
        gettimeofday(&tv1,NULL);
        system(stringa);
        gettimeofday(&tv2,NULL);
	gettimeofday(&tv3,NULL);
        system(stringa1);
        gettimeofday(&tv4,NULL);
        total_time = ((double)(tv2.tv_usec -tv1.tv_usec) /1000000 +(double)(tv2.tv_sec - tv1.tv_sec));
        //fprintf(stdout,"Encryption Speed: %lf\n",total_time);
        sleep(5);
	
        total_time1 = ((double)(tv4.tv_usec -tv3.tv_usec) /1000000 +(double)(tv4.tv_sec - tv3.tv_sec));
        //fprintf(stdout,"Decryption Speed: %lf\n",total_time1);
	fprintf(stdout,"%lf\t&%lf\t&%lf\t",total_time,total_time1,total_time/total_time1);
	//fprintf(stdout,"SPEED RATIO: %lf\n",total_time/total_time1);

        exit(EXIT_SUCCESS);
    }
}
