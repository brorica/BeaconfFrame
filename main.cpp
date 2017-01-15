#include <tins/tins.h>
#include <cassert>
#include <unistd.h>
#include <iostream>
#include <string>

using namespace Tins;

using namespace std;
int main() {
    RadioTap radio;
    Dot11Beacon beacon;
    // Make this a broadcast frame. Note that Dot11::BROADCAST
    // is just the same as "ff:ff:ff:ff:ff:ff"
    beacon.addr1(Dot11::BROADCAST);

    // We'll set the source address to some arbitrary address
    beacon.addr2("01:01:02:03:04:05");
    // Set the bssid, to the same one as above

    // Let's add an ssid option
    beacon.ssid("restaurants");
    // Our current channel is 8
    beacon.ds_parameter_set(1);
    // This is our list of supported rates:
    beacon.supported_rates({ 1.0f, 5.5f, 11.0f });

    // The beacon's ready to be sent!
    radio.inner_pdu(beacon);
    PacketSender sender;
    while(1)
    {
        sender.send(radio, "wlan1");
        sleep(1);
    }

}
