// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "sync/internal_api/public/events/protocol_event.h"

namespace syncer {

ProtocolEvent::ProtocolEvent() {}

ProtocolEvent::~ProtocolEvent() {}

scoped_ptr<base::DictionaryValue> ProtocolEvent::ToValue(
    const ProtocolEvent& event) {
  scoped_ptr<base::DictionaryValue> dict(new base::DictionaryValue());

  dict->SetDouble("time", event.GetTimestamp().ToJsTime());
  dict->SetString("type", event.GetType());
  dict->SetString("details", event.GetDetails());
  dict->Set("proto", event.GetProtoMessage().release());

  return dict;
}

}  // namespace syncer
