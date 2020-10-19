template <class type1, class type2>
class Pair {
public:
  type1 first;
  type2 second;

  Pair(type1 _first, type2 _second) {
    first = _first;
    second = _second;
  }

  Pair operator+(const Pair &other) {
    Pair pair = *this;
    pair.first += other.first;
    pair.second += other.second;
    return pair;
  }

  bool operator>(const Pair &other) {
    type1 sum_one = first + second;
    type1 sum_two = other.first + other.second;
    type1 difference = sum_one - sum_two;

    if (difference > 0) {
      return 1;
    } else {
      return 0;
    }
  }
};