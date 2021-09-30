# MoogVCF
A virtual analog filter that models the nonlinearities of the Moog ladder filter.  The implementation is based on the following paper
by Vesa Välimäki and Antti Huovilainen - https://direct.mit.edu/comj/article/30/2/19/94705/Oscillator-and-Filter-Algorithms-for-Virtual

The filter does not require any dependencies and should fit seamlessly into any C++ audio application.

How to use the filter:

    // Moog filter object
    MoogVCF moogVCF;
    
    float filterCutoff = 1000.0f;
    float filterResonance = 0.9f;
    
    // Calculate new filter coefficients
	  moogVCF.calculate_coefficients(audioSampleRate, filterCutoff, filterResonance);
    
    float out = moogVCF.process(in);
    

An interesting property of this filter is that for resonance values greater than 1 it begins to self-oscillate.
