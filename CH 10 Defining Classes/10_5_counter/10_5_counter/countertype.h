#ifndef COUNTERTYPE_H
#define COUNTERTYPE_H

class CounterType
{
public:
    CounterType();
    CounterType(int Counter);
    void incr1();
    void decr1();
    void reset();
    bool negative();
    void print();
private:
    int count;
};

#endif // COUNTERTYPE_H
