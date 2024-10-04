#ifndef RANDOM_HPP
#define RANDOM_HPP

class SampleBoxMuller
{
public:
    // Constructor (default) and Destructor
    SampleBoxMuller() {}
    ~SampleBoxMuller() {}

    // Function to generate a random number based on the Box-Muller transform
    double operator()() const;  // Overloaded operator to call the function directly
};

#endif // RANDOM_HPP
