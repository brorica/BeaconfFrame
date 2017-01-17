#include "header.h"

int main(int argc, char * argv[])
{

    if(argc < 2)
    {
        cout << "usage <interface> <SSID1>, <SSID2>, ..." << endl;
        exit(0);
    }
    char hw_addr[argc][hw_addr_len];
    makemac(argc-2, hw_addr);
    send_beacon(argc-2, hw_addr, argv);

}
