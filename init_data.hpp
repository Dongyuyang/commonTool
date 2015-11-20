/*init data 2015.08.23 dyy*/
#include <time.h>
#include <stdlib.h>
#include <vector>
#include <math.h>
#include <random>
#include <string>
#include <fstream>
#include <sstream>

/*get a rand double value*/
double get_rand(double lower_bound, double upper_bound)
{
  std::uniform_real_distribution<double> unif(lower_bound, upper_bound);
  std::random_device rand_dev;          // Use random_device to get a random seed.
  std::mt19937 rand_engine(rand_dev()); // mt19937 is a good pseudo-random number
  // generator.
  return unif(rand_engine);
}

/*Uniform distribution data*/
void randinit(std::vector<std::vector<double> > &points, int dimension, double lower_bound, double upper_bound)
{
  std::uniform_real_distribution<double> unif(lower_bound, upper_bound);

  std::random_device rand_dev;          // Use random_device to get a random seed.
  std::mt19937 rand_engine(rand_dev()); // mt19937 is a good pseudo-random number
  // generator.

  for(int i = 0; i < points.size();i++){
    std::vector<double> v;
    for(int j = 0; j < dimension; j++)
      v.push_back(unif(rand_engine));
    points[i] = v;
  }  
}

// sum = 1
void randinit_w(std::vector<std::vector<double> > &points, int dimension, double lower_bound, double upper_bound)
{
  std::uniform_real_distribution<double> unif(lower_bound, upper_bound);

  std::random_device rand_dev;          // Use random_device to get a random seed.
  std::mt19937 rand_engine(rand_dev()); // mt19937 is a good pseudo-random number
  // generator.

  for(int i = 0; i < points.size();i++){
    std::vector<double> v(dimension);
    double sum = 0.0;
    for(int j = 0; j < dimension; j++){
      v[j] = (unif(rand_engine));
      sum += v[j];
    }

    double unit = 1.0 / sum;
    sum = 0;
    for(int j = 0; j < dimension; j++){
      v[j] *= unit;
      sum += v[j];
    }
    points[i] = v;
  }  
}

/*read data from file*/
void read_point_file(std::vector<std::vector<double> > &points, int dimension, std::string path)
{
  std::ifstream ifs( path );
  std::vector<double> v((std::istream_iterator<double>(ifs)), std::istream_iterator<double>());

  int num = 0;
  for(int i = 0; i < points.size();i++){
    for(int j = 0; j < dimension; j ++){
      points[i].push_back(v[num++]);
    }
  }
}

