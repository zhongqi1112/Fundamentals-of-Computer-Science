#ifndef COUNTER_H
#define COUNTER_H

class Counter
{
public:
    Counter();
    Counter(int MAX);
    void reset();
    void incr1();
    void incr10();
    void incr100();
    void incr1000();
    bool overflow();
    void Print();
private:
    int count;
    int Max_count;
};

#endif // COUNTER_H
