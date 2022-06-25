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
#include <vector>
#include <string>
#include "../Tensor.hpp"
using namespace std;

template<typename T>
class BaseLayer{

};


template<typename T>
class DenseLayer: public BaseLayer<T>{

};

template<typename T>
class ConvLayer: public BaseLayer<T>{

};

template<typename T>
class Conv2DLayer: public Conv{

};


template<typename T>
class ReluLayer: public BaseLayer<T>{

};

template<typename T>
class BathNormalizationLayer: public BaseLayer<T>{

};


template<typename T>
class SoftmaxLayer: public BaseLayer<T>{

};

#endif