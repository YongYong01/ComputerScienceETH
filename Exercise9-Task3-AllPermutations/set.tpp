template <typename T>
Set<T>::Set(const Set& other) {
    for (auto e : other.m_elements) {
      insert(e);
    }
  }
  
template <typename T>
Set<T>::Set(){};
template <typename T>
Set<T>::Set(const std::set<T>& elements) : m_elements(elements) {}
template <typename T>
Set<T>::Set(T element) { m_elements.insert(element); }

template <typename T>
unsigned int Set<T>::size() const { return m_elements.size(); }
template <typename T>
void Set<T>::insert(T element) { m_elements.insert(element); }
template <typename T>
void Set<T>::remove(T element) { m_elements.erase(element); }
template <typename T>
bool Set<T>::contains(T element) const {
  for (auto e : m_elements) {
    if (e == element) {
      return true;
    }
  }
  return false;
}

template <typename T>
bool Set<T>::is_subset(const Set& other) const {
  for (auto e : m_elements) {
    if (!other.contains(e)) {
      return false;
    }
  }
  return true;
}
template <typename T>
bool Set<T>::is_superset(const Set& other) const { return other.is_subset(*this); }
template <typename T>
bool Set<T>::is_equal(const Set& other) const {
  return is_subset(other) && is_superset(other);
}
template <typename T>
bool Set<T>::is_unequal(const Set& other) const { return !is_equal(other); }
template <typename T>
bool Set<T>::is_strict_subset(const Set& other) const {
  return is_subset(other) && !is_equal(other);
}
template <typename T>
bool Set<T>::is_strict_superset(const Set& other) const {
  return other.is_strict_superset(*this);
}

template <typename T>
Set<T>& Set<T>::operator=(const Set<T>& other) {
  m_elements.clear();
  for (auto e : other.m_elements) {
    insert(e);
  }
  return *this;
}

template <typename T>
bool Set<T>::operator<(const Set<T>& other) const {
  // attempt to order them by subset
  if (is_strict_subset(other)) {
    return true;
  }
  if (other.is_strict_subset(*this)) {
    return false;
  }

  // attempt to order them by size
  unsigned int size = this->size();
  unsigned int other_size = other.size();
  if (size < other_size) {
    return true;
  }
  if (other_size < size) {
    return false;
  }

  // attempt to order them lexicographically
  for (unsigned int i = 0; i < size; ++i) {
    auto e = (*this).at(i);
    auto other_e = other.at(i);
    if (e < other_e) {
      return true;
    }
    if (other_e < e) {
      return false;
    }
  }

  // the sets must be equal
  return false;
}
template <typename T>
bool Set<T>::operator>(const Set<T>& other) const { return other < (*this); }
template <typename T>
bool Set<T>::operator==(const Set<T>& other) const { return is_equal(other); }

template <typename T>
const T& Set<T>::at(unsigned int i) const {
  assert(i >= 0 && i < size());
  return *next(m_elements.begin(), i);
}
template <typename T>
Set<T> Set<T>::operator+(const Set<T>& other) const {
  Set<T> result;
  for (auto e : m_elements) {
    result.insert(e);
  }
  for (auto e : other.m_elements) {
    result.insert(e);
  }
  return result;
}
template <typename T>
Set<T> Set<T>::operator-(const Set<T>& other) const {
  Set<T> result;
  for (auto e : m_elements) {
    result.insert(e);
  }
  for (auto e : other.m_elements) {
    result.remove(e);
  }
  return result;
}

template <typename T>
Set<T> Set<T>::intersection(const Set<T>& other) const {
  Set<T> result;
  for (auto e : m_elements) {
    if (other.contains(e)) {
      result.insert(e);
    }
  }
  return result;
}

template <typename T>
const std::set<T>& Set<T>::elements() const { return m_elements; }

template <typename T>
Set<T> set_union(const std::vector<Set<T>>& sets) {
  Set<T> result;
  for (auto& set : sets) {
    for (auto e : set.elements()) {
      result.insert(e);
    }
  }
  return result;
}

template <typename T>
std::ostream& operator<<(std::ostream& os, const Set<T>& set) {
  os << "{";
  bool first = true;
  for (auto e : set.elements()) {
    if (!first) {
      os << ",";
    }
    os << e;
    first = false;
  }
  os << "}";
  return os;
}

template <typename T>
std::istream& operator>>(std::istream& is, Set<T>& set) {
  unsigned int n;
  is >> n;

  for (; n > 0; --n) {
    T element;
    is >> element;
    set.insert(element);
  }

  return is;
}