/*
This program implements the decryption of a 
random Caesar cipher on the file Caesar_Text.txt.
A Caesar cipher substitutes each letter in
the alphabet with another given letter. This 


*/
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
int main(){
	char alpha[27]="abcdefghijklmnopqrstuvwxyz";
	char caesar[27]="--------------------------";
	char c;
	int i;
	int k,t;
	printf("Input password:\n");
	scanf("%d",&k);
	int j=0,l=0;
	for(i=0;i<26;i++,j=0,l=0){
		while(1){
			if(caesar[l%26]=='-'){
				if(j==k){
					caesar[l%26]=alpha[i];
					break;
				}
				else j++;
			}
			l++;			
		}
	}
	//printf("{%s}\n{%s}\n",alpha,caesar);
	FILE *g;
	g=fopen("Caesar_Text.txt","r+");
for(t=0,rewind(g);t<2;t++){
	while(!feof(g)){
		c=fgetc(g);
		for(i=0;i<26;i++){
			if(caesar[i]==c){
				fseek(g,-1,SEEK_CUR);
				fputc(alpha[i],g);
			}
			else if(toupper(caesar[i])==c){
				fseek(g,-1,SEEK_CUR);
				fputc(toupper(alpha[i]),g);
			}
		}
	}
}
	while(1){
		printf("Is your document correct? y/n\n");
		c='a';
		scanf(" %c",&c);
		if(c=='y') break;
		else if(c=='n'){
		for(t=0,rewind(g);t<2;t++){
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
		}
			printf("Changes restored\n");
			break;
		}
		else printf("Invalid response\n");
	}
	fclose(g);
	return 0;
}

