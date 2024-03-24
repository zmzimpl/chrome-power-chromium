// extended_parameters.cc
#include "third_party/blink/renderer/chrome_power/base/extended_parameters.h"
#include "third_party/blink/renderer/chrome_power/base/custom_command.h"

std::mutex ExtendedParameters::mutex_;
ExtendedParameters* ExtendedParameters::instance_ = nullptr;

ExtendedParameters::ExtendedParameters() {
  InitializeFromCommandLine();
}

ExtendedParameters* ExtendedParameters::GetInstance() {
  std::lock_guard<std::mutex> lock(mutex_);
  if (instance_ == nullptr) {
    instance_ = new ExtendedParameters();
  }
  return instance_;
}

void ExtendedParameters::InitializeFromCommandLine() {
  const auto& command_line = *base::CommandLine::ForCurrentProcess();

  if (command_line.HasSwitch(chrome_power::kExtendedParametersFlag)) {
    std::string encoded_param =
        command_line.GetSwitchValueASCII(chrome_power::kExtendedParametersFlag);
    std::string json_string;
    if (base::Base64Decode(encoded_param, &json_string)) {
      absl::optional<base::Value> parsed_json =
          base::JSONReader::Read(json_string);
      if (parsed_json) {
        LOG(WARNING) << "Extended parameters: " << parsed_json.value();
        parameters_ = std::move(*parsed_json);
      } else {
        LOG(ERROR) << "Failed to parse JSON parameters.";
      }
    } else {
      LOG(ERROR) << "Failed to decode extended-parameters.";
    }
  } else {
    LOG(WARNING) << "No extended-parameters found.";
  }
}

std::variant<std::string, int, float> ExtendedParameters::GetParameter(
    const std::string& key) const {
  LOG(WARNING) << "Extended parameters: " << parameters_.value();
  if (parameters_ && parameters_->is_dict()) {
    const auto& dict = parameters_->GetDict();

    const base::Value* value = dict.Find(key);
    if (value) {
      if (value->is_string()) {
        return value->GetString();
      } else if (value->is_int()) {
        return value->GetInt();
      } else if (value->is_double()) {
        double double_value = value->GetDouble();
        return static_cast<float>(double_value);
      }
    }
  }
  return "";  // 或者返回一个默认的数值，视您的需要而定
}
