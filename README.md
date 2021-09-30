# MoogVCF
A virtual analog filter that models the nonlinearities of the Moog ladder filter.  The implementation is based on the following paper
by Vesa Välimäki and Antti Huovilainen - https://direct.mit.edu/comj/article/30/2/19/94705/Oscillator-and-Filter-Algorithms-for-Virtual

The filter does not require any dependencies and should fit seamlessly into any C++ audio application.

How to use the filter:

    // Moog filter object
    MoogVCF moogVCF;
    
    float filterType = four_pole_low_pass;
	  moogVCF.set_filter_type(filterType);
    
    // Calculate new filter coefficients
	  moogVCF.calculate_coefficients(audioSampleRate, filterCutoff, resonance);
    
    float out = moogVCF.process(in);
