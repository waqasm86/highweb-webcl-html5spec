/*
 * DeviceApiPermissionController.h
 *
 *  Created on: 2015. 12. 1.
 *      Author: azureskybox
 */

#ifndef DeviceApiPermissionController_h
#define DeviceApiPermissionController_h

#include "core/frame/LocalFrame.h"
#include "platform/Supplementable.h"
#include "wtf/PassOwnPtr.h"
#include "public/platform/modules/device_api/WebDeviceApiPermissionCheckClient.h"

namespace blink {

class DeviceApiPermissionController final : public NoBaseWillBeGarbageCollectedFinalized<DeviceApiPermissionController>, public WillBeHeapSupplement<LocalFrame> {
	WILL_BE_USING_GARBAGE_COLLECTED_MIXIN(DeviceApiPermissionController);
public:
	~DeviceApiPermissionController();// override;

    static void provideTo(LocalFrame&, WebDeviceApiPermissionCheckClient*);
    static DeviceApiPermissionController* from(LocalFrame&);
    static const char* supplementName();

    WebDeviceApiPermissionCheckClient* client() { return m_client; };

	DECLARE_VIRTUAL_TRACE();

private:
	DeviceApiPermissionController(LocalFrame&, WebDeviceApiPermissionCheckClient*);

	WebDeviceApiPermissionCheckClient* m_client;
};

}

#endif  // DeviceApiPermissionController_h
