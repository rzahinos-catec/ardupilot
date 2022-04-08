#include "mode.h"
#include "Plane.h"

bool ModeFBWB::_enter()
{
#if HAL_SOARING_ENABLED
    // for ArduSoar soaring_controller
    plane.g2.soaring_controller.init_cruising();
#endif

    plane.set_target_altitude_current();

    return true;
}

void ModeFBWB::update()
{


    // Thanks to Yury MonZon for the altitude limit code!
    //Get roll reference from RC
    // plane.nav_roll_cd = plane.channel_roll->norm_input() * plane.roll_limit_cd;
    
    // Get roll reference from companion computer
    plane.calc_nav_roll();

    plane.update_load_factor();
    plane.update_fbwb_speed_height();

}

