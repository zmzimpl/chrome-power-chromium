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

int getRandomAudioNum() {
  srand(int(time(0)));

  std::variant<std::string, int, float> param =
      ExtendedParameters::GetInstance()->GetParameter(
          fingerprint::audio::audioFlag);

  int result = 0;
  int* int_ptr = std::get_if<int>(&param);
  if (int_ptr) {
    result = *int_ptr;
  } else {
    result = rand() % 99;
  }

  return result;
}
