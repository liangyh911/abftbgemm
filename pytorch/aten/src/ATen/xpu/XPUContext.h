#pragma once

#include <c10/xpu/XPUFunctions.h>

namespace at::xpu {

// XPU is available if we compiled with XPU.
inline bool is_available() {
  return c10::xpu::device_count() > 0;
}

TORCH_XPU_API DeviceProp* getCurrentDeviceProperties();

TORCH_XPU_API DeviceProp* getDeviceProperties(DeviceIndex device);

TORCH_XPU_API int32_t getGlobalIdxFromDevice(DeviceIndex device);

} // namespace at::xpu
