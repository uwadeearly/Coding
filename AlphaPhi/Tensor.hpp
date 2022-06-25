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
#include <exception>
#include <iostream>
#include <memory>
#include <string>
#include <vector>

class SmallVec {
 public:
  SmallVec() {
    data = new int[allocSize];
    size = allocSize;
  }

  void resize(int newSize) {
    if (newSize <= size) {
      size = newSize;
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

  size_t getSize(){return size;}

  int& operator[](int index) {
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
  Tensor(std::initializer_list arr) {
    is_allocate = true;
    size = 1;
    for (auto iter = arr.begin(); iter < arr.end(); ++iter) {
      size *= (*iter);
    }
    data = new T[size];
  }

  Tensor(T* data, std::initializer_list arr) : dataT(data), Tensor(arr){};

  ~Tensor() {
    if (is_allocate) delete[] dataT;
  }

  Tensor(const Tensor<T>& rSource) {}

  Tensor& operator=(const Tensor<T>& rSource) {}

  size_t getSize() { return size; }

  SmallVec getShape() { return shape; }

  void rehsape(){
    
  }

  template <typename Type>
      friend std::ostream& opterator
      << (std::ostream & os, const Tensor<Type>& source);

 private:
  size_t size;
  SmallVec shape;
  T* dataT;
  bool is_allocate = false;
};

#endif