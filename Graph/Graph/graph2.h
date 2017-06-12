#ifndef _GRAPH_H_
#define _GRAPH_H_

#include <vector>
#include <set>
#include <utility>
#include <fstream>
#include <iostream>
#include <memory>
using std::set;
using std::vector;
using std::pair;
using std::istream;
using std::ostream;
using std::shared_ptr;
namespace mystl {

template< typename VertexProperty, typename EdgeProperty>
  class graph {

  class vertex;
  class edge;
  public:
      ///required public types
      typedef size_t vertex_descriptor; //unique vertex identifier

      typedef pair<size_t, size_t> edge_descriptor; //unique edge identifier
                                                    //represents pair of vertex
                                                    //descriptors

      //vertex container should contain "vertex" and not "vertex*"
      typedef typename set<shared_ptr<vertex> >::iterator vertex_iterator; //vertex iterators
      typedef typename set<shared_ptr<vertex> >::const_iterator const_vertex_iterator;

      //edge container should contain "edge" and not "edge*"
      typedef typename set<shared_ptr<edge> >::iterator edge_iterator; //edge iterators
      typedef typename set<shared_ptr<edge> >::const_iterator const_edge_iterator;

      //adjacent edge container should contain "edge*" and not "edge"
      typedef typename set<shared_ptr<edge> >::iterator adj_edge_iterator; //adjacency list iterators
      typedef typename set<shared_ptr<edge> >::const_iterator const_adj_edge_iterator;

      ///required constructor/destructors
      graph(): vertex_counter(0) {}

      ~graph(){}

      graph(const graph&) = delete;
      graph& operator=(const graph&) = delete;

      ///required graph operations

      //iterators
      vertex_iterator vertices_begin() {return vertices.begin();}
      const_vertex_iterator vertices_cbegin() const {return  vertices.cbegin();}
      vertex_iterator vertices_end() {return vertices.end();}
      const_vertex_iterator vertices_cend() const {return vertices.cend();}

      edge_iterator edges_begin() {return edges.begin();}
      const_edge_iterator edges_cbegin() const {return edges.cbegin();}
      edge_iterator edges_end() {return edges.end();}
      const_edge_iterator edges_cend() const {return edges.cend();}

      //accessors
      size_t num_vertices() const {return vertices.size();}
      size_t num_edges() const {return edges.size();}

      vertex_iterator find_vertex(vertex_descriptor v_descriptor) {
        return vertices.find(vertex(v_descriptor, VertexProperty()));
      }

      const_vertex_iterator find_vertex(vertex_descriptor v_descriptor) const {
      	return vertices.find(vertex(v_descriptor, VertexProperty()));
      }

      edge_iterator find_edge(edge_descriptor e_descriptor) {
	       return edges.find(edge(e_descriptor.first, e_descriptor.second, EdgeProperty()));
      }

      const_edge_iterator find_edge(edge_descriptor e_descriptor) const {
       	return edges.find(edge(e_descriptor.first, e_descriptor.second, EdgeProperty()));
      }

      //modifiers
      vertex_descriptor insert_vertex(const VertexProperty& property) {
      	shared_ptr<vertex> tmp(new vertex(vertex_counter, property));
      	vertices.insert(tmp);
      	vertex_counter++;  // increment the counter for the indentification of vertices
      	return tmp->v_id; // the vertex_count will alway be 1 more then that created vertex
      }

      edge_descriptor insert_edge(vertex_descriptor v_src, vertex_descriptor v_dest, const EdgeProperty& property) {
      	shared_ptr<edge> tmp(new edge(v_src, v_dest, property));
      	edges.insert(tmp);
	      return tmp->e_id;
      }

      void insert_edge_undirected(vertex_descriptor v_src, vertex_descriptor v_dest, const EdgeProperty& property) {
        insert_edge(v_src, v_dest, property);
        insert_edge(v_dest, v_src, property);
      }

      void erase_vertex(vertex_descriptor v_descriptor) {
        auto iter = find_vertex(v_descriptor);
        iter->adj_edges.clear();
        if(iter != vertices.end()){
          vertices.erase(iter);
        }
      }

      void erase_edge(edge_descriptor e_descriptor) {
        auto iter = find_edge(e_descriptor);
        if(iter != edges.end()){
         edges.erase(iter);
        }
      }

      void clear(){
        vertices.clear();
        edges.clear();
        vertex_counter = 0;
      }

      template <typename V, typename E>
      friend istream& operator>>(istream& in, graph<V,E>& g) {

        int num_vertices, num_edges;
        in >> num_vertices >> num_edges;
        int v_counter = 0, e_counter = 0;
        E e_tmp;
        V v_tmp;
        vertex_descriptor d1, d2;
        while(v_counter < num_vertices){
          in >> v_tmp;
          g.insert_vertex(v_tmp);
          v_counter++;
        }
        while(e_counter < num_edges) {
          in >> d1 >> d2 >> e_tmp;
          g.insert_edge(d1 , d2, e_tmp);
          e_counter++;
        }

	      return in;
      }


      template <typename V, typename E>
      friend ostream& operator<<(ostream& out, const graph<V,E>& g) {
        out << g.num_vertices() << " " << g.num_edges() << std::endl;
        for(auto iter = g.vertices_cbegin(); iter != g.vertices_cend(); iter++ )
          out << iter->property() << std::endl;

        for(auto iter = g.edges_cbegin_cbegin(); iter != g.edges_cend(); iter++ )
          out << iter->source() << " " << iter->target() << " " << iter->property() << std::endl;

	      return out;
      }

    private:
      ///required internal classes
      set<shared_ptr<vertex>, std::less<vertex_descriptor> > vertices;
      set<shared_ptr<edge>, std::less<edge_descriptor> > edges;
      size_t vertex_counter;

      class vertex {
        public:
          ///required constructors/destructors
          vertex(vertex_descriptor vd, const VertexProperty& v): value(v), id(vd) {}

          ///required vertex operations
          VertexProperty& operator* () { return value; }

  	  bool isAdjacentTo() {
        return true;
      }

  	  edge_descriptor add_edge(shared_ptr<edge>& e) {
  	    adj_edges.insert(e);
  	    return e->id;
  	  }
            //iterators
      adj_edge_iterator begin() {return adj_edges.begin();}
      const_adj_edge_iterator cbegin() const {return adj_edges.cbegin();}
      adj_edge_iterator end() {return adj_edges.end();}
      const_adj_edge_iterator cend() const {return adj_edges.cend();}

      //accessors
      const vertex_descriptor descriptor() const { return id; }
      VertexProperty& property() { return value; }

      const VertexProperty& property() const { return value; }
    private:
	       VertexProperty value;
          const vertex_descriptor v_id;
          set<shared_ptr<edge> > adj_edges;
      };

      class edge {
        public:
          ///required constructors/destructors
      edge(vertex_descriptor v_src, vertex_descriptor v_dest, const EdgeProperty& property): weight(property), id(std::make_pair(v_src, v_dest))  {}

          //required edge operations
          // operator*
          // endVertices()
          // opposite(v)
          // isAdjacentTo(f)
          // isIncidentOn(v)

          //accessors
          const vertex_descriptor source() const {return id.first;}
          const vertex_descriptor target() const {return id.second;}
          const edge_descriptor descriptor() const {return id;}
          EdgeProperty& property() {return weight;}
          const EdgeProperty& property() const {return weight;}

        private:
    	  //std::pair<vertex*, vertex*> v_edge;
    	  //std::pair<vertex_descriptor, vertex_descriptor> v_edge;
        EdgeProperty weight;
    	  const edge_descriptor e_id;
     };
  };
}

#endif
