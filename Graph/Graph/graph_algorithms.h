////////////////////////////////////////////////////////////////////////////////
/// @brief Graph Algorithms, e.g., algorithms for graphs
/// @ingroup MySTL
////////////////////////////////////////////////////////////////////////////////

#ifndef _GRAPH_ALGORITHMS_H_
#define _GRAPH_ALGORITHMS_H_

#include <boost/heap/fibonacci_heap.hpp>
#include <utility>
#include <list>
#include <queue>
#include <iostream>

using namespace std;

namespace mystl {

//Here is an example list of the basic algorithms we will work with in class. I
//will add more as we go to the online version of this file.
//
//In general this is what the following template parameters are:
// - Graph - type of graph, literally your adjacency list graph
// - ParentMap - associative container between vertex_descriptors and parent
//               vertex_descriptors. This is a representation of the free
//               trees/forests created by these search methods
// - DistanceMap - associative container between vertex_descriptors and
//                 EdgeProperties. This represents the summation of the path
//                 weights to the vertex itself.
//
//Assume EdgeProperties can be added and compared with less than/less than or
//equal.
//
//Remember that every extra algorithm you implement can earn you bonus.
  
////////////////////////////////////////////////////////////////////////////////
/// @brief Depth First Search
/// @tparam Graph graph graph type
/// @tparam ParentMap constructed map type
/// @param g graph reference
/// @param p constructed map
template<typename Graph, typename ParentMap>
  void depth_first_search(const Graph& g, ParentMap& p);

////////////////////////////////////////////////////////////////////////////////
/// @brief Breadth First Search
/// @tparam Graph graph type
/// @tparam ParentMap constructed map type
/// @param g graph reference
/// @param p constructed map
///
/// Breadth first search will search all of the edges of a vertex before
/// traversing to another vertex. It will construct of map of parent vertex
/// descriptors and child vertex descriptors.
template<typename Graph, typename ParentMap>
  void breadth_first_search(const Graph& g, ParentMap& p) { // O(deg(v)nlogn)
  	typedef typename Graph::Label Label;
  	// typedef typename Graph::vertex_descriptor vertex_descriptor;
  	typedef typename Graph::vertex_iterator vertex_iterator;

  	//set labels for all vertices and edges to unvisited
  	for(auto it = g.vertices_cbegin(); it != g.vertices_cend(); it++) // O(n)
  		(*it)->setLabel(Label::UNVISITED);
  	for(auto it= g.edges_cbegin(); it != g.edges_cend(); it++) // O(m)
  		(*it)->setLabel(Label::UNVISITED);

  	list<vertex_iterator> v_list;
  	
  	v_list.push_back(g.vertices_cbegin());
  	vertex_iterator curr;
  	while(!v_list.empty()) { // will loop while there are vertex in the edge O(n)
  		curr = v_list.front();
  		v_list.pop_front();
  		(*curr)->setLabel(Label::VISITED);
  		
  		for(auto iter = (*curr)->cbegin();iter != (*curr)->cend();iter++){  // O(deg(v)logn)
  			if((*iter)->getLabel() == Label::UNVISITED) {
  				if((*iter)->source() == (*curr)->descriptor()) { // this is an outgoing edge
  					auto i = g.find_vertex((*iter)->target()); // this will get an iterator to the opposite vertex O(logn)
  					if((*i)->getLabel() == Label::UNVISITED){ // 1
  						(*iter)->setLabel(Label::DISCOVERED); // 1
  						(*i)->setLabel(Label::VISITED); // 1
  						v_list.push_back(i); // 1
  						p.insert(make_pair((*curr)->descriptor(),(*i)->descriptor())); // 1
  					}
  					else
  						(*iter)->setLabel(Label::CROSS);
  				} 
  			}
  		}	
  	}
  }

////////////////////////////////////////////////////////////////////////////////
/// @brief Prim Jarniks Minimum Spanning Tree Algorithm
/// @tparam Graph graph type
/// @tparam ParentMap constructed map type
/// @param g graph reference
/// @param p constructed map
///
/// Prim Jarniks constructs a miminum spanning tree as it traverses the graph.
/// Creating an association of parent vertexs to child vertexs which are
/// represented by the vertex descriptors of each.
template<typename Graph, typename ParentMap>
  void mst_prim_jarniks(const Graph& g, ParentMap& p) {
  	//select vertex to start from
  	auto&& vstart = g.find_vertex(0);
  	(*vstart)->setDistance(0);
  	(*vstart)->setParent(0);
      
  	//set all other vertices' distance values to infinity
  	auto&& i = g.vertices_cbegin();
  	++i;
  	for (; i != g.vertices_cend(); ++i) {
  	  (*i)->setDistance(std::numeric_limits<double>::infinity());
  	  (*i)->setParent(0);
  	}

  	//construct priority queue of vertex iterators
    //sorted by distance from cloud
  	boost::heap::fibonacci_heap<typename Graph::vertex_iterator, 
  	  boost::heap::compare<typename Graph::MSTCompare > > Q;

  	for (auto&& vi2 = g.vertices_cbegin(); vi2 != g.vertices_cend(); ++vi2)
  	  Q.push(vi2);
      
  	//remove vertex iterator with the smalles distance
  	//add to ParentMap along with its parent descriptor
  	while (!Q.empty()) {
  	  auto&& u = Q.top();
  	  Q.pop();
  	  p[(*u)->descriptor()] = (*u)->getParent();

  	  for (auto&& j = (*u)->cbegin(); j != (*u)->cend(); ++j) {
  	    auto&& z = g.find_vertex((*j)->target());
  	    if ((*j)->property() < (*z)->getDistance()) {
  	      (*z)->setDistance((*j)->property());
  	      (*z)->setParent((*j)->source());
	        //Q.update(s_handle_from_iterator(z), (*z)->getDistance());
  	    }
  	  }
    }
  }



template<typename Graph, typename ParentMap>
  void mst_kruskals(const Graph& g, ParentMap& p);

template<typename Graph, typename ParentMap, typename DistanceMap>
  void sssp_dijkstras(const Graph& g, ParentMap& p, DistanceMap& d);

template<typename Graph, typename ParentMap, typename DistanceMap>
  void sssp_bellman_ford(const Graph& g, ParentMap& p, DistanceMap& d);
}

#endif
