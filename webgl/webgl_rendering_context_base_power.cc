#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <algorithm>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>
#include "third_party/blink/renderer/chrome_power/base/extended_parameters.h"
#include "third_party/blink/renderer/chrome_power/base/fingerprint.h"

// int randomFunc(int arr_len) {
//   return rand() % arr_len;
// }

// String getRandomGPU() {
//   srand(int(time(0)));
//   String gpuList[] = {
//       "ANGLE (NVIDIA, NVIDIA GeForce RTX 3080 Direct3D11 vs_5_0 ps_5_0,
//       D3D11)", "ANGLE (NVIDIA, NVIDIA GeForce RTX 3070 Direct3D11 vs_5_0
//       ps_5_0, D3D11)", "ANGLE (NVIDIA, NVIDIA GeForce RTX 3060 Direct3D11
//       vs_5_0 ps_5_0, D3D11)",
//   };
//   int length = sizeof(gpuList) / sizeof(gpuList[0]);
//   return gpuList[randomFunc(length)];
// }

float getRandomFloat() {
  srand((unsigned int)time(NULL));

  std::variant<std::string, int, float> param =
      ExtendedParameters::GetInstance()->GetParameter(
          fingerprint::webgl::floatFlag);

  std::visit(
      [](auto&& arg) {
        using T = std::decay_t<decltype(arg)>;
        if constexpr (std::is_same_v<T, float>) {
          LOG(WARNING) << "param is a float: " << arg << std::endl;
        } else if constexpr (std::is_same_v<T, int>) {
          LOG(WARNING) << "param is an int: " << arg << std::endl;
        } else if constexpr (std::is_same_v<T, std::string>) {
          LOG(WARNING) << "param is a string: " << arg << std::endl;
        } else {
          LOG(WARNING) << "param is of unknown type " << std::endl;
        }
      },
      param);

  float result;

  float* float_ptr = std::get_if<float>(&param);
  if (float_ptr) {
    result = *float_ptr;
  } else {
    result = static_cast<float>(rand()) / static_cast<float>(RAND_MAX) / 2;
  }
  return result;
}
