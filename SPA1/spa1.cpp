/*
 * SPA 1, Fall 2024, Leigh Goetsch
 */

#include <iostream>
using namespace std;

int main() {
  int totalFluid = 0;
  string time;
  string item;
  int fluid;

  cin >> time >> item >> fluid;

  while (cin) {
    if (item == "urine" || item == "bloodloss"|| item == "diarrhea") {
      totalFluid -= fluid;
    } else {
      totalFluid += fluid;
      
      if (totalFluid >= 1000) {
      cout << "after consuming " << item
      << " at " << time << ", intake exceeds output by " << totalFluid << " ml"<<endl;
      }
    }

    cin >> time >> item >> fluid;
  }
  cout << "the final fluid differential is " << totalFluid << " ml" << endl;
  return 0;
}