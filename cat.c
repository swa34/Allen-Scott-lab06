#include <fcntl.h>   
#include <stdio.h>    
#include <unistd.h>    // for read(), write(), close()

#define BUF_SIZE 2048

void filecopy(int fileOne, int fileTwo); /* prototype for function */


int main(int argc, char *argv[]) {
  int i, fd, ch;    
  if (argc == 1) /* no args; copy standard input */
  { filecopy(0, 1); }
  for (i = 1; i < argc; i++) {
	fd = open(argv[i], O_RDONLY | O_CREAT);
	if (fd < 0) {
	  perror(argv[i]);
	  continue;
	}
	while (read(fd, &ch, 1) == 1)
	  write(STDOUT_FILENO, &ch, 1);
	close(fd);
  }
}
/* filecopy copy file fileOne to fileTwo */
void filecopy(int fileOne, int fileTwo) {
  char buffer[BUF_SIZE];
  int c;
  while ((c = read(fileOne, buffer, BUF_SIZE)) != 0)
	write(fileTwo, buffer, c);

}



