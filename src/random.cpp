#include "random.h"

  RandomNumbers::RandomNumbers(unsigned long int s)
  :seed(s)
  {
	  if (s==0){
		std::random_device rd;
		seed = rd();
	  }
	  rng=std::mt19937(seed);
  }

  void RandomNumbers::uniform_double(std::vector<double>& vec, double lower, double upper){
	  
	  std::uniform_real_distribution<double> unif_dist(lower,upper);
	  for (size_t i(0); i < vec.size(); ++i){
	   vec[i] = unif_dist(rng);
	  }
  }
  
  double RandomNumbers::uniform_double(double lower, double upper){
	  
	  std::uniform_real_distribution<double> unif_dist(lower,upper);
	  return unif_dist(rng);
  }
  
  void RandomNumbers::normal(std::vector<double>& vec, double mean, double sd){
	for (size_t i(0); i < vec.size(); ++i){
	  std::normal_distribution<double> norm_dist(mean,sd);
	  vec[i] = norm_dist(rng);
    }
  }
  
  double RandomNumbers::normal(double mean, double sd){
	  
	   std::normal_distribution<double> norm_dist(mean,sd);
	   return norm_dist(rng);
  }
  
  void RandomNumbers::poisson(std::vector<int>& vec, double mean){
	  for (size_t i(0); i < vec.size(); ++i){
		std::poisson_distribution<int> poiss_dist(mean);
		vec[i] = poiss_dist(rng);
	  }
  }
  
  int RandomNumbers::poisson(double mean){
	   std::poisson_distribution<int> poiss_dist(mean);
	   return poiss_dist(rng);
  }





