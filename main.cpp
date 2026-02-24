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
bool hasNext(VecIt<T> it)
{
  return it.i != it.s;
}

template< class T >
VecIt<T> next(VecIt<T> it)
{
  return {it.data, it.i + 1, it.s};
}


int main()
{
  std::cout << "Hello, World!\n";
  return 0;
}