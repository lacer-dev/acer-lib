#pragma once

template<typename T>
class Tracked {
public: 
    const T& last() const;
    Tracked();
    Tracked(const T&);
    Tracked(const T&&);
    Tracked& operator=(const T&);
    Tracked& operator=(const T&&);
    operator T() const;
private:
    T current_value;
    T last_value;
};

#include "Tracked.tpp"
