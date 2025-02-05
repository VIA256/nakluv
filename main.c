#include <vulkan/vulkan.h>

#include <stdio.h>
#include <stdint.h>

int main(void){
	VkInstance vki;
	VkInstanceCreateInfo vkici = (VkInstanceCreateInfo){
		VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO,//sType
		NULL,//pNext
		0,//flags
		NULL,//pApplicationInfo
		0,//enabledLayerCount
		NULL,//ppEnabledLayerNames
		0,//enabledExtentionCount
		NULL,//ppEnabledExtensionNames
	};


	/*PFN_vkVoidFunction myVCI = vkGetInstanceProcAddr(
		NULL,
		"vkCreateInstance"
	);

	VkResult r = (VkResult (*)(
		const VkInstanceCreateInfo* pCreateInfo,
		const VkAllocationCallbacks* pAllocator,
		VkInstance*
	))myVCI(*/
	VkResult r = vkCreateInstance(
		&vkici,
		NULL,
		&vki
	);

	if(r != VK_SUCCESS){
		printf("FUCK\n");
	}else{
		uint32_t v = 0;
		vkEnumerateInstanceVersion(&v);
		printf("Vulkan API Version %d.%d.%d\n", VK_VERSION_MAJOR(v), VK_VERSION_MINOR(v), VK_VERSION_PATCH(v));
	}

	vkDestroyInstance(
		vki,
		NULL
	);

	return 0;
}
