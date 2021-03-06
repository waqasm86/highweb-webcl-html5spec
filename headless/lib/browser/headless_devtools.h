// Copyright 2015 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef HEADLESS_LIB_BROWSER_HEADLESS_DEVTOOLS_H_
#define HEADLESS_LIB_BROWSER_HEADLESS_DEVTOOLS_H_

#include "base/memory/scoped_ptr.h"

namespace devtools_http_handler {
class DevToolsHttpHandler;
}

namespace headless {
class HeadlessBrowserContext;

// Starts a DevTools HTTP handler on the loopback interface on the port
// configured by HeadlessBrowser::Options.
scoped_ptr<devtools_http_handler::DevToolsHttpHandler>
CreateLocalDevToolsHttpHandler(HeadlessBrowserContext* browser_context);

}  // namespace content

#endif  // HEADLESS_LIB_BROWSER_HEADLESS_DEVTOOLS_H_
