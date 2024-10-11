//
// Created by goetschm on 10/2/2024.
//

#ifndef RECTANGLE_H
#define RECTANGLE_H

class Rectangle {
  private:
    int width, height;

  public:
    Rectangle(int w, int h);

    int getWidth() const;
    int getHeight() const;

    void setWidth(int w);
    void setHeight(int h);

    int area() const;

};



#endif //RECTANGLE_H
