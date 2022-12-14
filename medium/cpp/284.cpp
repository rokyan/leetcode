// https://leetcode.com/problems/peeking-iterator/

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

class PeekingIterator : public Iterator
{
public:
	PeekingIterator(const std::vector<int>& nums)
        : Iterator(nums)
        , next_val(Iterator::next())
        , has_next(true)
    {
	    // Initialize any member here.
	    // **DO NOT** save a copy of nums and manipulate it directly.
	    // You should only use the Iterator interface methods.
        
	}
	
    // Returns the next element in the iteration without advancing the iterator.
	int peek()
    {
        return next_val;
	}
	
	// hasNext() and next() should behave the same as in the Iterator interface.
	// Override them if needed.
	int next()
    {
        int ret = next_val;
        
        has_next = Iterator::hasNext();
        
        next_val = has_next ? Iterator::next() : 0;
        
        return ret;
	}
	
	bool hasNext() const
    {
        return has_next;
	}
    
private:
    int next_val;
    bool has_next;
};