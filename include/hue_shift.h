#ifndef HUE_SHIFT_H
#define HUE_SHIFT_H

#include <math.h>

//Define a struct to store the 3 color values
typedef struct{
  unsigned char r;
  unsigned char g;
  unsigned char b;
} CRGB;

unsigned char clamp(float v) //define a function to bound and round the input float value to 0-255
{
  if (v < 0)
    return 0;
  if (v > 255)
    return 255;
  return (unsigned char)v;
}

// Shift 0.0 to 1.0 wrapped
CRGB HueShift(const CRGB in, const float fHue)
{
  CRGB out;
  const float cosA = cos(fHue * 3.14159265f * 2); //convert degrees to radians
  const float sinA = sin(fHue * 3.14159265f * 2); //convert degrees to radians
  //calculate the rotation matrix, only depends on Hue
  float matrix[3][3] = { {cosA + (1.0f - cosA) / 3.0f, 1.0f / 3.0f * (1.0f - cosA) - sqrtf(1.0f / 3.0f) * sinA, 1.0f / 3.0f * (1.0f - cosA) + sqrtf(1.0f / 3.0f) * sinA},
      {1.0f / 3.0f * (1.0f - cosA) + sqrtf(1.0f / 3.0f) * sinA, cosA + 1.0f / 3.0f * (1.0f - cosA), 1.0f / 3.0f * (1.0f - cosA) - sqrtf(1.0f / 3.0f) * sinA},
      {1.0f / 3.0f * (1.0f - cosA) - sqrtf(1.0f / 3.0f) * sinA, 1.0f / 3.0f * (1.0f - cosA) + sqrtf(1.0f / 3.0f) * sinA, cosA + 1.0f / 3.0f * (1.0f - cosA)} };
  //Use the rotation matrix to convert the RGB directly
  out.r = clamp(in.r * matrix[0][0] + in.g * matrix[0][1] + in.b * matrix[0][2]);
  out.g = clamp(in.r * matrix[1][0] + in.g * matrix[1][1] + in.b * matrix[1][2]);
  out.b = clamp(in.r * matrix[2][0] + in.g * matrix[2][1] + in.b * matrix[2][2]);
  return out;
}

#endif