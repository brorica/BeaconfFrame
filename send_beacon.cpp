#include <tins/tins.h>
#include <cassert>
#include <unistd.h>
#include "header.h"

using namespace Tins;

int send_beacon()
{
    RadioTap radio;
    Dot11Beacon beacon;
    // Make this a broadcast frame. Note that Dot11::BROADCAST
    // is just the same as "ff:ff:ff:ff:ff:ff"
    beacon.addr1(Dot11::BROADCAST);

    // We'll set the source address to some arbitrary address
    beacon.addr2("00:01:02:03:04:05");
    // Set the bssid, to the same one as above

    // Let's add an ssid option
    beacon.ssid("restaurants4");
    // Our current channel is 8
    beacon.ds_parameter_set(40);
    // This is our list of supported rates:
    beacon.supported_rates({ 1.0f, 5.5f, 11.0f });

    // The beacon's ready to be sent!
    radio.inner_pdu(beacon);            // render PDU info
    PacketSender sender;
    while(1)
    {
        sender.send(radio, "wlan0");    // set ur wireless LAN Card!
        sleep(1);
    }
    return 0;
}
