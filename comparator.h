#ifndef COMPARATOR_H
#define COMPARATOR_H

class Comparator
{
public:
public:
    virtual bool equal(int itemA, int itemB) = 0;
    virtual bool lessThen(int itemA, int itemB) = 0;
    virtual bool moreThen(int itemA, int itemB) = 0;
    virtual int getMoreThenNodes(int itemA,int itemB) = 0;
};

#endif // COMPARATOR_H


#ifndef VALIDATOR_H
#define VALIDATOR_H
class Validator:public Comparator{
public:
    Validator();
    bool equal(int itemA, int itemB);
    bool lessThen(int itemA, int itemB);
    bool moreThen(int itemA, int itemB);
    int getMoreThenNodes(int itemA,int itemB);
};

#endif // VALIDATOR_H
