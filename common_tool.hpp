#include <iostream>
#include <vector>
#include <map>

/* get the mbr from a points vector
 * @param points double vector of points
 * return mbr[0]:low bound, mbr[1]:up bound
 */
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

/* println a vector for debug
 * @param v a vecfor to print
 */
template <typename T>
void put_vector(const std::vector<T> &v)
{
  for(auto element : v){
    std::cout << element << ", ";
  }
  std::cout << std::endl;
}

/* compute inner product of two vector
 *
 */
template <typename T>
T inner_product(const std::vector<T> &a, const std::vector<T> &b)
{
  T result = 0;
  for(int i = 0; i < a.size();i++)
    result += a[i] * b[i];
  return result;
}


/* update a buffer of map
 */
template <typename KEY, typename VALUE>
void update_buffer(std::multimap<KEY,VALUE> &buffer, KEY key, VALUE value)
{
  buffer.insert(std::pair<KEY,VALUE>(key,value));
  buffer.erase(std::prev( buffer.end() ));
}


