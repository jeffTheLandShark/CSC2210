// road.h

#ifndef _road_h
#define _road_h

#include <string>

class Vehicle; // declare the class so Road can use it

class Road {
public:
  Road(std::string description);
  void advance_one_step();
  bool is_clear() const;
  int steps_to_clear() const;
  // return true if the spot exists and is nullptr or it doesn't exist
  bool spot_is_clear(int index) const;
  void display();
private:
  int length;
  int cur_step;
  Vehicle** spots;      // array of spaces, allocated in constructor
};

class Vehicle {
public:
  Vehicle(Road *road_on) : _can_move{false}, road{road_on} { }
  bool can_move() const { return _can_move; }
  void reset_move_state() { _can_move = false; }
protected:
  bool _can_move;        // is vehicle in a place where it can move?
  Road *road;            // current road vehicle is on
};

// TODO: add car, taxi, eighteenwheeler classes

#endif
