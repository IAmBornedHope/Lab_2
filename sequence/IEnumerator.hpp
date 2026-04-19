#pragma once

template<class T>
class IEnumerator {
public:
    virtual ~IEnumerator() = default;
    virtual const T& get_elem() const = 0;
    virtual void next_elem() = 0;
    virtual bool is_end() const = 0;
};