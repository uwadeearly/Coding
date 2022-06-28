/*
 * Filename: /home/wei.zhao/cpp_code/Coding/AlphaPhi/Tensor.hpp
 * Path: /home/wei.zhao/cpp_code/Coding/AlphaPhi
 * Created Date: Friday, June 24th 2022, 7:49:57 pm
 * Author: Zhao Wei
 *
 * Copyright (c) 2022 The StreamComputing Inc
 */
#ifndef TENSOR_HPP
#define TENSOR_HPP
#include <algorithm>
#include <array>
#include <exception>
#include <functional>
#include <iostream>
#include <memory>
#include <numeric>
#include <string>
#include <vector>

namespace alphaphi {
class SmallVec {
 public:
  SmallVec() {
    data = new int[allocSize];
    size = allocSize;
  }

  void resize(int newSize) {
    if (newSize <= size) {
      size = newSize;
      data = new int[newSize];
    } else {
      auto tmpPtr = std::make_unique<int[]>(newSize);
      for (int i = 0; i < newSize; ++i) {
        tmpPtr[i] = data[i];
      }
      delete[] data;
      data = tmpPtr.release();
      size = newSize;
    }
  }

  size_t getSize() { return size; }

  int& operator[](int index) {
    if (index < size) {
      return data[index];
    } else {
      throw std::out_of_range("index out range...");
    }
  }

  const int& operator[](int index) const {
    if (index < size) {
      return data[index];
    } else {
      throw std::out_of_range("index out range...");
    }
  }

  ~SmallVec() { delete[] data; }

 private:
  const int allocSize = 4;
  size_t size;
  int* data;
};

template <typename T>
class Tensor {
 public:
  Tensor(std::initializer_list<int> arr) {
    is_allocate = true;
    setSizeShape(arr);
    dataT = new T[size];
  }

  Tensor(T* data, std::initializer_list<int> arr) : dataT(data) {
    setSizeShape(arr);
  };

  Tensor(size_t len): size(len){
    dataT = new T[len];
    is_abstract = true;
    shape[0] = len;
    dims = 1;
  }

  ~Tensor() { del(); }

  void del() {
    if (is_allocate) {
      delete[] dataT
    };
    is_allocate = false;
  }

  Tensor(const Tensor<T>& rSource) {
    size = rSource.size;
    dataT = new T[size];
    for (int i = 0; i < size; ++i) {
      dataT[i] = rSource.dataT[i];
    }

    is_allocate = true;
    for (int i = 0; i < rSource.shape.size(); ++i) {
      shape[i] = rSource.shape[i];
    }
  }

  Tensor& operator=(const Tensor<T>& rSource) {
    if (size == rSource.size) {
      for (int i = 0; i < size; ++i) {
        dataT[i] = rSource.dataT[i];
      }
    }
  }

  size_t getSize() const { return size; }

  std::array<int, 5> getShape() const { return shape; }

  size_t getDims() const { return dims; }
  T* getPtr(size_t index) {
    if (index < size) {
      return dataT + index;
    } else {
      return nullptr;
    }
  }

  void rehsape(std::initializer_list<int> arr) {
    size_t newSize =
        std::accumulate(arr.begin(), arr.end(), 1, std::multiplies<>());

    if (newSize == size) {
      std::copy(arr.begin(), arr.end(), shape.begin());
    } else {
      throw std::invalid_argument("two shape is not equ, reshape bad!\n");
    }
  }

  T& operator()(size_t dim0 = 0, size_t dim1 = 0, size_t dim2 = 0,
                size_t dim3 = 0, size_t dim4 = 0) {
    size_t index = dim0 * shape[1] * shape[2] * shape[3] * shape[4] +
                   dim1 * shape[2] * shape[3] * shape[4] +
                   dim2 * shape[3] * shape[4] + dim3 * shape[4] + dim4;
    return dataT[index];
  }

  const T& operator()(size_t dim0 = 1, size_t dim1 = 1, size_t dim2 = 1,
                      size_t dim3 = 1, size_t dim4 = 1) const {
    size_t index = dim0 * shape[1] * shape[2] * shape[3] * shape[4] +
                   dim1 * shape[2] * shape[3] * shape[4] +
                   dim2 * shape[3] * shape[4] + dim3 * shape[4] + dim4;
    return dataT[index];
  }
  T& operator[](size_t index) { return dataT[index]; }
  const T& operator[](size_t index) const { return dataT[index]; }

  template <typename Type>
  friend std::ostream& operator<<(std::ostream& os, const Tensor<Type>& source);

 private:
  size_t size = 0;
  std::array<int, 5> shape = {1, 1, 1, 1, 1};
  size_t dims = 0;
  T* dataT;
  bool is_allocate = false;

  void setSizeShape(std::initializer_list<int>& arr) {
    size_t i = 0;
    size = 1;
    for (auto iter = arr.begin(); iter != arr.end(); ++iter, ++i) {
      size *= (*iter);
#if 0
std::cout << (*iter) << std::endl;
#endif
      shape[i] = (*iter);
      dims++;
    }
  }
};

template <typename T>
std::ostream& operator<<(std::ostream& os, const Tensor<T>& source) {
  auto shape = source.getShape();
  size_t size = source.getSize();
  size_t dims = source.getDims();

  for (int i = 0; i < size; ++i) {
    os << source[i] << ", ";
    if ((i + 1) % shape[dims - 1] == 0) {
      os << std::endl;
    }
  }
  os << std::endl;
}
}  // namespace alphaphi

#endif