#include <iostream>
#include <string.h>
#include "header.h"
using namespace std;


int main(int argc, char * argv[])
{
    argc = 1;
    /*
    if(argc < 2)
    {
        cout << "usage <SSID1>, <SSID2>, ..." << endl;
        exit(0);
    }
    */
    //int count_ssid = argc;
    int channel_array[argc];
    char hw_addr[argc][len_MacAddr];


    makemac(argc,channel_array, hw_addr);
    //send_beacon();
}
