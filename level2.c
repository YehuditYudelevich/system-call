#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
int main(){
	int fd=open("level2.txt",O_WRONLY | O_CREAT,0644);
	if(fd==-1){
		perror("Error opennig file");
		return 1;
	}
	char *msg="\nim yehudit, checking level 2 using write function\n";
	write(fd,msg,strlen(msg));
	close(fd);
	return 0;

}
