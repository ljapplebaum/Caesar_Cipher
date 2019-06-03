/*
This program implements the encryption of a 
random Caesar cipher on the file Caesar_Text.txt.
A Caesar cipher substitutes each letter in
the alphabet with another given letter. This 

*/
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>
int main(){
	char alpha[27]="abcdefghijklmnopqrstuvwxyz";
	char caesar[27]="--------------------------";
	char d[5]="\0\0\0\0\0";	
	char c;
	int i,k,j=0,l=0;
	while(1){
		printf("Input password or r for random\n");
		fgets(d,5,stdin);
		if(d[0]=='r'){
			srand(time(NULL));
			k=rand()%10000;
			break;
		}
		else if(isdigit(d[0])&&isdigit(d[1])
		&&isdigit(d[2])&&isdigit(d[3])){
			k=atoi(d);
			break;
		}
		else printf("Invalid response\n");
	}
	
	for(i=0;i<26;i++,j=0,l=0){
		while(1){
			if(caesar[l%26]=='-'){
				if(j==k){
					caesar[l%26]=alpha[i];
					break;
				}
				else{
					j++;
				}
			}
			l++;
			
		}
	}
	//printf("{%s}\n{%s}\n",alpha,caesar);
	FILE *g;
	g=fopen("Caesar_Cipher_Text.txt","r+");
	while(!feof(g)){
		c=fgetc(g);
		for(i=0;i<26;i++){
			if(alpha[i]==c){
				fseek(g,-1,SEEK_CUR);
				fputc(caesar[i],g);
			}
			else if(toupper(alpha[i])==c){
				fseek(g,-1,SEEK_CUR);
				fputc(toupper(caesar[i]),g);
			}
		}
	}
	fclose(g);
	printf("Encryption complete\nPassword is {%d}\n",k);
	return 0;
}

