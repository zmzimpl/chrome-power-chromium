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

// #include "base/values.h"
// #include "base/json/json_reader.h"
// #include "third_party/blink/renderer/chrome_power/base/extended_parameters.h"

int getRandomNum() {
  srand(int(time(0)));
  return rand() % 20;
}

String getRandomStr() {
  srand(int(time(0)));
  String str_list[] = {"a", "b", "c", "d", "e", "f", "g", "h", "i",
                       "j", "k", "l", "m", "n", "o", "p", "q", "r",
                       "s", "t", "u", "v", "w", "x", "y", "z", "0",
                       "1", "2", "3", "4", "5", "6", "7", "8", "9"};

  std::variant<std::string, int, float> param =
      ExtendedParameters::GetInstance()->GetParameter(
          fingerprint::canvas::textFlag);

  String result;

  std::string pathStr;
  // 显式声明指针类型
  std::string* str_ptr = std::get_if<std::string>(&param);
  if (str_ptr) {
    pathStr = *str_ptr;
  }
  if (!pathStr.empty()) {
    result = String::FromUTF8(pathStr.c_str(), pathStr.length());
  } else {
    int length = sizeof(str_list) / sizeof(str_list[0]);
    result = str_list[rand() % length];
  }

  return result;
}
