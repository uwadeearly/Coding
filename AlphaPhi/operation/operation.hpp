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
        T tmp = 0;
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
            size_t stride) {
  auto outShape = dst.getShape();
  auto inShape = featMap.getShape();
  size_t batch = outShape[0];
  size_t outH = outShape[1];
  size_t outW = outShape[2];
  size_t outC = outShape[3];

  size_t inH = inShape[1];
  size_t inW = inShape[2];
  size_t inC = inShape[3];

  auto krShape = kernel.getShape();
  size_t kH = krShape[0];
  size_t kW = krShape[1];
  size_t inC = krShape[2];
  size_t outC = krShape[3];

  for (int n = 0; n < batch; ++n) {
    for (int h = 0; h < outH; ++h) {
      for (int w = 0; w < outW; ++w) {
        for (int c = 0; c < outC; ++c) {
          T tmp = 0;
          for (int kh = 0; kh < kH; ++kh) {
            for (int kw = 0; kw < kW; ++kw) {
              for (int cin = 0; cin < inC; ++cin) {
                // multipy and add
                size_t featIndex = n * inH * inW * inC +
                                   (h * stride + kh) * inW * inC +
                                   (w * stride + kw) * outC + cin;
                size_t kernelIndex =
                    kh * kW * inC * outC + kw * inC * outC + cin * outC + c;
                tmp += featMap[featIndex] * kernel[kernelIndex];
              }
            }
          }

          size_t outIndex =
              n * outH * outW * outC + h * outW * outC + w * outC + c;
          dst[outIndex] = tmp;
        }
      }
    }
  }
}

template <typename T>
T mean(Tensor<T>& featMap) {
  T mean = 0;
  size_t size = featMap.getSize();
  for (int i = 0; i < size; ++i) {
    mean += featMap[i];
  }
  return mean / size;
}

template <typename T>
T variance(Tensor<T>& featMap) {
  T var = 0;
  size_t size = featMap.getSize();
  for (int i = 0; i < size; ++i) {
    var += std::pow(featMap[i], 2);
  }
  return var;
}

template <typename T>
void relu(Tensor<T>& dst, Tensor<T>& featMap) {
  auto reluFunc = [](T x) {
    if (x > 0) {
      return x;
    } else {
      return 0;
    }
  };
  unaryOp<T>(dst, featMap, reluFunc);
}

template <typename T>
void softmax(Tensor<T>& dst, Tensor<T>& featMap) {
  auto shape = featMap.getShape();
  size_t rows = shape[0];
  size_t cols = shape[1];
  Tensor<T> tmp(rows);

  for (int i = 0; i < rows; ++i) {
    T max = featMap[i * cols];
    tmp[i] = 0;
    for (int j = 0; j < cols; ++j) {
      if (max < featMap[i * cols + j]) {
        max = featMap[i * cols + j];
      }
    }

    for (int j = 0; j < cols; ++j) {
      T expVal = std::exp(featMap[i * cols + j] - max);
      tmp[i] += expVal; 
      dst[i*cols +j] = expVal;
    }

    for(int j=0; j<clos; ++j){
      dst[i*cols +j] /= tmp[i];
    }
  }
}

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