#include<unistd.h>
#include<sys/syscall.h>
#include <fcntl.h>
#include <string.h>
#include <stdio.h>
int main(){
	int fd=syscall(SYS_open,"level3.txt",O_WRONLY |O_CREAT,0644);
	if(fd==-1){
		perror("Error openning file");
		return 1;
	}
	char *msg="hi, im yehudit checking levle 3, using syscall\n";
	syscall(SYS_write,fd,msg,strlen(msg));
	syscall(SYS_close,fd);
	return 0;
}
