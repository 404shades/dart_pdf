/*
 * Copyright (C) 2017, David PHAM-VAN <dev.nfet.net@gmail.com>
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef PRINTING_PLUGIN_PRINT_JOB_LINUX_H_
#define PRINTING_PLUGIN_PRINT_JOB_LINUX_H_

#include "print_job.h"

#include <flutter/method_channel.h>
#include <flutter/standard_method_codec.h>

#include <map>
#include <memory>
#include <sstream>

namespace printing {
class PrintJobLinux : PrintJob {
 public:
  PrintJobLinux(std::shared_ptr<PrintingPlugin> printing, int index);
};

}  // namespace printing

#endif  // PRINTING_PLUGIN_PRINT_JOB_WINDOWS_H_
