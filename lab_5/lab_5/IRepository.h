#pragma once
#include <string>
#include <vector>
template <typename T>
__interface IRepository 
{
public:
    virtual std::vector<T> getAll() const;
    virtual void add(const T& user) = 0;
    virtual void Remove(const T& user) = 0;
    virtual void update(const T& user) = 0;
};

