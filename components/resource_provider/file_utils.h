// Copyright 2015 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef COMPONENTS_RESOURCE_PROVIDER_FILE_UTILS_H_
#define COMPONENTS_RESOURCE_PROVIDER_FILE_UTILS_H_

#include <string>

namespace base {
class FilePath;
}

namespace resource_provider {

// Returns the path to the resources for |application_name|, or an empty
// path if |application_name| is not valid.
base::FilePath GetPathForApplicationName(const std::string& application_name);

// Returns the path to the specified resource. |app_path| was previously
// obtained by way of GetPathForApplicationName().
base::FilePath GetPathForResourceNamed(const base::FilePath& app_path,
                                       const std::string& resource_path);

}  // namespace resource_provider

#endif  // COMPONENTS_RESOURCE_PROVIDER_FILE_UTILS_H_
