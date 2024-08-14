#include "math_tools.hpp"

namespace tools
{
float limit_angle(float angle)
{
  while (angle > PI) angle -= 2 * PI;
  while (angle <= -PI) angle += 2 * PI;
  return angle;
}

float limit_max(float input, float max)
{
  if (input > max)
    input = max;
  else if (input < -max)
    input = -max;
  return input;
}

int deadband_limit(int input, int deadline) { return std::fabs(input) < deadline ? 0 : input; }

float uint_to_float(uint32_t input, float min, float max, size_t bits)
{
  auto span = max - min;
  auto norm = static_cast<float>(input) / ((1 << bits) - 1);
  return norm * span + min;
}

uint32_t float_to_uint(float input, float min, float max, size_t bits)
{
  auto span = max - min;
  auto norm = (input - min) / span;
  return norm * ((1 << bits) - 1);
}

}  // namespace tools
