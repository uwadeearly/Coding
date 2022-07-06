/*
 * Filename: /home/wei.zhao/cpp_code/Coding/AlphaPhi/Operation.hpp
 * Path: /home/wei.zhao/cpp_code/Coding/AlphaPhi
 * Created Date: Friday, June 24th 2022, 7:50:12 pm
 * Author: Zhao Wei
 *
 * Copyright (c) 2022 The StreamComputing Inc
 */
#ifndef LAYER_HPP
#define LAYER_HPP
#include <iostream>
#include <string>
#include <vector>
#include <memory>

#include "../Tensor.hpp"
using namespace std;

namespace alphaphi {
/* the feature of layer format is '[N, H, W, C]',
 * and kernel is '[kh, kw, cin, cout]'
 * in fact, i don't like this format, but ...
 */
template <typename T>
class BaseLayer {
public:
  BaseLayer() = default;
  virtual ~BaseLayer() = default;
  BaseLayer(const BaseLayer& src) = delete;
  this* operator=(const BaseLayer& src) = delete;

  virtual void build() = 0;
  virtual void forward(Tensor<T>& inputs) = 0;
  virtual void backward(Tensor<T>& delta) = 0;
};

template <typename T>
class DenseLayer : public BaseLayer<T> {
public:
  DenseLayer(size_t inShape, std::string name=nullptr){
    name = "dense_layer";
  }
  virtual ~DenseLayer(){

  }

  virtual build(){

  }
  virtual forward(Tensor<T>& inputs){}
  virtual backward(Tensor<T>& delta){}

  virtual Tensor<T>& getWeights(){
    return weights.get();
  }

private:
  std::name;
  size_t inShape;
  std::unique_ptr<Tensor<T>> weights;
};

template <typename T>
class ConvLayer : public BaseLayer<T> {};

template <typename T>
class Conv2DLayer : public Conv {};

template <typename T>
class ReluLayer : public BaseLayer<T> {};

template <typename T>
class BathNormalizationLayer : public BaseLayer<T> {};

template <typename T>
class SoftmaxLayer : public BaseLayer<T> {};

}  // namespace alphaphi

#endif