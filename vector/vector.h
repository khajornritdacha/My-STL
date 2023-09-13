#ifndef JO_VECTOR_H
#define JO_VECTOR_H

namespace JO {
    template<typename T>
    class Vector {
    protected:
        size_t mCap;
        size_t mSize;
        T* mData;

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
        /**
         * @brief Default constructor of a new Vector object
         * 
         */
        Vector() : mCap(1), mSize(0), mData(new T[1]) {}

        void push_back(T const &x) {
            ensureCapacity(mSize + 1);
            mData[size()] = x;
            mSize += 1;
        }

        T& operator[](size_t idx) {
            return mData[idx];
        }

        size_t empty() {
            return (mSize == 0);
        }
        size_t size() {
            return mSize;
        }

        ~Vector() {
            delete [] mData;
        }
    };
}

#endif