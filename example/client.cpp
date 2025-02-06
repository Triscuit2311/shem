
#include "../shem.hpp"
#include "model.hpp"

int main(){

    shem::shared_memory_obj<model::server_settings> shm_out(L"SHM_SERVER_SETTINGS");
    shem::shared_memory_obj<model::client_settings> shm_in(L"SHM_CLIENT_SETTINGS");

    while (true)
	{   
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));

        {
            shm_in.read(&model::g_client_settings); // Update from server
            // Use g_client_settings fields here
        }


        {
            // Set server fields
            strcpy_s((char*)&model::g_server_settings.some_str, 128, "HONKYTONKY");
            shm_out.write(&model::g_server_settings); // Send update to server
        }
    }
}