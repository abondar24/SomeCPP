//
// Created by abondar on 12.05.16.
//

#include "IPPacket.h"
#include "PacketBuffer.h"
#include <iostream>
using namespace std;
int main(){

    PacketBuffer<IPPacket> ipPackets(3);
    for (int i = 1; i < 4; i++) {
        if (!ipPackets.bufferPacket(IPPacket(i))) {
            cout << "Pakcet " << i << " dropped (queue is full)." << endl;
        }
    }

    while (true) {
        try {
            IPPacket packet = ipPackets.getNextPacket();
            cout << "Processing pakcet " << packet.getID() << endl;
        } catch (const out_of_range &) {
            cout << "Queue is empty" << endl;
            break;
        }
    }


    return 0;
}