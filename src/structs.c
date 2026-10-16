#pragma once
#include <stdint.h>
typedef struct NODE{
	uint16_t symbol; //по сути, байт. от 0-255 - реальный байты, 256 - пустышка/конец файла
	uint16_t frequency; 
	struct NODE *left;
	struct NODE *right;
} NODE;

//фукции для работы с бинарной кучей

