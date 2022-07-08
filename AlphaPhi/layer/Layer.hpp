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
  DenseLayer(size_t inFeat, size_t outFeat, std::string name=nullptr){
    if(!name){
      name = "DenseLayer";
    } 
    weights = std::make_unique<Tensor<T>>({inFeat, outFeat});
    bias = std::make_unique<Tensor<T>>({outFeat});
  }
  virtual ~DenseLayer(){}

  DenseLayer(DenseLayer<T>& rSrc) = delete;
  DenseLayer<T>& operator=(DenseLayer<T>& rSrc) = delete;

  virtual void build(size_t, inFeat, size_t outFeat){
    setWeights(weights);
  }

  virtual void forward(Tensor<T>& inputs){
    //TODO
  }
  virtual void backward(Tensor<T>& delta){
    //TODO
  }

  Tensor<T>& getWeights(){
    return weights.get();
  }

  void setWeights(std::unique_ptr<Tensor<T>> weights){
    //TODO
  }


  void setBias(std::unique_ptr<Tensor<T>> bias){}
  virtual Tensor<T>& getBias(){
    return bias.get();
  }

private:
  std::name = "DenseLayer";
  size_t inShape;
  std::unique_ptr<Tensor<T>> weights;
  std::unique_ptr<Tensor<T>> bias;
};

template <typename T>
class Conv2DLayer : public BaseLayer<T> {
public:

private:
  std::name = "Conv2dLayer";
  std::unique_ptr<Tensor<T>> kernel;
  std::unique_ptr<Tensor<T>> bias;
};


template <typename T>
class ReluLayer : public BaseLayer<T> {};

template <typename T>
class BathNormalizationLayer : public BaseLayer<T> {};

template <typename T>
class SoftmaxLayer : public BaseLayer<T> {};

}  // namespace alphaphi

#endif