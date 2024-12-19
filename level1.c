#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(){
	FILE *file=fopen("level1.txt","w");
	if(file==NULL){
		perror("Error openning the file\n");
		return 1;
	}
	char *msg="hi,im yehudit, checking level 1";
	fwrite(msg,sizeof(char),strlen(msg),file);
	fclose(file);
	return 0;
}



