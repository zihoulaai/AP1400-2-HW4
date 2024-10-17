#ifndef UNIQUE_PTR
#define UNIQUE_PTR

template<typename T>
class UniquePtr {
public:
    // constructor
    explicit UniquePtr(T *p) : _p(p) {
    }

    // default constructor
    UniquePtr() {
        _p = nullptr;
    }

    // destructor
    ~UniquePtr() {
        delete _p;
        _p = nullptr;
    }

    // Copy constructor , can not be copied
    UniquePtr(const UniquePtr &other) = delete;

    // Operator =, can not be copied
    UniquePtr &operator=(const UniquePtr &other) = delete;

    // get the pointer
    T *get() const {
        return _p;
    }

    // operator *
    T &operator*() const {
        return *_p;
    }

    // Operator->
    T *operator->() const {
        return _p;
    }

    // reset the pointer
    void reset() {
        delete _p;
        _p = nullptr;
    }

    // reset the pointer with a new pointer
    void reset(T *p) {
        delete _p;
        _p = p;
    }

    T *release() {
        T *temp = _p;
        // release the ownership of the pointer
        _p = nullptr;
        // not delete the pointer
        return temp;
    }

    // if the pointer is not null
    explicit operator bool() const {
        return _p != nullptr;
    }

private:
    T *_p; // pointer to the object
};

template<typename T, typename... Args>
UniquePtr<T> make_unique(Args &&... args) {
    // new T(std::forward<Args>(args)...) creates a new object of type T
    // and passes the arguments to the constructor
    return UniquePtr<T>(new T(std::forward<Args>(args)...));
}

#endif //UNIQUE_PTR
