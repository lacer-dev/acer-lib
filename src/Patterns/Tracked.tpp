#include "Tracked.hpp"
#include <utility>

template<typename T>
const T& Tracked<T>::last() const {
    return last_value;    
}

template<typename T>
Tracked<T>::Tracked() : current_value() {
       
}

template<typename T>
Tracked<T>::Tracked(const T& value) : current_value(value) {
    
}

template<typename T>
Tracked<T>::Tracked(const T&& value) : current_value(std::move(value)) {
    
}

template<typename T>
Tracked<T>& Tracked<T>::operator=(const T& value) {
    last_value = std::move(current_value);
    current_value = value;
}

template<typename T>
Tracked<T>& Tracked<T>::operator=(const T&& value) {
    last_value = std::move(current_value);
    current_value = std::move(value);
    return *this;
}

template<typename T>
Tracked<T>::operator T() const {
    return current_value;    
}
