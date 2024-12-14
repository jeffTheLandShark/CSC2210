// cow_string.h: copy-on-write strings

#ifndef _cow_string_h
#define _cow_string_h

class cow_string {
public:
  cow_string(const char *text = "");

  virtual ~cow_string();

  cow_string(const cow_string &src);

  cow_string &operator=(const cow_string &src);

  const char &operator[](int index) const;

  char &operator[](int index);

  void get_inspection_data(char *buffer); // assumes buffer is large
private:
  struct shareable_string {
    int count = 0;
    char *contents = nullptr;

    shareable_string(const char *text);

    ~shareable_string();
  } *underlying_string = nullptr;

  static int bytes_allocated; // how many bytes allocated at any one time; must
  // be 0 at end
public:
  static int unreleased_bytes();
};

#endif
