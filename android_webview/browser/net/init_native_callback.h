// Copyright (c) 2012 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef ANDROID_WEBVIEW_BROWSER_NET_INIT_NATIVE_CALLBACK_H_
#define ANDROID_WEBVIEW_BROWSER_NET_INIT_NATIVE_CALLBACK_H_

#include "base/memory/ref_counted.h"
#include "base/memory/scoped_ptr.h"

namespace base {
class SingleThreadTaskRunner;
}

namespace net {
class CookieStore;
class URLRequestInterceptor;
}  // namespace net

namespace android_webview {
class AwBrowserContext;

// Gets the TaskRunner that the CookieStore must be called on.
scoped_refptr<base::SingleThreadTaskRunner> GetCookieStoreTaskRunner();

// Gets a pointer to the CookieStore managed by the CookieManager.
// The CookieStore is never deleted. May only be called on the
// CookieStore's TaskRunner.
net::CookieStore* GetCookieStore();

// Called lazily when the job factory is being constructed.
scoped_ptr<net::URLRequestInterceptor>
    CreateAndroidAssetFileRequestInterceptor();

// Called lazily when the job factory is being constructed.
scoped_ptr<net::URLRequestInterceptor>
    CreateAndroidContentRequestInterceptor();

}  // namespace android_webview

#endif  // ANDROID_WEBVIEW_BROWSER_NET_INIT_NATIVE_CALLBACK_H_
