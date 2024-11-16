// pointers.cpp: illustrate pointers

#include <cstdint>
#include <iomanip>
#include <iostream>

using namespace std;

constexpr int STOP = -1;
constexpr int INSTRUCTIONS_TO_PRINT = 40;

// can call this to fill up the stack with random values
int fib(int n) {
  if (n < 2)
    return 1;
  else
    return fib(n - 1) + fib(n - 2);
}

void report(int *p, int line) {
  cout << "@ line " << line << ", p is at address " << hex << p;
  cout << ", value " << dec << *p << " (0x" << hex << *p << ")" << endl;
  cout << dec;
}

int location(int target, int nums[], int end_val) {
  int *p = &nums[0];
  report(p, __LINE__);
  while (p != nullptr && *p != end_val && *p != target) {
    ++p;
    report(p, __LINE__);
  }
  if (p == nullptr || *p != target)
    return -1;
  else {
    int index = p - nums;
    return index;
  }
}

void report_random() {
  constexpr int ITEMS = 5;
  int num[ITEMS];
  cout << "Uninitialized data in report_random (size " << sizeof(num) << "):";
  for (int i = 0; i < ITEMS; ++i)
    cout << " " << num[i];
  cout << endl;
}

void dump_fib() {
  cout << "Instructions for fib():" << endl;
  int *instruction = (int *)&fib;
  cout << hex;
  for (int i = 0; i < INSTRUCTIONS_TO_PRINT / 4; ++i) {
    cout << instruction << ": " << setw(8) << *instruction;
    cout << "    ";
    ++instruction;
    cout << instruction << ": " << setw(8) << *instruction;
    cout << "    ";
    ++instruction;
    cout << instruction << ": " << setw(8) << *instruction;
    cout << "    ";
    ++instruction;
    *instruction += 1;
    cout << instruction << ": " << setw(8) << *instruction;
    cout << endl;
    ++instruction;
  }
  cout << dec;
  cout << "Fib of 5: " << fib(5) << endl;
}

int main() {
  // test location
  int some_numbers[30] = {1,  1,  2,  3,   5,   8,   13,  21,
                          34, 55, 89, 144, 233, 377, STOP};

  cout << "--------------------------------------------------" << endl;
  cout << "Values for call to location()" << endl;
  int *p = &some_numbers[0];
  while (*p != STOP) {
    cout << " " << *p;
    p++;
  }
  cout << " END" << endl;
  cout << "--------------------------------------------------" << endl;
  int loc;
  loc = location(144, some_numbers, STOP);
  cout << "144 is at index " << loc << endl;
  cout << "--------------------------------------------------" << endl;
  report_random();
  cout << "--------------------------------------------------" << endl;
  dump_fib();

  return 0;
}
