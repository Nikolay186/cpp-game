#include <Utils.h>

#include <chrono>

double Utils::drand(double min, double max) {
  std::uniform_real_distribution<double> distr(min, max);
  std::default_random_engine reng;
  auto s = std::chrono::system_clock::now().time_since_epoch().count();
  reng.seed(s);
  return distr(reng);
}
