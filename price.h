#ifndef PRICE_H
#define PRICE_H
#include<iostream>
using namespace std;
class Price{
  friend ostream& operator<<(ostream& o, const Price& m);

 private:
  int dollar;
  int cent;
 public:
  Price();
  Price(int d, int c);
  // ostream& operator<<(ostream& o, const Price& c);
  Price operator+(const Price& p2);
  Price operator-(const Price& p2);
};

#endif
