//
// Created by Aidan Thomas on 7/6/24.
//

#ifndef HUFFENCODING_HUFFNODE_H
#define HUFFENCODING_HUFFNODE_H


class BaseNode{
public:
    virtual bool isLeaf() = 0;
    virtual int getWeight() = 0;
};

template <typename T>
class LeafNode: public BaseNode {
private:
    int weight;
public:
    T element;
    LeafNode(T element, int weight): weight(weight){
        this->element = element;
    }
    bool isLeaf() override {return true;}
    int getWeight() override{ return weight;}
};

class InternalNode: public BaseNode {
private:
    int weight;
public:
    BaseNode* left;
    BaseNode* right;
    InternalNode(BaseNode* left, BaseNode* right, int weight): left(left), right(right), weight(weight){
    }
    bool isLeaf() override {return false;}
    int getWeight() override{ return weight;}
};

#endif //HUFFENCODING_HUFFNODE_H
