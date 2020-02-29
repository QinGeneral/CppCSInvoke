#include "mono/jit/jit.h"
#include <mono/metadata/assembly.h>
#include <mono/metadata/class.h>
#include <mono/metadata/debug-helpers.h>
#include <mono/metadata/mono-config.h>

int main()
{
    // 初始化 Mono 运行时
    MonoDomain *domain = mono_jit_init("CppInvokeCS");
    // 配置 Mono 的位置和配置文件
    mono_set_dirs("/Library/Frameworks/Mono.framework/Home/lib", "/Library/Frameworks/Mono.framework/Home/etc");
    // 使用默认配置文件
    mono_config_parse(NULL);
    // 加载 CppInvokeCS.dll
    MonoAssembly *assembly = mono_domain_assembly_open(domain, "./CppInvokeCS.dll");
    MonoImage *image = mono_assembly_get_image(assembly);

    //获取 MonoClass
    MonoClass *main_class = mono_class_from_name(image, "CppInvokeCS", "Main");
    // 获取 MonoMethodDesc
    MonoMethodDesc *entry_point_method_desc = mono_method_desc_new("CppInvokeCS.Main:Log()", true);
    MonoMethod *entry_point_method = mono_method_desc_search_in_class(entry_point_method_desc, main_class);
    mono_method_desc_free(entry_point_method_desc);
    // 调用方法
    mono_runtime_invoke(entry_point_method, NULL, NULL, NULL);
    // 释放运行时
    mono_jit_cleanup(domain);
    return 0;
}