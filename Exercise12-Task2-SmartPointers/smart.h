#pragma once

// Forward declarations.
struct tracked;

class Smart {
public:
  // POST: create a smart pointer pointing to nothing (null smart pointer)
  Smart();
  // POST: create a smart pointer pointing to the same location as src
  Smart(const Smart& src);
  // POST: assign a smart pointer to src
  Smart& operator=(const Smart& src);
  // POST: deallocate pointer object if it is the last smart pointer object
  //       pointing to it.
  ~Smart();
  // PRE: if v != nullptr, v point to an object allocated by new.
  //      Deallocation responsibility of v has not been given to anyone yet.
  // POST: create a smart pointer pointing to v.
  //       Give deallocation responsibility to the
  //       Smart pointer class.
  Smart(tracked* v);
  // PRE: smart pointer is not null.
  // POST: return reference to stored value
  tracked& operator*();
  // PRE: smart pointer is not null
  // POST: return reference to stored value
  const tracked& operator*() const;
  // (Technical: needed so that x->... work properly)
  tracked* operator->();
  const tracked* operator->() const;
  // POST: return whether pointers point to the same location.
  bool operator==(const Smart& cmp) const;
  // POST: negation of (==).
  bool operator!=(const Smart& cmp) const;
  //POST: returns the number of objects of class Smart that share the same
  //      ptr. Returns 0 if count == nullptr
  unsigned int get_count() const;
private:
  unsigned int* count; // INV: count != nullptr -> *count is the number
                       //   of object of class Smart which share the same
                       //   value for field ptr.
  tracked* ptr;        // INV: ptr == nullptr if and only if count == nullptr
};

void your_own_tests();
