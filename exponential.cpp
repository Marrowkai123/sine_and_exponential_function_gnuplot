#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <string>

// Function to define the exponential function
double exponential_function(double x, double a, double b) {
  return a * std::exp(b * x);
}

int main() {
  // Parameters for the exponential function
  double a = 3;  // Coefficient
  double b = 2;  // Exponent

  // Range of x values for data generation
  double x_min = 0.0;
  double x_max = 5.0;
  int num_points = 100;

  // Generate x values
  std::vector<double> x(num_points);
  double dx = (x_max - x_min) / (num_points - 1);
  for (int i = 0; i < num_points; ++i) {
    x[i] = x_min + i * dx;
  }

  // Calculate y values using the exponential function
  std::vector<double> y(num_points);
  for (int i = 0; i < num_points; ++i) {
    y[i] = exponential_function(x[i], a, b);
  }

  // Open a text file for output
  std::ofstream outfile("output.txt");
  if (!outfile.is_open()) {
    std::cerr << "Error opening file: exponential_data.txt" << std::endl;
    return 1;
  }

  // Write x and y values to the file
  for (int i = 0; i < num_points; ++i) {
    outfile << x[i] << " " << y[i] << std::endl;
  }
  outfile.close();

  return 0;
}
