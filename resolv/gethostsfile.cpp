#include <string.h>
#include <netdb.h>
#include <sys/system_properties.h>

#include "gethostsfile.h"

const char* gethostsfile() {
       char hosts_setting[128];
       int prop_len = __system_property_get(QASSA_HOSTS_SETTING_PROP,
                                            hosts_setting);
	if (prop_len > 0 && strncmp(hosts_setting, "true", 5) == 0) {
		return QASSA_PATH_ADBLOCK_HOSTS;
	} else {
		return _PATH_HOSTS;
	}
}
