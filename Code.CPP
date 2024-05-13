#include <iostream>
#include <vector>
#include <cmath>


class TransferFunction {
private:
    std::vector<double> numeratorCoeffs;
    std::vector<double> denominatorCoeffs;

public:
    // Constructor
    TransferFunction(const std::vector<double>& numCoeffs, const std::vector<double>& denCoeffs)
        : numeratorCoeffs(numCoeffs), denominatorCoeffs(denCoeffs) {}

    // Evaluate the transfer function at a given frequency
    double evaluate(double frequency) const {
        double numeratorResult = 0.0;
        double denominatorResult = 0.0;

        // Evaluate the numerator polynomial
        for (int i = 0; i < numeratorCoeffs.size(); ++i) {
            numeratorResult += numeratorCoeffs[i] * std::pow(frequency, i);
        }

        // Evaluate the denominator polynomial
        for (int i = 0; i < denominatorCoeffs.size(); ++i) {
            denominatorResult += denominatorCoeffs[i] * std::pow(frequency, i);
        }

        // Return the ratio of the numerator and denominator results
        if (denominatorResult != 0.0) {
            return numeratorResult / denominatorResult;
        } else {
            // Handle division by zero (return infinity)
            return std::numeric_limits<double>::infinity();
        }
    }
};

int main() {
    // Example Transfer Function: H(s) = (s + 1) / (s^2 + 2s + 2)
    std::vector<double> numerator = {1, 1};      // s + 1
    std::vector<double> denominator = {1, 2, 2};  // s^2 + 2s + 2

    TransferFunction tf(numerator, denominator);

    // Evaluate the transfer function at frequency = 1 Hz
    double frequency = 1.0;
    double result = tf.evaluate(frequency);

    std::cout << "Transfer Function H(s) at frequency " << frequency << " Hz: " << result << std::endl;

    return 0;
}
