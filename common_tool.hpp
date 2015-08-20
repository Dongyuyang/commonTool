#include <iostream>
#include <algorithm>
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
      max[j] = std::max(max[j],points[i][j]);
      min[j] = std::min(min[j],points[i][j]);
    }
  }
  
  return {min,max};
}

/* get the mbr and expand to square*/
template <typename T>
std::vector<std::vector<T> > get_square_mbr(const std::vector<std::vector<T> > &points)
{
  std::vector<std::vector<T> > mbr = get_mbr(points);
  std::vector<T> diff(mbr[0].size());

  double max = 0;
  for(int i = 0; i < diff.size();i++){
    diff[i] = mbr[1][i] - mbr[0][i];
    max = std::max(diff[i],max);
  }
  std::vector<T> up;
  for(int i = 0; i < mbr[0].size();i++)
    up.push_back(mbr[0][i] + max);
    
  return {mbr[0],up};
}

/* distance of two points (vector)*/
template <typename T>
T distance_no_sqrt(const std::vector<T> &p1, const std::vector<T> &p2)
{
  double result = 0;
  for(int i = 0; i < p1.size();i++)
    result += (p2[i] - p1[i]) * (p2[i] - p1[i]);

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


