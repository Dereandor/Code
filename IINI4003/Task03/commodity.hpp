#pragma once
#include <string>

using namespace std;

class Commodity {
public:
  Commodity(string name_, int id_, double price_);
  string get_name();
  int get_id();
  double get_price(double amount);
  double get_price();
  void set_price(double newPrice);
  double get_price_with_sales_tax(double amount);
  double get_price_with_sales_tax();

private:
  string name;
  int id;
  double price;
};

Commodity::Commodity(string name_, int id_, double price_) : name(name_), id(id_), price(price_) {
}

string Commodity::get_name() {
  return name;
}

int Commodity::get_id() {
  return id;
}

double Commodity::get_price(double amount) {
  return price * amount;
}

double Commodity::get_price() {
  return price;
}

void Commodity::set_price(double newPrice) {
  price = newPrice;
}

double Commodity::get_price_with_sales_tax(double amount) {
  return (price * amount) * 1.25;
}

double Commodity::get_price_with_sales_tax() {
  return price * 1.25;
}