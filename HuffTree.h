//
// Created by Aidan Thomas on 7/6/24.
//

#ifndef HUFFENCODING_HUFFTREE_H
#define HUFFENCODING_HUFFTREE_H
#include "HuffNode.h"

template <typename T>
class HuffTree{
public:
    BaseNode* root;
    HuffTree(T element, int weight): root(){
        this->root = new LeafNode<T>(element, weight);
    }
    HuffTree(BaseNode* left, BaseNode* right): root() {
        this->root = new InternalNode(left, right, left->getWeight()+right->getWeight());
    }
    [[nodiscard]] int weight() const {
        return this->root->getWeight();
    }

};

template <typename T>
bool operator==(HuffTree<T>  one, HuffTree<T>  two){return one.weight() == two.weight();}
template <typename T>
bool operator>=(HuffTree<T> one, HuffTree<T>  two){return one.weight() >= two.weight();}
template <typename T>
bool operator<=(HuffTree<T> one, HuffTree<T> two){return one.weight() <= two.weight();}
template <typename T>
bool operator!=(HuffTree<T> one, HuffTree<T> two){return one.weight() != two.weight();}
template <typename T>
bool operator<(HuffTree<T>  one, HuffTree<T> two){return one.weight() < two.weight();}
template <typename T>
bool operator>(HuffTree<T>  one, HuffTree<T> two){return one.weight() > two.weight();}


#endif //HUFFENCODING_HUFFTREE_H
