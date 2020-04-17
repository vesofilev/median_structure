// #include <cstdlib>
#include "median_struct.hpp"


void MedianStruct::rebalance() {
      if (abs((int) (min_heap.size() - max_heap.size())) < 2)
        return;
      if (min_heap.size() > max_heap.size()) {
        max_heap.push(min_heap.top());
        min_heap.pop();
      } else {
        min_heap.push(max_heap.top());
        max_heap.pop();
      }
    }
    
void MedianStruct::setCurrentMedian() {
      if (min_heap.size() > max_heap.size()) 
        currentMedian = min_heap.top();
      else if (min_heap.size() < max_heap.size()) 
        currentMedian = max_heap.top();
      else
        currentMedian = 0.5 * (min_heap.top() + max_heap.top());
    }

void MedianStruct::insertElement(double element) {
      if (max_heap.empty() && min_heap.empty()) {
          max_heap.push(element);
          currentMedian = element;
          return;
        }
      if (element > currentMedian) 
        min_heap.push(element);
      else if (element < currentMedian) 
        max_heap.push(element);
      else {
        if (min_heap.size() > max_heap.size()) 
          max_heap.push(element);
        else
          min_heap.push(element);
      }
      rebalance();
      setCurrentMedian();
    }

