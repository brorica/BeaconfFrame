#include <tins/tins.h>
#include <cassert>
#include <unistd.h>
#include "header.h"

using namespace Tins;

int send_beacon(int argc, int channel_array[], char(*hw_addr)[hw_addr_len])
{
    int i = 0;
    RadioTap radio[argc];
    Dot11Beacon beacon[argc];
    // Make this a broadcast frame. Note that Dot11::BROADCAST
    // is just the same as "ff:ff:ff:ff:ff:ff"
    for(i=0;i<argc;i++)
    {
        beacon[i].addr1(Dot11::BROADCAST);

        // We'll set the source address to some arbitrary address
        beacon[i].addr2("00:01:02:03:04:05");
        // Set the bssid, to the same one as above

        // Let's add an ssid option
        beacon[i].ssid("restaurants4");
        // Our current channel is 8
        beacon[i].ds_parameter_set(40);
        // This is our list of supported rates:
        beacon[i].supported_rates({ 1.0f, 5.5f, 11.0f });

        // The beacon's ready to be sent!
        radio[i].inner_pdu(beacon[i]);            // render PDU info
    }
    PacketSender sender;
    while(1)
    {
        for(i=0 ; i<argc; i++)
        {
            sender.send(radio[i], "wlan0");    // set ur wireless LAN Card!
            sleep(1);
        }
    }
    return 0;
}
