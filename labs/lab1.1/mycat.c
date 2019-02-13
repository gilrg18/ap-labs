/* Sources:
 *		http://codewiki.wikidot.com/c:system-calls:open 
 * 		http://codewiki.wikidot.com/c:system-calls:read
 * 		http://codewiki.wikidot.com/c:system-calls:write
 * 		http://codewiki.wikidot.com/c:system-calls:close
 */
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>


#define SIZE_BUF 128

int main(int argc, char *argv[]){

	int file;
	file = open(argv[1], O_RDONLY);	
	char buf[SIZE_BUF]; 	
	
	if(file < 0){
		write(2, "Error: Couldn't read file.\n'", SIZE_BUF);
	}
	while(read(file, buf, SIZE_BUF -1) != 0){
			write(1, buf, SIZE_BUF);
			memset(buf, '\0', SIZE_BUF);
	}

	close(file);

}