#pragma once
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "constants.h"
#include <getopt.h>
#include <stdint.h>
#include <string.h>

void take_flags(int argc, char *argv[], uint8_t *flag, char name[][2]);
void check_flags(uint8_t flag);
void check_argc(int argc);