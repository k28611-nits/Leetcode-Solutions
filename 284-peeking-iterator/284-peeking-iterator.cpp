/*
 * Below is the interface for Iterator, which is already defined for you.
 * **DO NOT** modify the interface for Iterator.
 *
 *  class Iterator {
 *		struct Data;
 * 		Data* data;
 *  public:
 *		Iterator(const vector<int>& nums);
 * 		Iterator(const Iterator& iter);
 *
 * 		// Returns the next element in the iteration.
 *		int next();
 *
 *		// Returns true if the iteration has more elements.
 *		bool hasNext() const;
 *	};
 */

class PeekingIterator : public Iterator {
private:
    // support variables
    int _nextVal;
    bool _hasNext;
public:
	PeekingIterator(const vector<int>& nums) : Iterator(nums) {
        // local copies initialised
	    this->_hasNext = Iterator::hasNext();
	    if (this->_hasNext) this->_nextVal = Iterator::next();
	}
	
    // Returns the next element in the iteration without advancing the iterator.
	int peek() {
        return this->_nextVal;
	}
    
	int next() {
        // storing the current value of nextVal
        int tmp = this->_nextVal;
        // updating hasNext
        this->_hasNext = Iterator::hasNext();
        // updating nextVal, but only if we can
        if (this->_hasNext) {
            this->_nextVal = Iterator::next();
        }
	    return tmp;
	}
	
	bool hasNext() const {
	    return this->_hasNext;
	}
};