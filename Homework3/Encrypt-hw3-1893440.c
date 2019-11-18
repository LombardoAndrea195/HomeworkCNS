#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/time.h>
/*

	Formato :  <fileinput> <fileouput> 

*/
#define SIZE 512
int main(int argc, char*argv[]) {
    if(argc<3){
        fprintf(stderr,"Errore in numero di parametri passati\n");
        exit(1);
    }
    else{
        struct timeval tv1, tv2, tv3, tv4;
	
        struct timeval tv5, tv6, tv7, tv8;
	
        double total_time,total_time1,total_time2,total_time3;
        char* stringa;
	char* stringa1;
	char* key;
      	char decryption[245];
	char decryption1[245];
        stringa=malloc(sizeof(char)*SIZE);
        if(stringa==NULL){
            fprintf(stderr,"Errore in malloc\n");
            exit(EXIT_FAILURE);
        }
	key=malloc(sizeof(char)*SIZE);
        if(key==NULL){
            fprintf(stderr,"Errore in malloc\n");
            exit(EXIT_FAILURE);
        }
	stringa1=malloc(sizeof(char)*SIZE);
        if(stringa1==NULL){
            fprintf(stderr,"Errore in malloc\n");
            exit(EXIT_FAILURE);
        }
	fprintf(stdout,"Insert key through you can make testing:\n");

	if(fgets(key,SIZE,stdin)==NULL){
        perror("Errore nell'fgets\n");
        exit(EXIT_FAILURE);
    	}
	int len=(int)strlen(key);
    	if(key[len-1]=='\n'){
      	  key[len-1]='\0';
   	}
        strcpy(stringa,"openssl enc ");
	strcpy(stringa1,stringa);
        strcat(stringa,"-aes-256-cbc -k ");
        strcat(stringa1,"-aes-256-gcm -k ");
	strcat(stringa,key);
	strcat(stringa1,key);
	
	strcat(stringa," -pbkdf2");
	strcat(stringa1," -pbkdf2");
	strcpy(decryption,stringa);
	strcpy(decryption1,stringa1);
        strcat(stringa," -e -in ");
        strcat(stringa1," -e -in ");

        strcat(decryption," -d -in ");	
        strcat(decryption1," -d -in ");

        strcat(stringa,argv[1]);
        strcat(stringa," -out ");
        strcat(stringa,argv[2]);
	strcat(stringa1,argv[1]);
        strcat(stringa1," -out ");
	strcat(stringa1,argv[2]);
       

        strcat(decryption,argv[2]);
        strcat(decryption," -out ");
        strcat(decryption,argv[1]);
	strcat(decryption1,argv[2]);
        strcat(decryption1," -out ");
	strcat(decryption1,argv[1]);

        gettimeofday(&tv1,NULL);
        system(stringa);
        gettimeofday(&tv2,NULL);
        gettimeofday(&tv5,NULL);
        system(decryption);
        gettimeofday(&tv6,NULL);
	gettimeofday(&tv3,NULL);
        system(stringa1);
        gettimeofday(&tv4,NULL);

        total_time = ((double)(tv2.tv_usec -tv1.tv_usec) /1000000 +(double)(tv2.tv_sec - tv1.tv_sec));
        fprintf(stdout,"Encryption Speed with aes-256-cbc: %lf\n",total_time);
        
	
        total_time1 = ((double)(tv4.tv_usec -tv3.tv_usec) /1000000 +(double)(tv4.tv_sec - tv3.tv_sec));
	fprintf(stdout,"Encryption Speed with aes-256-gcm: %lf\n",total_time1);
        
	
	gettimeofday(&tv7,NULL);
        system(decryption1);
        gettimeofday(&tv8,NULL);

        total_time2 = ((double)(tv6.tv_usec -tv5.tv_usec) /1000000 +(double)(tv6.tv_sec - tv5.tv_sec));
        fprintf(stdout,"Decryption Speed with aes-256-cbc: %lf\n",total_time2);
        
	
        total_time3 = ((double)(tv8.tv_usec -tv7.tv_usec) /1000000 +(double)(tv8.tv_sec - tv7.tv_sec));
	fprintf(stdout,"Decryption Speed with aes-256-gcm: %lf\n",total_time3);
              


	fprintf(stdout,"SPEED RATIO aes-256-cbc: %lf\n",total_time/total_time2);

	fprintf(stdout,"SPEED RATIO aes-256-gcm: %lf\n",total_time1/total_time3);

	fprintf(stdout,"GCM %lf\t&%lf\t&%lf\t",total_time1,total_time3,total_time1/total_time3);
	fprintf(stdout,"CBC %lf\t&%lf\t&%lf\t",total_time,total_time2,total_time/total_time2);
	
        exit(EXIT_SUCCESS);
    }
}
