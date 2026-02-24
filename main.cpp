#include <iostream>

template< class T >
struct Vec {
  T* data;
  size_t s;
};
template< class T >
struct VecIt {
  T* data;
  size_t i, s;
};

template< class T >
VecIt< T > begin(Vec<T> d)
{
  return {d.data, 0, d.s};
}

template< class T >
VecIt< T > rbegin(Vec<T> d)
{
  return {d.data, d.s, d.s};
}

template< class T >
bool hasNext(VecIt<T> it)
{
  return it.i != it.s;
}

template< class T >
bool hasPrev(VecIt<T> it)
{
  return 0 != it.i;
}

template< class T >
VecIt<T> next(VecIt<T> it)
{
  return {it.data, it.i + 1, it.s};
}

template< class T >
VecIt<T> prev(VecIt<T> it)
{
  return {it.data, it.i - 1, it.s};
}

template< class T >
T& value(VecIt<T> it)
{
  return it.data[it.i - 1];
}


int main()
{
  Vec<int> a{ new int[10], 10};
  for (size_t i = 0; i < 10; i++) {
    a.data[i] = i;
  }
  VecIt<int> h = rbegin(a);
  for (;hasPrev(h); h = prev(h)) {
    std::cout << value(h) << '\n';
  }

  delete[] a.data;
  return 0;
}

