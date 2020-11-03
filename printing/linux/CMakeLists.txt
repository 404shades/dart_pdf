# Copyright (C) 2017, David PHAM-VAN <dev.nfet.net@gmail.com>
#
# Licensed under the Apache License, Version 2.0 (the "License"); you may not
# use this file except in compliance with the License. You may obtain a copy of
# the License at
#
# http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
# WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. See the
# License for the specific language governing permissions and limitations under
# the License.

cmake_minimum_required(VERSION 3.15)
set(PROJECT_NAME "printing")
project(${PROJECT_NAME} LANGUAGES CXX)

# Download pdfium
include(../windows/DownloadProject.cmake)
download_project(
  PROJ
  pdfium
  URL
  https://github.com/bblanchon/pdfium-binaries/releases/latest/download/pdfium-linux.tgz
  )

# This value is used when generating builds using this plugin, so it must not be
# changed
set(PLUGIN_NAME "printing_plugin")

include(${pdfium_SOURCE_DIR}/PDFiumConfig.cmake)

add_library(${PLUGIN_NAME} SHARED
            # "../windows/printing.cpp"
            # "../windows/printing.h"
            "printing_plugin.cpp" "include/printing/printing_plugin.h"
            # "../windows/print_job.cpp"
            # "../windows/print_job.h"
            # "print_job_linux.cpp"
            # "print_job_linux.h"
            )

apply_standard_settings(${PLUGIN_NAME})
set_target_properties(${PLUGIN_NAME} PROPERTIES CXX_VISIBILITY_PRESET hidden)
target_compile_definitions(${PLUGIN_NAME} PRIVATE FLUTTER_PLUGIN_IMPL)
target_include_directories(${PLUGIN_NAME}
                           INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}/include")
target_link_libraries(${PLUGIN_NAME} PRIVATE flutter)
target_link_libraries(${PLUGIN_NAME} PRIVATE PkgConfig::GTK)

# List of absolute paths to libraries that should be bundled with the plugin
set(printing_bundled_libraries
    "${pdfium_SOURCE_DIR}/lib/libpdfium.so"
    PARENT_SCOPE)
