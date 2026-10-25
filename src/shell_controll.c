#include "shell_controll.h"
/*
файл содержит в себе реализацию функций по обработке аргументов командной строки
*/ 



/*
первый элемент name - источник
второй - приём, если первый байт 0 - значит файл будет перезаписан
*/
void take_flags(int argc, char *argv[], uint8_t *flag, char name[][2]){
	opterr=0; //выключаем сообщения об ошибках в getopt, нафиг оно надо
	int opt=0;
	struct option options[]={
		{"code", 2, NULL, 'c'},
		{"decode", 2, NULL, 'd'},
		{"to", 2, NULL, 't'},
		{0, 0, 0, 0}
	};
	int option_index=0;
	while((opt=getopt_long(argc, argv, "c::d::", options, &option_index))!=-1){
		switch(opt){
			case 'c':
					(*flag)|=CODE;
					//если параметр указан, копируем. Иначе убиваем программу
					if(optarg){
						size_t len = strlen(optarg);
						strncpy(name[0], optarg, len);
					}
					else{
						puts("enter file name!");
						exit(-1);
					}
					break;
			case 'd':
					(*flag)|=DECODE;
					//если параметр указан, копируем. Иначе убиваем программу
					if(optarg){
						size_t len = strlen(optarg);
						strncpy(name[0], optarg, len);
					}
					else{
						puts("enter file name!");
						exit(-1);
					}
					break;
			case 't':
					//если параметр указан, копируем. Иначе устанавливаем 0 для дальнешей валидации
					if(optarg){
						size_t len = strlen(optarg);
						strncpy(name[1], optarg, len);
					}
					else{
						name[1][0]='\0';
					}
					break;
			case '?':
				printf("incorrect flag!");
				exit(-1); 
		}
	}
}

void check_argc(int argc){
	if(argc<3){
		printf("too few arguments!");
		exit(-1);
	}
}

void check_flags(uint8_t flag){
	if((flag&CODE)==CODE && (flag&DECODE)==DECODE){
		puts("please enter only one main flag!");
		exit(-1);
	}
}
