// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef MOJO_PUBLIC_CPP_BINDINGS_LIB_STRING_SERIALIZATION_H_
#define MOJO_PUBLIC_CPP_BINDINGS_LIB_STRING_SERIALIZATION_H_

#include <stddef.h>

#include "mojo/public/cpp/bindings/lib/array_internal.h"
#include "mojo/public/cpp/bindings/string.h"

namespace mojo {

size_t GetSerializedSize_(const String& input,
                          internal::SerializationContext* context);
void Serialize_(const String& input,
                internal::Buffer* buffer,
                internal::String_Data** output,
                internal::SerializationContext* context);
bool Deserialize_(internal::String_Data* input,
                  String* output,
                  internal::SerializationContext* context);

}  // namespace mojo

#endif  // MOJO_PUBLIC_CPP_BINDINGS_LIB_STRING_SERIALIZATION_H_
