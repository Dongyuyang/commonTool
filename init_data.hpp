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

void normal_init(std::vector<std::vector<double> > &points, int dimension, double mu, double sigma, double lower_bound, double upper_bound)
{
  std::default_random_engine generator;
  std::normal_distribution<double> distribution(mu,sigma);
  // generator.
  
  for(int i = 0; i < points.size();i++){
    std::vector<double> v;
    for(int j = 0; j < dimension; j++){
      double value = distribution(generator);
      if(value > lower_bound && value < upper_bound)
	v.push_back(value);
      else
	j--;
    }
    points[i] = v;
  }  
}

void cluster_init(std::vector<std::vector<double> > &points, int dimension, double lower_bound, double upper_bound, double sigma)
{
  int center_num = 10;
  int each_num = points.size() / center_num;
  int current_index = 0;
  for(int i = 0; i < center_num; i++){
    double mu = get_rand(0.2,0.8);
    std::vector<std::vector<double> > sub_points(each_num);
    normal_init(sub_points,dimension,mu,sigma,lower_bound,upper_bound);
    for(int j = 0; j < sub_points.size(); j++){
      points[current_index] = sub_points[j];
      current_index++;
    }
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
  std::cout << path << std::endl;
  std::ifstream ifs("/Users/dse2015/Desktop/Research/ARKR/data/houseD6.csv");
  std::vector<double> v((std::istream_iterator<double>(ifs)), std::istream_iterator<double>());

  int num = 0;
  int count = 0;
  for(int i = 0; i < points.size();i++){
    for(int j = 0; j < dimension; j ++){
      if(v[num] > 10000)
	points[i].push_back(get_rand(0,1));
      else{
	count++;
	points[i].push_back(v[num]/10000);
      }
      num++;
    }
  }

  
  std::cout << "coount" << count << std::endl;
  
}

