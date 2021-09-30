/***** MoogVCF.h *****/
#include "FirstOrderFilter.h"
#include <cmath>
#include <array>
#include <vector>
#include <libraries/math_neon/math_neon.h>

class MoogVCF {
public:
    MoogVCF();
    float process(float in);
    void calculate_coefficients(float sampleRate, float frequencyHz, float resonance);
    void set_filter_type(int type);
private:
    // Coefficients (probably don't need to be initialized here.)
    float a1 = 0.0f;
    float b0 = 0.0f;
    float b1 = 0.0f;
    float g  = 0.0f;
    
    std::vector<FirstOrderFilter> filters;
    
    // Fixed by design
    const float gComp = 0.5f;
    float gRes = 0.75f;
    
    float delayed_filter_output = 0.0f;

    // Using an enum to improve readability
    enum filter_type { two_pole_low_pass,  four_pole_low_pass,
                       two_pole_band_pass, four_pole_band_pass,
                       two_pole_high_pass, four_pole_high_pass };
                    
    filter_type filter_t = four_pole_low_pass;
    
    std::array<std::array<float, 5>, 6> filter_weights;
};