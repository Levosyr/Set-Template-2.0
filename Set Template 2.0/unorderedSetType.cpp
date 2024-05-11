#ifndef H_unorderedSetType
#define H_unorderedSetType

#include "unorderedArrayListType.h"

template <class elemType>
class unorderedSetType : public unorderedArrayListType<elemType> {
public:
    void insertEnd(const elemType& insertItem);
    void insertAt(int location, const elemType& insertItem);
    void replaceAt(int location, const elemType& repItem);
    unorderedSetType<elemType> operator+(const unorderedSetType<elemType>& otherSet) const;
    unorderedSetType<elemType> operator-(const unorderedSetType<elemType>& otherSet) const;

    unorderedSetType(int size = 100);
};

template <class elemType>
void unorderedSetType<elemType>::insertEnd(const elemType& insertItem) {
    int loc = this->seqSearch(insertItem);
    if (loc == -1)
        unorderedArrayListType<elemType>::insertEnd(insertItem);
}

template <class elemType>
void unorderedSetType<elemType>::insertAt(int location, const elemType& insertItem) {
    int loc = this->seqSearch(insertItem);
    if (loc == -1)
        unorderedArrayListType<elemType>::insertAt(location, insertItem);
}

template <class elemType>
void unorderedSetType<elemType>::replaceAt(int location, const elemType& repItem) {
    int loc = this->seqSearch(repItem);
    if (loc == -1)
        unorderedArrayListType<elemType>::replaceAt(location, repItem);
}

template <class elemType>
unorderedSetType<elemType> unorderedSetType<elemType>::operator+(const unorderedSetType<elemType>& otherSet) const {
    unorderedSetType<elemType> unionSet(this->maxListSize() + otherSet.maxListSize());
    for (int i = 0; i < this->listSize(); ++i)
        unionSet.insertEnd(this->list[i]);
    for (int i = 0; i < otherSet.listSize(); ++i)
        unionSet.insertEnd(otherSet.list[i]);
    return unionSet;
}

template <class elemType>
unorderedSetType<elemType> unorderedSetType<elemType>::operator-(const unorderedSetType<elemType>& otherSet) const {
    unorderedSetType<elemType> intersectSet(this->maxListSize());
    for (int i = 0; i < this->listSize(); ++i)
        if (otherSet.seqSearch(this->list[i]) != -1)
            intersectSet.insertEnd(this->list[i]);
    return intersectSet;
}

template <class elemType>
unorderedSetType<elemType>::unorderedSetType(int size) : unorderedArrayListType<elemType>(size) {}

#endif