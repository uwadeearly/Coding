/*
 * Filename: /home/wei.zhao/cpp_code/Coding/AlphaPhi/model/Model.hpp
 * Path: /home/wei.zhao/cpp_code/Coding/AlphaPhi/model
 * Created Date: Friday, June 24th 2022, 7:50:19 pm
 * Author: Zhao Wei
 *
 * Copyright (c) 2022 The StreamComputing Inc
 */

#ifndef MODEL_HPP
#define MODEL_HPP
#include <iostream>
#include <memory>
#include <string>
#include <vector>

#include "../Tensor.hpp"

namespace alphaphi {
template <typename T>
class Model {
 public:
  using LayerPtr = std::unique_ptr<Layer<T>>;
  using tensorPrt = std::unique_ptr<Tensor<T>>

  Model() = default;
  Model(Model<T>& rSrc) = delete;
  Model& operator=(Model<T>& rSrc) = delete;

  void forward() {}

  void backward() {}

 private:
  vector<LayerPtr> layers;
  tensorPrt inputs;
  tensorPrt outputs;
};
}  // namespace alphaphi

#endif // MODEL_HPP