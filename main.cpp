#include <iostream>
#include "MinHeap.h"
#include "HuffTree.h"
#include <map>
#include <cassert>
#include <string>

template <typename T>
HuffTree<T>* getEncodingTreeFromCounts (std::map<T, int>& countMap){
    assert(!countMap.empty());
    MinHeap<HuffTree<T>> treeHeap;
    for(const auto &keyValue: countMap){
        T key = keyValue.first;
        int val = keyValue.second;
        auto* newTree = new HuffTree<T>(key, val);
        treeHeap.push(newTree);
    }

    while(treeHeap.getSize() >= 2){
        auto one = treeHeap.pop();
        auto two = treeHeap.pop();
        treeHeap.push(new HuffTree<T>(one->root, two->root));
    }
    return treeHeap.pop();
}

template<typename T>
void convertEncodingTreeToMap(BaseNode* node, std::map<T,std::string>& encodings, std::string rep){
    if(node->isLeaf()){
        auto leafNode = dynamic_cast<LeafNode<T>*>(node);
        encodings[leafNode->element] = rep;
        return;
    }
    auto convertedNode = dynamic_cast<InternalNode*>(node);
    convertEncodingTreeToMap(convertedNode->right, encodings, rep.substr(0)+="1");
    convertEncodingTreeToMap(convertedNode->left, encodings, rep.substr(0)+="0");

}


int main() {
    std::map<char, int> mp;
    mp['a'] = 4;
    mp['b'] = 8;
    mp['c'] = 1;
    mp['d'] = 1;

    auto encodingTree = getEncodingTreeFromCounts(mp);

   std::map<char, std::string> encodings;
    convertEncodingTreeToMap(encodingTree->root, encodings, (std::string) "");

    for(const auto &keyValue: encodings){
        auto key = keyValue.first;
        auto val = keyValue.second;
        std::cout << key << ": " << val << '\n';
    }
    return 0;
}