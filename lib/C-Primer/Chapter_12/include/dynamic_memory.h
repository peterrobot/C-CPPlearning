#pragma once
#include <string>
#include <vector>
#include <memory>

class StrBlobPtr;
class ConstStrBlobPtr;

class StrBlob
{
public:
    friend class StrBlobPtr;
    friend class ConstStrBlobPtr;
    
    typedef std::vector<std::string>::size_type size_type; 
    StrBlob();
    StrBlob(std::initializer_list<std::string> il);
    size_type size() const { return data->size(); }
    bool empty() const { return data->empty(); }

    void push_back(const std::string &t) { data->push_back(t); }
    void pop_back();

    std::string& front();
    std::string& back();
    const std::string& front() const;
    const std::string& back() const;

    StrBlobPtr begin();
    StrBlobPtr end();
    const ConstStrBlobPtr cbegin() const;
    const ConstStrBlobPtr cend() const;

private:
    std::shared_ptr<std::vector<std::string>> data;
    void check(size_type i, const std::string &msg) const;
};

class StrBlobPtr
{
public:
    StrBlobPtr() : curr(0) {}
    StrBlobPtr(StrBlob &a, size_t sz = 0) : wptr(a.data), curr(sz) {}
    std::string& deref() const;
    StrBlobPtr& incr();
private:
    std::shared_ptr<std::vector<std::string>> check(std::size_t, const std::string&) const;
    std::weak_ptr<std::vector<std::string>> wptr;
    std::size_t curr;
};

class ConstStrBlobPtr
{
public:
    ConstStrBlobPtr(const StrBlob& ref, std::size_t i) : wptr(ref.data), curr(i) {}
    const std::string& deref() const;
    ConstStrBlobPtr& incr();

    const std::string& operator*() const;
    ConstStrBlobPtr& operator++();
    bool operator!=(ConstStrBlobPtr&) const;
private:
    const std::shared_ptr<std::vector<std::string>> check(std::size_t, const std::string&) const;
    const std::weak_ptr<std::vector<std::string>> wptr;
    size_t curr;
};

void dynamic_memory_test();