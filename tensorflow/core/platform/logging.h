/* Copyright 2015 The TensorFlow Authors. All Rights Reserved.

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

#ifndef TENSORFLOW_CORE_PLATFORM_LOGGING_H_
#define TENSORFLOW_CORE_PLATFORM_LOGGING_H_

#include "tensorflow/core/platform/platform.h"  // To pick up PLATFORM_define
#include "tensorflow/core/platform/types.h"

#if defined(PLATFORM_GOOGLE) || defined(PLATFORM_GOOGLE_ANDROID) || \
    defined(PLATFORM_GOOGLE_IOS) || defined(GOOGLE_LOGGING) ||      \
    defined(__EMSCRIPTEN__) || defined(PLATFORM_CHROMIUMOS)
#include "tensorflow/tsl/platform/google/logging.h"  // IWYU pragma: export
#else
#include "tensorflow/tsl/platform/default/logging.h"  // IWYU pragma: export
#endif

namespace tensorflow {

namespace internal {
// Emit "message" as a log message to the log for the specified
// "severity" as if it came from a LOG call at "fname:line"
void LogString(const char* fname, int line, int severity,
               const std::string& message);
}  // namespace internal

}  // namespace tensorflow

#endif  // TENSORFLOW_CORE_PLATFORM_LOGGING_H_
