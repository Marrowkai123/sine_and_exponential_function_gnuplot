#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

int main() {
  // Parameters for the sine function
  double amplitude = 1.0;  // Amplitude of the sine wave
  double frequency = 2.0 * 0.5;  // Frequency in radians (adjust for desired period)

  // Range of x values for data generation
  double x_min = 0.0;
  double x_max = 10.0;  // Adjust for desired range
  int num_points = 100;

  // Generate x values
  std::vector<double> x(num_points);
  double dx = (x_max - x_min) / (num_points - 1);
  for (int i = 0; i < num_points; ++i) {
    x[i] = x_min + i * dx;
  }

  // Calculate y values using the sine function
  std::vector<double> y(num_points);
  for (int i = 0; i < num_points; ++i) {
    y[i] = amplitude * std::sin(frequency * x[i]);
  }

  // Open a text file for output
  std::ofstream outfile("sine_data.txt");
  if (!outfile.is_open()) {
    std::cerr << "Error opening file: sine_data.txt" << std::endl;
    return 1;
  }

  // Write x and y values to the file
  for (int i = 0; i < num_points; ++i) {
    outfile << x[i] << " " << y[i] << std::endl;
  }

  outfile.close();

  std::cout << "Data exported to sine_data.txt" << std::endl;

  return 0;
}
