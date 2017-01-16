#ifndef HEADER_H
#define HEADER_H

#endif // HEADER_H

#define hw_addr_len 18

#include <string.h>

int send_beacon(int argc, int channel_array[], char(*hw_addr)[hw_addr_len]);
int makemac(int count_ssid,int channel_array[], char(*hw_addr)[hw_addr_len]);

