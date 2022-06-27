/*
 * Filename: /home/wei.zhao/cpp_code/Coding/AlphaPhi/operation/operation.hpp
 * Path: /home/wei.zhao/cpp_code/Coding/AlphaPhi/operation
 * Created Date: Saturday, June 25th 2022, 9:41:08 am
 * Author: Zhao Wei
 *
 * Copyright (c) 2022 The StreamComputing Inc
 */

#ifndef OPERATION_HPP
#define OPERATION_HPP
#include <cmath>
#include <exception>
#include <functional>

#include "Tensor.hpp"
namespace alphaphi {
template <typename T>
void binaryOp(Tensor<T>& dst, Tensor<T>& left, Tensor<T>& right,
              std::function<T(T, T)> func) {
  size_t lSize = left.getSize();
  size_t rSize = right.getSize();
  if (lSize == rSize) {
    for (int i = 0; i < lSize; ++i) {
      dst[i] = func(left[i], right[i]);
    }
  } else {
    throw std::length_error("two tenosr size not eq...");
  }
}

template <typename T>
void unaryOp(Tensor<T>& dst, Tensor<T>& src, std::function<T(T)> func) {
  size_t inSize = src.getSize();
  for (int i = 0; i < inSize; ++i) {
    dst[i] = func(src[i]);
  }
}

template <typename T>
void dot(Tensor<T>& dst, Tensor<T>& left, Tensor<T>& right) {
  size_t lDims = left.getDims();
  size_t rDims = right.getDims();
  if (lDims == 2 && rDims == 2) {
    auto lShape = left.getShape();
    auto rShape = right.getShape();
    size_t m = lshape[0];
    size_t n = lshape[1];
    size_t k = rshape[1];

    for (size_t i = 0; i < m; ++i) {
      for (size_t j = 0; j < k; ++j) {
        size_t tmp = 0;
        for (size_t q = 0; q < n; ++q) {
          tmp += left[i * n + q] * right(q * n + j);
        }
        dst[i * m + j] = tmp;
      }
    }
  } else {
    throw std::out_of_range("two inputs dims is not eq...");
  }
}

template <typename T>
void conv2d(Tensor<T>& dst, Tensor<T>& featMap, Tensor<T>& kernel,
            size_t stride, size_t padding) {}

template <typename T>
void bn(Tensor<T>& dst, Tensor<T>& featMap) {}

template <typename T>
void relu(Tensor<T>& dst, Tensor<T>& featMap) {}

template <typename T>
void softmax(Tensor<T>& dst, Tensor<T>& featMap) {}

template <typename T>
void conv2dTranspose(Tensor<T>& dst, Tensor<T>& featMap, Tensor<T>& kernel) {}

template <typename T>
void transpose2D(Tensor<T>& dst, Tensor<T>& src) {
  if (src.getDims() != dst.getDims() || src.getSize() != dst.getSize()) {
    throw std::length_error("two tensor shape is not eq...");
  }
  auto inShape = src.getShape();
  size_t rows = inShape[0];
  size_t cols = inShape[1];

  for (size_t i = 0; i < rows; ++i) {
    for (size_t j = 0; j < cols; ++j) {
      dst[j * rows + i] = src[i * cols + j];
    }
  }
}

// transpose operation on its ground
template <typename T>
void transpose2D(Tensor<T>& src) {
  auto shape = src;
  size_t rows = shape[0];
  size_t cols = shape[1];
  for (int i = 0; i < rows; ++i) {
    for (int j = 0; j < cols; ++j) {
      std::swap(src[j * rows + i], src[i * cols + j]);
    }
  }
}

}  // namespace alphaphi

#endif