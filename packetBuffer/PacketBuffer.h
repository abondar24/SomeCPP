//
// Created by abondar on 11.05.16.
//

#ifndef SOMECPP_PACKETBUFFER_H
#define SOMECPP_PACKETBUFFER_H

#include <cstdlib>
#include <stdexcept>
#include <queue>

template<typename T>
class PacketBuffer {
public:
    //if max =0, size is unlimited
    PacketBuffer(size_t maxSize = 0);

    bool bufferPacket(const T &packet);

    T getNextPacket() throw(std::out_of_range);

protected:
    std::queue<T> packets;
    int maxSize;
};


template<typename T>
PacketBuffer<T>::PacketBuffer(size_t maxSize) : maxSize(maxSize) { }

template<typename T>
bool PacketBuffer<T>::bufferPacket(const T &packet) {
    if (maxSize > 0 && packets.size() == maxSize) {
        return false;
    }
    packets.push(packet);
    return true;
}

template<typename T>
T PacketBuffer<T>::getNextPacket() throw(std::out_of_range) {
    if (packets.empty()){
        throw std::out_of_range("Buffer is empty");
    }

    T temp = packets.front();
    packets.pop();

    return temp;
}


#endif //SOMECPP_PACKETBUFFER_H
