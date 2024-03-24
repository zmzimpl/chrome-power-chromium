#ifndef EXTENDED_PARAMETERS_H_
#define EXTENDED_PARAMETERS_H_

#include <variant>
#include <string>
#include <mutex>
#include "base/values.h"
#include "base/command_line.h"
#include "base/logging.h"
#include "base/base64.h"
#include "third_party/abseil-cpp/absl/types/optional.h"
#include "base/json/json_reader.h"

class ExtendedParameters {
 public:
  static ExtendedParameters* GetInstance();

  std::variant<std::string, int, float> GetParameter(const std::string& key) const;

 private:
  ExtendedParameters();
  ~ExtendedParameters() = default;

  void InitializeFromCommandLine();

  absl::optional<base::Value> parameters_;
  static std::mutex mutex_;
  static ExtendedParameters* instance_;
};

#endif  // EXTENDED_PARAMETERS_H_