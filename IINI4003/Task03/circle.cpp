const double pi = 3.141592;

class Circle {
public:
  Circle(double radius_);
  int get_area() const;
  double get_circumference() const;

private:
  double radius;
};

// ==> Implementasjon av klassen Circle

Circle::Circle(double radius_) : radius(radius_) {
}

int Circle::get_area() const {
  double area = pi * radius * radius;
  return area;
}

double Circle::get_circumference() const {
  double circumference = 2.0 * pi * radius;
  return circumference;
}