/*
 * windefs.c: default settings that are specific to Windows.
 */

#include "putty.h"

#include <commctrl.h>

static size_t major_os_version_number() {
    OSVERSIONINFO versioninfo;
    versioninfo.dwOSVersionInfoSize = sizeof(OSVERSIONINFO);
    GetVersionEx(&versioninfo);
	return versioninfo.dwMajorVersion;
}

FontSpec *platform_default_fontspec(const char *name)
{
    if (!strcmp(name, "Font")) {
		if (major_os_version_number() < 6)
	        return fontspec_new("Courier New", false, 10, ANSI_CHARSET);
        return fontspec_new("Consolas", false, 12, ANSI_CHARSET);
    } else
        return fontspec_new("", false, 0, 0);
}

Filename *platform_default_filename(const char *name)
{
    if (!strcmp(name, "LogFileName"))
        return filename_from_str("putty.log");
    else
        return filename_from_str("");
}

char *platform_default_s(const char *name)
{
    if (!strcmp(name, "SerialLine"))
        return dupstr("COM1");
    return NULL;
}

bool platform_default_b(const char *name, bool def)
{
    return def;
}

int platform_default_i(const char *name, int def)
{
    /*if (!strcmp(name, "FontQuality") && major_os_version_number() >= 6)
        return FQ_CLEARTYPE;*/
    return def;
}
