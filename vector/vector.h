#ifndef JO_VECTOR_H
#define JO_VECTOR_H

namespace JO {
    template<typename T>
    class Vector {
    protected:
        size_t mCap;
        size_t mSize;
        T* mData;

        void rangeCheck(size_t idx) {
            if (idx < 0 or idx >= mSize) throw std::range_error("Index out of range");
        }

        void ensureCapacity(size_t desired_size) {
            if (mCap < desired_size) {
                int new_mCap = desired_size > mCap*2 ? desired_size : mCap*2;
                expand(new_mCap);
            }
            return;
        }

        void expand(size_t new_mCap) {
            T* new_mData = new T[new_mCap];
            for (size_t i = 0; i < mSize; i++) new_mData[i] = mData[i];
            delete [] mData;
            mData = new_mData;
            mCap = new_mCap;
        }

    public:
        typedef *T iterator;

        /**
         * @brief Default constructor of a new Vector object
         * 
         */
        Vector() : mCap(1), mSize(0), mData(new T[1]) {}

        /**
         * @brief Construct a new Vector object with only size specified
         * Delegate constructor to another constructor
         * @param sz size of the vector
         */
        Vector(size_t sz) : Vector(sz, T()) {}

        Vector(size_t sz, T init_value) {
            mCap = sz;
            mSize = sz;
            mData = new T[mCap];
            for (size_t i = 0; i < mCap; i++) mData[i] = init_value;
        }

        void push_back(T const &x) {
            ensureCapacity(mSize + 1);
            mData[size()] = x;
            mSize += 1;
        }

        void pop_back() {
            if (mSize <= 0) throw std::runtime_error("Cannot pop_back because vector is empty");
            mSize -= 1;
        }

        Vector& operator=(Vector<T> const &other) {
            T* new_mData = new T[other.mCap];
            for (size_t i = 0; i < other.mSize; i++) new_mData[i] = other.mData[i];
            this->mCap = other.mCap;
            this->mSize = other.mSize;
            this->mData = new_mData;
            return *this;
        }

        void clear() {
            mSize = 0;
        }

        iterator begin() const {
            return mData;
        }

        iterator end() const {
            return mData + mSize;
        }

        T& operator[](size_t idx) const {
            return mData[idx];
        }

        T& at(size_t idx) const {
            rangeCheck(idx);
            return mData[idx];
        }

        size_t empty() const {
            return (mSize == 0);
        }
        size_t size() const {
            return mSize;
        }

        ~Vector() {
            delete [] mData;
        }
    };
}

#endif