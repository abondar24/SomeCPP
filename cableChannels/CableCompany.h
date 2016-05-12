//
// Created by abondar on 12.05.16.
//

#ifndef SOMECPP_CABLECOMPANY_H
#define SOMECPP_CABLECOMPANY_H

#include <map>
#include <bitset>

using std::map;
using std::bitset;
using std::string;
using std::out_of_range;
const int numChannels = 3;
class CableCompany {
public:
    CableCompany(){};
    void addPackage(const string& packageName, const bitset<numChannels>& channels);
    void removePackage(const string& packageName);
    void newCustomer(const string& name, const string& package) throw(out_of_range);
    void newCustomer(const string& name, const bitset<numChannels>& channels);
    void addChannel(const string& name,int channel);
    void removeChannel(const string& name,int channel);
    void addPackageToCutomer(const string& name,const string& package);
    void deleteCustomer(const string& name);
    bitset<numChannels>& getCustomerChannels(const string& name)throw (out_of_range);

protected:
    typedef map<string,bitset<numChannels>> MapType;
    MapType packcages,customers;




};


#endif //SOMECPP_CABLECOMPANY_H
