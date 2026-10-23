// local
#include "json_to_string.hpp"

// cppcheck-supress unusedFunction
std::string json_to_string(const nlohmann::json &value) {
  {
    if (value.is_string()) {
      return value.get<std::string>();
    }

    if (value.is_number_integer()) {
      return std::to_string(value.get<long long>());
    }

    return value.dump();
  }
}
