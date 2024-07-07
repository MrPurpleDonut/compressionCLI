//
// Created by Aidan Thomas on 7/6/24.
//

#ifndef HUFFENCODING_MINHEAP_H
#define HUFFENCODING_MINHEAP_H

#include <vector>
template <typename T>
class MinHeap {

private:
    int size;
    std::vector<T*> internalArray;

    void shift() {
        int currentIndex = 0;
        T* current = internalArray[0];
        while(true){
            if(2*currentIndex >= size-1){ return;}

            if(2*currentIndex + 1 == size-1){
                if(*current > *internalArray[size-1]){
                    internalArray[currentIndex] = internalArray[size-1];
                    internalArray[size-1] = current;
                }
                return;
            }

            T* left = internalArray[2*currentIndex+1];
            T* right = internalArray[2*currentIndex+2];
            if(*current <= *left && *current <= *right){
                return;
            }
            if(*left <= *right){
                internalArray[currentIndex] = left;
                internalArray[2*currentIndex+1] = current;
                currentIndex = 2*currentIndex+1;
            }else{
                internalArray[currentIndex] = right;
                internalArray[2*currentIndex+2] = current;
                currentIndex = 2*currentIndex+2;
            }
        }
    }
    void percolate(){
        int currentIndex = size-1;
        T* current = internalArray[currentIndex];
        while (true){
            if(currentIndex == 0){ return;}
            int parentIndex = (currentIndex-1)/2;
            if(*internalArray[parentIndex] <= *current){
                return;
            }
            internalArray[currentIndex] = internalArray[parentIndex];
            internalArray[parentIndex] = current;
            currentIndex = parentIndex;
        }
    }
public:
    MinHeap(){
        size = 0;
    }
     int getSize(){
        return size;
    }
    T* pop(){
        T* returnVal = internalArray[0];
        internalArray[0] = internalArray[size-1];
        size--;
        shift();
        return returnVal;
    }

    void push(T* item){
        if(internalArray.size() >  size){
            internalArray[size] = item;
        }else{
            internalArray.push_back(item);
        }
        size++;
        percolate();
    }
};


#endif //HUFFENCODING_MINHEAP_H
