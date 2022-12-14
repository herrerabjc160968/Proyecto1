/* Copyright 2021 The TensorFlow Authors. All Rights Reserved.

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
==============================================================================*/

#include "tensorflow/core/data/service/py_utils.h"

#include <string>

#include "tensorflow/core/data/service/credentials_factory.h"

namespace tensorflow {
namespace data {

std::string DefaultProtocol() {
#if defined(PLATFORM_GOOGLE)
  if (CredentialsFactory::Exists("grpc+loas")) {
    return "grpc+loas";
  }
  static absl::once_flag log_once;
  absl::call_once(log_once, [] {
    LOG(WARNING)
        << "loas credentials factory is not available, falling back to "
           "using insecure credentials.";
  });
#endif  // PLATFORM_GOOGLE
  return "grpc";
}

std::string DefaultDataTransferProtocol() { return "grpc"; }

}  // namespace data
}  // namespace tensorflow
