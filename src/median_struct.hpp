//-----------------------
// \file median_struct.hpp
// \author Veselin Filev
//
// Header file for the meadian data structure
//-----------------------
#include <vector>
#include <queue>


class MedianStruct 
//---------------------------------------------------------
//
// DESCRIPTION:
// This class relies on two prioroty queues 
// to efficiently keep track on the current
// median as elements are being added
//
// INPUTS:
//     insertElement(double) - adding a new element to the data structure
//
// OUTPUTS:
//     getMedian() - returning the current median
//
// Author : Veselin Filev
//---------------------------------------------------------
{
private:
    std::priority_queue<double, std::vector<double>, std::greater<double> > min_heap;
    std::priority_queue<double, std::vector<double>, std::less<double> > max_heap;
    double currentMedian;

    void rebalance();

    void setCurrentMedian();

public:
    MedianStruct (){ 
    }
    void insertElement(double element);
    
    double getMedian() {  return currentMedian; }

};
