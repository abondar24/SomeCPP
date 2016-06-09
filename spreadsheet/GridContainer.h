//
// Created by abondar on 09.06.16.
//

#ifndef SOMECPP_GRIDCONTAINER_H
#define SOMECPP_GRIDCONTAINER_H

#include <array>

using namespace std;

template <typename T,typename Container>
class GridContainer {
public:
    GridContainer(size_t inWidth=defWidth,size_t inHeight = defHeight);
    GridContainer(const GridContainer<T,Container>& src);
    virtual ~GridContainer();
    GridContainer<T,Container>& operator=(const GridContainer<T,Container>& rhs);
    void setElementAt(int x, int y, const T& elem);
    const T& getElementAt(int x, int y) const;
    size_t getHeight() const { return height;}
    size_t getWidth() const { return width;}

    static  const size_t  defWidth =10;
    static const size_t defHeight =10;

protected:
    void copyFrom(const GridContainer<T,Container>& src);


    Container* cells;
    size_t width;
    size_t height;

};


#endif //SOMECPP_GRIDCONTAINER_H
