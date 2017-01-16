#ifndef HEADER_H
#define HEADER_H

#endif // HEADER_H

#define hw_addr_len 18

#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

int send_beacon(int argc, char(*hw_addr)[hw_addr_len], char * argv[]);
int makemac(int count_ssid, char(*hw_addr)[hw_addr_len]);

