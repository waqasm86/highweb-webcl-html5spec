// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "content/browser/service_worker/service_worker_info.h"

#include "content/common/service_worker/service_worker_types.h"
#include "content/public/common/child_process_host.h"
#include "ipc/ipc_message.h"

namespace content {

ServiceWorkerVersionInfo::ClientInfo::ClientInfo()
    : ClientInfo(ChildProcessHost::kInvalidUniqueID,
                 MSG_ROUTING_NONE,
                 SERVICE_WORKER_PROVIDER_UNKNOWN) {}

ServiceWorkerVersionInfo::ClientInfo::ClientInfo(int process_id,
                                                 int route_id,
                                                 ServiceWorkerProviderType type)
    : process_id(process_id), route_id(route_id), type(type) {
}

ServiceWorkerVersionInfo::ClientInfo::~ClientInfo() {
}

ServiceWorkerVersionInfo::ServiceWorkerVersionInfo()
    : running_status(ServiceWorkerVersion::STOPPED),
      status(ServiceWorkerVersion::NEW),
      registration_id(kInvalidServiceWorkerRegistrationId),
      version_id(kInvalidServiceWorkerVersionId),
      process_id(ChildProcessHost::kInvalidUniqueID),
      thread_id(kInvalidEmbeddedWorkerThreadId),
      devtools_agent_route_id(MSG_ROUTING_NONE) {}

ServiceWorkerVersionInfo::ServiceWorkerVersionInfo(
    ServiceWorkerVersion::RunningStatus running_status,
    ServiceWorkerVersion::Status status,
    const GURL& script_url,
    int64_t registration_id,
    int64_t version_id,
    int process_id,
    int thread_id,
    int devtools_agent_route_id)
    : running_status(running_status),
      status(status),
      script_url(script_url),
      registration_id(registration_id),
      version_id(version_id),
      process_id(process_id),
      thread_id(thread_id),
      devtools_agent_route_id(devtools_agent_route_id) {}

ServiceWorkerVersionInfo::ServiceWorkerVersionInfo(
    const ServiceWorkerVersionInfo& other) = default;

ServiceWorkerVersionInfo::~ServiceWorkerVersionInfo() {}

ServiceWorkerRegistrationInfo::ServiceWorkerRegistrationInfo()
    : registration_id(kInvalidServiceWorkerRegistrationId),
      delete_flag(IS_NOT_DELETED),
      force_update_on_page_load(IS_NOT_FORCED),
      stored_version_size_bytes(0) {}

ServiceWorkerRegistrationInfo::ServiceWorkerRegistrationInfo(
    const GURL& pattern,
    int64_t registration_id,
    DeleteFlag delete_flag)
    : pattern(pattern),
      registration_id(registration_id),
      delete_flag(delete_flag),
      force_update_on_page_load(IS_NOT_FORCED),
      stored_version_size_bytes(0) {}

ServiceWorkerRegistrationInfo::ServiceWorkerRegistrationInfo(
    const GURL& pattern,
    int64_t registration_id,
    DeleteFlag delete_flag,
    ForceUpdateOnPageLoad force_update_on_page_load,
    const ServiceWorkerVersionInfo& active_version,
    const ServiceWorkerVersionInfo& waiting_version,
    const ServiceWorkerVersionInfo& installing_version,
    int64_t stored_version_size_bytes)
    : pattern(pattern),
      registration_id(registration_id),
      delete_flag(delete_flag),
      force_update_on_page_load(force_update_on_page_load),
      active_version(active_version),
      waiting_version(waiting_version),
      installing_version(installing_version),
      stored_version_size_bytes(stored_version_size_bytes) {}

ServiceWorkerRegistrationInfo::ServiceWorkerRegistrationInfo(
    const ServiceWorkerRegistrationInfo& other) = default;

ServiceWorkerRegistrationInfo::~ServiceWorkerRegistrationInfo() {}

}  // namespace content
