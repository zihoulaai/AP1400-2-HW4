#ifndef SHARED_PTR
#define SHARED_PTR

template<typename T>
class SharedPtr {
public:
    // default constructor
    SharedPtr() {
        _p = nullptr;
        _ref_count = new size_t(0);
    }

    // constructor
    explicit SharedPtr(T *p) {
        _ref_count = new size_t(1);
        _p = p;
    }

    // copy constructor
    SharedPtr(const SharedPtr &other) {
        // copy the reference count
        _ref_count = other._ref_count;
        // copy the pointer
        _p = other._p;
        // increment the reference count
        ++(*_ref_count);
    }

    // destructor
    ~SharedPtr() {
        // decrement the reference count
        --(*_ref_count);
        // if the reference count is 0, delete the pointer
        if (*_ref_count == 0) {
            delete _p;
            _p = nullptr;
        }
    }

    // get reference count
    [[nodiscard]] size_t use_count() const {
        return *_ref_count;
    };

    T *get() {
        return _p;
    }


    // operator =
    SharedPtr &operator=(const SharedPtr &other) {
        if (this == &other) {
            return *this;
        }

        // decrement the current reference count
        if (_p) {
            --(*_ref_count);
            if (*_ref_count == 0) {
                delete _p;
                delete _ref_count;
            }
        }

        // copy the pointer and reference count and increment the reference count
        _ref_count = other._ref_count;
        _p = other._p;
        ++(*_ref_count);
        return *this;
    }

    // operator *
    T &operator*() {
        return *_p;
    }

    T *operator->() {
        return _p;
    }

    void reset() {
        _ref_count = new size_t(0);
        delete _p;
        _p = nullptr;
    }

    void reset(T *p) {
        _ref_count = new size_t(1);
        delete _p;
        _p = p;
    }

    // operator bool()
    explicit operator bool() const {
        return _p != nullptr;
    }

private:
    // pointer to the object
    T *_p = nullptr;
    // pointer to the reference count
    size_t *_ref_count = nullptr;
};

// make_shared
template<typename T, typename... Args>
SharedPtr<T> make_shared(Args &&... args) {
    // new T(std::forward<Args>(args)...) creates a new object of type T
    // and passes the arguments to the constructor
    return SharedPtr<T>(new T(std::forward<Args>(args)...));
}

#endif //SHARED_PTR
