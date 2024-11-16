void ex1() {
  // output: 129, a
  int a = 32;
  int *ptr = &a;
  char ch = 'A';
  char &cptr = ch;
  cptr += a;
  *ptr += ch;
  cout << a << ", " << ch << endl;
}

void ex2() {
  // output: compile error
  const int i = 20;
  const int *const ptr = &i;
  (*ptr)++;
  int j = 15;
  ptr = &j;
  cout << i;
}

void ex3() {
  // output: 10, 20, 30, 40, 50
  int num[5];
  int *p;
  p = num;
  *p = 10;
  ++p;
  *p = 20;
  p = &num[2];
  *p = 30;
  p = num + 3;
  *p = 40;
  p = num;
  *(p + 4) = 50;
  for (int i = 0; i < 5; ++i) {
    cout << num[i] << ", ";
  }
}

void ex4() {
  // output: 14
  int arr[] = {4, 5, 6, 7};
  int *p = (arr + 1);
  cout << *arr + 10;
}

void ex5() {
  // output: random address of b
  int a = 5, b = 10, c = 15;
  int *arr[] = {&a, &b, &c};
  cout << arr[1] << endl;
}

void ex6() {
  // output: ABCDEFGHIJ
  char arr[20];
  int i;
  for (i = 0; i < 10; ++i) {
    *(arr + i) = 65 + i;
  }
  *(arr + i) = '\0';
  cout << arr;
}

void ex7() {
  // output: in
  char *ptr;
  char str[] = "penguin";
  ptr = str;
  ptr += 5;
  cout << ptr;
}

void ex8() {
  // output: 88
  int myInt1 = 3, myInt2 = 3;
  int *ptr1 = &myInt1, *ptr2 = &myInt2;
  myInt1 = ++(*ptr1) + (*ptr1);
  myInt2++;
  myInt2 = (*ptr2) + (*ptr2);
  cout << myInt1 << myInt2;
}

int main() {
  ex1();
  ex2();
  ex3();
  ex4();
  ex5();
  ex6();
  ex7();
  ex8();
  return 0;
}