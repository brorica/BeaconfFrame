#include <tins/tins.h>
#include <cassert>
#include <unistd.h>
#include "header.h"

using namespace Tins;

int send_beacon(int argc, char(*hw_addr)[hw_addr_len], char * argv[])
{
    int i = 0;
    int channel_array[argc];

    RadioTap radio[argc];
    Dot11Beacon beacon[argc];

    srand(time(NULL));

    // associate channel
    for(i=0; i<argc; i++)
        channel_array[i] = rand()%8;

    // Let's add an ssid option
    for(i=1; i <=argc; i++)
        beacon[i-1].ssid(argv[i]);

    // Make this a broadcast frame. Note that Dot11::BROADCAST
    // is just the same as "ff:ff:ff:ff:ff:ff"
    for(i=0; i< argc; i++)
    {
        beacon[i].addr1(Dot11::BROADCAST);

        // We'll set the source address to some arbitrary address
        beacon[i].addr2(hw_addr[i]);
        // Set the bssid, to the same one as above

        // Our current channel is 8
        beacon[i].ds_parameter_set(channel_array[i]);
        // This is our list of supported rates:
        beacon[i].supported_rates({ 1.0f, 5.5f, 11.0f });

        // The beacon's ready to be sent!
        radio[i].inner_pdu(beacon[i]);            // render PDU info
    }




    PacketSender sender;
    while(1)
    {
        for(i=0; i<argc; i++)
        {
            sender.send(radio[i], "wlan1");    // set ur wireless LAN Card!
            usleep(10);
        }
    }
    return 0;
}
