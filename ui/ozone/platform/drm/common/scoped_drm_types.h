// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef UI_OZONE_PLATFORM_DRM_COMMON_SCOPED_DRM_TYPES_H_
#define UI_OZONE_PLATFORM_DRM_COMMON_SCOPED_DRM_TYPES_H_

#include "base/memory/scoped_ptr.h"

typedef struct _drmModeConnector drmModeConnector;
typedef struct _drmModeCrtc drmModeCrtc;
typedef struct _drmModeEncoder drmModeEncoder;
typedef struct _drmModeFB drmModeFB;
typedef struct _drmModeObjectProperties drmModeObjectProperties;
typedef struct _drmModePlane drmModePlane;
typedef struct _drmModePlaneRes drmModePlaneRes;
typedef struct _drmModeProperty drmModePropertyRes;
typedef struct _drmModeAtomicReq drmModeAtomicReq;
typedef struct _drmModePropertyBlob drmModePropertyBlobRes;
typedef struct _drmModeRes drmModeRes;

namespace ui {

struct DrmResourcesDeleter {
  void operator()(drmModeRes* resources) const;
};
struct DrmConnectorDeleter {
  void operator()(drmModeConnector* connector) const;
};
struct DrmCrtcDeleter {
  void operator()(drmModeCrtc* crtc) const;
};
struct DrmEncoderDeleter {
  void operator()(drmModeEncoder* encoder) const;
};
struct DrmObjectPropertiesDeleter {
  void operator()(drmModeObjectProperties* properties) const;
};
struct DrmPlaneDeleter {
  void operator()(drmModePlane* plane) const;
};
struct DrmPlaneResDeleter {
  void operator()(drmModePlaneRes* plane_res) const;
};
struct DrmPropertyDeleter {
  void operator()(drmModePropertyRes* property) const;
};
#if defined(USE_DRM_ATOMIC)
struct DrmAtomicReqDeleter {
  void operator()(drmModeAtomicReq* property) const;
};
#endif  // defined(USE_DRM_ATOMIC)
struct DrmPropertyBlobDeleter {
  void operator()(drmModePropertyBlobRes* property) const;
};
struct DrmFramebufferDeleter {
  void operator()(drmModeFB* framebuffer) const;
};

typedef scoped_ptr<drmModeRes, DrmResourcesDeleter> ScopedDrmResourcesPtr;
typedef scoped_ptr<drmModeConnector, DrmConnectorDeleter> ScopedDrmConnectorPtr;
typedef scoped_ptr<drmModeCrtc, DrmCrtcDeleter> ScopedDrmCrtcPtr;
typedef scoped_ptr<drmModeEncoder, DrmEncoderDeleter> ScopedDrmEncoderPtr;
typedef scoped_ptr<drmModeObjectProperties, DrmObjectPropertiesDeleter>
    ScopedDrmObjectPropertyPtr;
typedef scoped_ptr<drmModePlane, DrmPlaneDeleter> ScopedDrmPlanePtr;
typedef scoped_ptr<drmModePlaneRes, DrmPlaneResDeleter> ScopedDrmPlaneResPtr;
typedef scoped_ptr<drmModePropertyRes, DrmPropertyDeleter> ScopedDrmPropertyPtr;
#if defined(USE_DRM_ATOMIC)
typedef scoped_ptr<drmModeAtomicReq, DrmAtomicReqDeleter> ScopedDrmAtomicReqPtr;
#endif  // defined(USE_DRM_ATOMIC)
typedef scoped_ptr<drmModePropertyBlobRes, DrmPropertyBlobDeleter>
    ScopedDrmPropertyBlobPtr;
typedef scoped_ptr<drmModeFB, DrmFramebufferDeleter> ScopedDrmFramebufferPtr;

}  // namespace ui

#endif  // UI_OZONE_PLATFORM_DRM_COMMON_SCOPED_DRM_TYPES_H_
