#pragma once

namespace model {

	struct server_settings
	{
		uint8_t some_str[128] = "";
        int a = 0;
        float b = 0.0f;
	} inline g_server_settings;

	struct client_settings
	{
		bool b = false;
		struct foo
		{
            int x = 0;
            float y = 0;
		} fooey;
	} inline g_client_settings;
}