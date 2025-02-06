
#include "../shem.hpp"
#include "model.hpp"

int main(){

    shem::shared_memory_obj<model::client_settings> shm_out(L"SHM_CLIENT_SETTINGS");
    shem::shared_memory_obj<model::server_settings> shm_in(L"SHM_SERVER_SETTINGS");

    while (true)
	{   
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));

        {
            // Set client fields
            &g_client_settings.fooey.x = 123;
            shm_out.write(&model::g_client_settings); // Send update to client
        }


        {
            shm_in.read(&model::g_server_settings); // Update from client
            // Use g_server_settings client here
        }

    }
}