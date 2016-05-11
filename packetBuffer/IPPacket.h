//
// Created by abondar on 11.05.16.
//

#ifndef SOMECPP_IPPACKET_H
#define SOMECPP_IPPACKET_H

class IPPacket{
public:
    IPPacket(int id): iD(id){}
    int getID() const { return iD;}

protected:
    int iD;
};
#endif //SOMECPP_IPPACKET_H
