#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdint.h>
#include "shell_controll.h"

/*
-> --code/-c= file.txt: code, кодировать текст из файла file.txt 
-> --decode/-d= file.txt: decode, декодировать текст из файла file.txt
-> --to/-t= куда вывести результат(перезаписать файл или создать новый) 
примеры:
 --code file.txt --to new.txt (кодирует file.txt в new.txt)
 --decode file.txt --to (раскодировать файл file.txt и перезаписать его)
изначально программа перезаписывает файл file.txt
чтобы сохранить file.txt в оригинале нужно указать выходной файл output.txt:
./prog -c file.txt output.txt

*/

int main(int argc, char *argv[]){
	uint8_t flag=0;
	char names[256][2]={0};
	check_argc(argc);
	take_flags(argc, argv, &flag, names);
	printf("the value of flag is: %d", flag);
}
