//
// Created by goetschm on 10/2/2024.
//

#include "rectangle.h"

Rectangle::Rectangle(int w, int h) {
  Rectangle::width = w;
  Rectangle::height = h;
}

int Rectangle::getHeight() const {
  return Rectangle::height;
}

int Rectangle::getWidth() const {
  return Rectangle::width;
}

void Rectangle::setHeight(int h) {
  Rectangle::height = h;
}

void Rectangle::setWidth(int w) {
  Rectangle::width = w;
}

int Rectangle::area() const {
  return Rectangle::width * Rectangle::height;
}
