//
// Created by abondar on 12.05.16.
//

#include "CableCompany.h"


void CableCompany::addPackage(const string& packageName, const bitset<numChannels>& channels) {
    packcages.insert({packageName, channels});
}

void CableCompany::removePackage(const string &packageName) {
    packcages.erase(packageName);
}

void CableCompany::newCustomer(const string& name, const string& package) throw(out_of_range){
    auto it = packcages.find(package);
    if(it == packcages.end()){
        throw out_of_range("Invalid package");
    } else{
        customers.insert({name,it->second});
    }
}

void CableCompany::newCustomer(const string& name, const bitset<numChannels>& channels){
    customers.insert({name,channels});
}

void CableCompany::addChannel(const string& name, int channel){
    auto it = customers.find(name);
    if(it != customers.end()){
        it->second.set(channel);
    }
}

void CableCompany::removeChannel(const string& name, int channel){
    auto it = customers.find(name);
    if(it != customers.end()){
        it->second.reset(channel);
    }
}

void CableCompany::addPackageToCutomer(const string& name, const string& package){
    auto itPack = packcages.find(package);
    auto itCust = customers.find(name);
    if(itCust != customers.end()){
        itCust->second |= itPack->second;
    }
}

void CableCompany::deleteCustomer(const string& name){
    customers.erase(name);
}

bitset<numChannels>& CableCompany::getCustomerChannels(const string& name)throw(out_of_range){
    auto it = customers.find(name);
    if(it != customers.end()){
        return it->second;
    }

    throw out_of_range("No customer with that name");
}


