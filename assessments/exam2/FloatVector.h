//
// Created by goetschm on 11/4/2024.
//

#ifndef FLOATVECTOR_H
#define FLOATVECTOR_H

#include <iostream>
#include <ostream>


class FloatVector {
public:
  virtual float &at(int index) = 0;
  virtual void dump() = 0;
};

class WeightVector : public FloatVector {
public:
  WeightVector(const int size) {
    this->size = size;
    data = new float[size];
  }

  ~WeightVector() {
    delete[] data;
  }

  float &at(const int index) override {
    if (index >= 0 && index < this->size) {
      return this->data[index];
    }
    std::cout << "index out of range" << std::endl;
    exit(-1);
  }

  void dump() override {
    for (int i = 0; i < this->size; i++) {
      std::cout << this->data[i] << " ";
    }
    std::cout << std::endl;
  }

private:
  int size;
  float *data;
};
#endif //FLOATVECTOR_H
