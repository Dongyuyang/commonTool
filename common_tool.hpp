#include <vector>


template <typename T>
std::vector<std::vector<T> > get_mbr(const std::vector<std::vector<T> > &points)
{
  std::vector<T> max = points[0];
  std::vector<T> min = points[0];
  for(int i = 1; i < points.size(); i++){
    for(int j = 0; j < points[i].size(); j++){
      if(max[j] < points[i][j])
	max[j] = points[i][j];
      if(min[j] > points[i][j])
	min[j] = points[i][j];
    }
  }
  std::vector<std::vector<T> > result;
  result.push_back(min);
  result.push_back(max);
  return result;
}


