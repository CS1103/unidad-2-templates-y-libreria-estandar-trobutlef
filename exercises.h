//
// Created by rudri on 10/18/2020.
//

#ifndef POO2_UNIT2_WEEK_7_2020_2_EXERCISES_H
#define POO2_UNIT2_WEEK_7_2020_2_EXERCISES_H

#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <list>
#include <string>
#include <sstream>
#include <deque>
#include<forward_list>
#include <initializer_list>
#include <tuple>
using namespace std;



//#2
// -> deque (Double Ended Queue)
// ->forward_list -> single linked list 

//using deque, forward_list, list from STL 
// forward_list does not have push_back()
//container -> deque<int>

//this is not for forward_list<T>;
//value -> # containers
template <typename container>
vector<container> split_range(container v, int value) {
  vector<container> ans;
  auto b_iter = v.begin();
  auto e_iter = v.end();
  
  auto sz = distance(b_iter, e_iter);//5
  auto elements_per_sub_ranges = sz/value;//1
  auto residuo_sub_ranges = sz % value;//1  //remainder of sz and value to evaluate if thereis an extra element in the last vector

  auto itr_b_ans = ans.begin();
  auto itr_e_ans = ans.end();  
  container temp;  
  for (int i = 0; i < value;i++){
    for(int j=0; j<elements_per_sub_ranges;j++) {
      temp.push_back(*b_iter); // temp es de tipo any container -> deque, list
      b_iter++;
      if(i==value -1 && j==elements_per_sub_ranges-1 && residuo_sub_ranges > 0){
          temp.push_back(*b_iter);
      }
      
    }
    
    ans.push_back(temp);
    temp.clear();
    itr_b_ans++;
  }
 
  return ans;
}


vector<forward_list<int>> split_range(forward_list<int> v, int value) {

  vector<forward_list<int>> ans;        
  auto b_iter = v.begin();
  auto e_iter = v.end();
  
  auto sz = distance(b_iter, e_iter);
  auto elements_per_sub_ranges = sz/value;
  auto residuo_sub_ranges = sz % value;  

  auto itr_b_ans = ans.begin();
  auto itr_e_ans = ans.end();  
  forward_list<int> temp;  
 
  for (int i = 0; i < value;i++){
    for(int j=0; j<elements_per_sub_ranges;j++) {
      temp.push_front(*b_iter); // temp es de tipo any container -> deque, list
      b_iter++;
      if(i==value -1 && j==elements_per_sub_ranges-1 && residuo_sub_ranges !=0){
          temp.push_front(*b_iter);
      }
    }
    temp.reverse();
    ans.push_back(temp);
    temp.clear();
    itr_b_ans++;
  }

  return ans;
}

//#3
template <typename U>
vector<int> sum_range(U l1, U l2){
    vector<int> ans;
   
    int sz =0 ;
    for (auto b = l1.begin(); b!= l1.end(); b++) {
        sz++;
    }
    
    auto itr = l1.begin(), ptr = l2.begin();
    for(int i=0;i<sz;i++){
        ans.push_back(*itr + *ptr);
        itr++;
        ptr++;
        if(ptr == l2.end()){
            ptr= begin(l2);
        }
    }
  
    return ans;
}
//#4
template <typename T,typename U>
T delete_range(T l1, U l2) { //initializer_list<int>
    auto itr = l1.begin();
    while (itr!=l1.end()){
        if(*itr==l2) {
            l1.erase(remove(l1.begin(),l1.end(), *itr), l1.end());
        }
        itr++;
    }
    return l1;
}
template <typename T>
T delete_range(T l1, initializer_list<int> l2) { //initializer_list<int>
    auto itr = l1.begin(), ptr = l2.begin();
    T ans;
    auto temp = ptr++;
    while (ptr!=l2.end()){
        while ( itr!=l1.end()) {
            if(*ptr!=*itr && *temp!=*itr) {
                ans.push_back(*itr);
            }
            itr++;
        }
        ptr++;
    }
    return ans;
}

//#5
template <typename T>
T delete_duplicated(T container) {
  T ans;
  bool is_true = true;
  auto itr = container.begin(), ptr = ans.begin();
  while (itr!=container.end()) {
      ptr = ans.begin();
      while(ptr!= ans.end()) {
          if(*ptr==*itr){
              is_true=false;
              break;
          }
          else {
              is_true = true;
          }
          ptr++;
      }
      if(is_true)
          ans.push_back(*itr);
      itr++;
  }
  return ans;
}
//#8
//we can use variadic templates for this approach
//http://www.cplusplus.com/articles/EhvU7k9E/


template <typename... Params>
tuple<Params&...> unpack(Params&... args) noexcept{
  return {args...};
}


//#11


template <template <typename> typename T, template<typename...> typename... Params>
T<vector<int>> zip (T<int> v, Params<int>... params) {
  T<vector<int>> ans;
  int sz = distance(v.begin(), v.end());
  
  for (int i = 0; i < sz; ++i) {
    vector<int> temp;
    
    int element_v = *(next(v.begin(), i));//this will insert the apporopiate value of each vector dependending on the position, so that it can work as a transpose matrix 
    temp.push_back(element_v);
    for (auto v_i : {params...}) { //this will get each vector 
      int element_each_vector = *(next(v_i.begin(), i));
      temp.push_back(element_each_vector);
    }
    ans.push_back(temp);
  }
  return ans;
}

#endif //POO2_UNIT2_WEEK_7_2020_2_EXERCISES_H