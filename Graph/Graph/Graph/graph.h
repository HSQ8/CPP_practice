#ifndef _GRAPH_H_
#define _GRAPH_H_

#include <utility>
#include <vector>
#include <set>
#include <iostream>

namespace mystl {

////////////////////////////////////////////////////////////////////////////////
/// @brief Graph ADT based on C++ map implemented with two sets
/// @ingroup MySTL
/// @tparam VertexProperty vertex value type
/// @tparam EdgeProperty edge weight type
////////////////////////////////////////////////////////////////////////////////

template<typename VertexProperty, typename EdgeProperty>
  class graph {

    //you have to forward declare these so you can use them in the public
    //section, when they are defined in the private section below. Essentially,
    //the compiler needs to know they exist in order to use them before the
    //definition of them.
    class vertex;       ///< Forward declared vertex class

    class edge;         ///< Forward declared edge class

    // ordering comparaters
    class vertex_comp;  ///< Forward declared vertex_commp comparator class
    class edge_comp;    ///< Forward declared edge_comp comparator class

    public:
      ///required public types
      ////////////////////////////////////////////////////////////////////////////
      /// @name Types
      /// @{
      typedef size_t vertex_descriptor; //unique vertex identifier

      typedef std::pair<size_t, size_t> edge_descriptor; //unique edge identifier
                                                    //represents pair of vertex
                                                    //descriptors
      //vertex container should contain "vertex*" or shared_ptr<vertex>
      typedef typename std::set<vertex*>::iterator vertex_iterator; ///< vertex iterators
      typedef typename std::set<vertex*>::const_iterator const_vertex_iterator;

      //edge container should contain "edge*" or shared_ptr<edge>
      typedef typename std::set<edge*>::iterator edge_iterator; ///< edge iterators
      typedef typename std::set<edge*>::const_iterator const_edge_iterator;

      //adjacent edge container should contain "edge*" or shared_ptr<edge>
      typedef typename std::set<edge*>::iterator adj_edge_iterator; //< adjacency list iterators
      typedef typename std::set<edge*>::const_iterator const_adj_edge_iterator;

      //Label for BFS
      enum Label {VISITED=0, UNVISITED, DISCOVERED, CROSS, BACK}; ///< enum values BFS vertex and edge labels

      /// @}
      ////////////////////////////////////////////////////////////////////////////

      ///required constructor/destructors

      ////////////////////////////////////////////////////////////////////////////
      /// @name Constructors
      /// @{

      /// @brief Constructor
      graph() : v_count(0) {}

      /// @brief Destructor
      ~graph() {}

      /// @brief Copy Constructor
      graph(const graph&) = delete;

       /// @brief Assignment operator
      graph& operator=(const graph&) = delete;
      /// @}
      ////////////////////////////////////////////////////////////////////////////

      ///required graph operations

      ////////////////////////////////////////////////////////////////////////////
      /// @name Iterators
      /// @{

      //iterators
      // @return Iterator to beginning of vertices
      vertex_iterator vertices_begin() {return vertex_set.begin();}
      // @return Iterator to constant beginning of vertices
      const_vertex_iterator vertices_cbegin() const {return vertex_set.cbegin();}
      // @return Iterator to end of vertices
      vertex_iterator vertices_end() {return vertex_set.end();}
      // @return Iterator to constant end of vertices
      const_vertex_iterator vertices_cend() const {return vertex_set.cend();}


      // @return Iterator to beginning of edges
      edge_iterator edges_begin() {return edge_set.begin();}
      // @return Iterator to constant beginning of edges
      const_edge_iterator edges_cbegin() const {return edge_set.cbegin();}
      // @return Iterator to end of edges
      edge_iterator edges_end() {return edge_set.end();}
      // @return Iterator to constant end of edges
      const_edge_iterator edges_cend() const {return edge_set.cend();}

      /// @}
      ////////////////////////////////////////////////////////////////////////////

      //accessors
      /// @return number of vertices
      size_t num_vertices() const {return vertex_set.size();}

      /// @return number of edges
      size_t num_edges() const {return edge_set.size();}

      //the find operations create a new object to pass to sest's find operation

      ////////////////////////////////////////////////////////////////////////////
      /// @name Entity Location
      /// @{

      /// @param vd vertex descriptor
      /// @return iterator to given vertex descriptor
      ///
      /// If \c vd matches any of the entities in the vertex set then it return an
      /// iterator to the location in the sets
      ///
      /// If \c vd is not found then an iterator to the end of the set will be returned
      vertex_iterator find_vertex(vertex_descriptor vd) {
        vertex v = vertex(vd, VertexProperty());
        auto&& i = vertex_set.find(&v);
        return i;
      }

      /// @param vd vertex descriptor
      /// @return iterator to given vertex descriptor
      ///
      /// If \c vd matches any of the entities in the vertex set then it return an
      /// iterator to the location in the sets
      ///
      /// If \c vd is not found then an iterator to the end of the set will be returned
      const_vertex_iterator find_vertex(vertex_descriptor vd) const {
        vertex v = vertex(vd, VertexProperty());
        auto&& i = vertex_set.find(&v);
        return i;
      }

      /// @param ed edge descriptor
      /// @return iterator to given edge descriptor
      ///
      /// If \c vd matches any of the entities in the edge set then it return an
      /// iterator to the location in the sets
      ///
      /// If \c vd is not found then an iterator to the end of the set will be returned
      edge_iterator find_edge(edge_descriptor ed) {
        edge e = edge(ed.first, ed.second, EdgeProperty());
        auto&& i = edge_set.find(&e);
        return i;
      }

      /// @param ed edge descriptor
      /// @return iterator to given edge descriptor
      ///
      /// If \c vd matches any of the entities in the edge set then it return an
      /// iterator to the location in the sets
      ///
      /// If \c vd is not found then an iterator to the end of the set will be returned
      const_edge_iterator find_edge(edge_descriptor ed) const {
        edge e = edge(ed.first, ed.second, EdgeProperty());
        auto&& i = edge_set.find(&e);
        return i;
      }
      /// @}
      ////////////////////////////////////////////////////////////////////////////


      ////////////////////////////////////////////////////////////////////////////
      /// @name Modifiers
      /// @{
      //modifiers
      //Insert operations create new object and use set's insert operation
      //Also increments the global vertex descriptor count

      /// @brief Insert a vertex into the graph with value v
      /// @param v value of the vertex
      /// @return the vertex descriptor the vertex inserted
      vertex_descriptor insert_vertex(const VertexProperty& v) {
        //vertex_descriptor descriptor = v_count;
        vertex* vert = new vertex(v_count, v);
        vertex_set.insert(vert);
        ++v_count;
        return vert->descriptor();
      }

      //Insert edge also inserts the edge into its vertices' adjacent edge sets

      /// @brief Insert an edge into the graph with weight e
      /// @param vd1 vertex descriptor of the source vertex
      /// @param vd2 vertex descriptor of the target vertex
      /// @return the edge descriptor the edge inserted
      edge_descriptor insert_edge(const vertex_descriptor vd1, const vertex_descriptor vd2, const EdgeProperty& e) {
        edge* edg = new edge(vd1, vd2, e);
        edge_set.insert(edg);

        vertex_iterator vi1 = find_vertex(vd1);
        vertex_iterator vi2 = find_vertex(vd2);
        if(vi1 != vertex_set.end() && vi2 != vertex_set.end()) {
	  (*vi1)->data().insert(edg);
	  (*vi2)->data().insert(edg);
        }
        return edg->descriptor();
      }

      //insert edge undirected inserts two direted edges in opposite directions
      /// @brief Insert an  undirected edge into the graph with weight e
      /// @param vd1 vertex descriptor of the source vertex
      /// @param vd2 vertex descriptor of the target vertex
      ///
      /// inserted two directed edges with swapped source and target vertex descriptors
      void insert_edge_undirected(const vertex_descriptor vd1, const vertex_descriptor vd2, const EdgeProperty& e) {
        insert_edge(vd1, vd2, e);
        insert_edge(vd2, vd1, e);
      }

      /*
        processes of the erase_vertex
        1. finds the vertex
        2. iterates through the set of adgacent edges and erasing the edge in other vertices
        3. erases the vertex
      */

      /// @brief erases a vertex from the graph
      /// @param vd vertex descriptor of vertex being erased
      ///
      /// erases any edge that is going to and from the vertex
      /// it must erase the edges in an opposite vertex's adjacent edge set
      void erase_vertex(const vertex_descriptor vd) {
        vertex_iterator vi = find_vertex(vd);
        if (vi != vertices_end()) {
          for(auto&& iter = (*vi)->begin(); iter != (*vi)->end(); iter++){
            if((*iter)->source() == vd )
              (*find_vertex((*iter)->target()))->data().erase(*iter);
            else if((*iter)->target() == vd)
              (*find_vertex((*iter)->source()))->data().erase(*iter);
            edge_set.erase((*iter));
          }
          vertex_set.erase(*vi);
        }
      }

      //erase edge first finds the edge, then removes it from any the adjancent edge sets it is in
      //finally removes edge from the edge set
      /// @brief Erase an edge from the graph
      /// @param ed edge descriptor of the edge begin erased
      ///
      /// removes the edge from both target and source adjacency edge set
      void erase_edge(const edge_descriptor ed) {
        edge_iterator ei = find_edge(ed);
        if (ei != edges_end()) {
          (*find_vertex((*ei)->source()))->data().erase(*ei);
          (*find_vertex((*ei)->target()))->data().erase(*ei);
          edge_set.erase(ei);
        }
      }

      /// @}
      ////////////////////////////////////////////////////////////////////////////


      void clear() {
        v_count = 0;
        vertex_set.clear();
        edge_set.clear();
      }

      //functions to input data
      //reads in num_vertices and num_edges first
      //then a list of vertices followed by a list of edges
      /// @brief input operator
      /// @param is input stream
      /// @param g graph
      /// @return input stream
      template<typename V, typename E>
        friend std::istream& operator>>(std::istream& is, graph<V, E>& g) {
        	size_t num_vertices;
        	size_t num_edges;
        	V v;
        	vertex_descriptor vd1;
        	vertex_descriptor vd2;
        	E e;
          is >> num_vertices >> num_edges;
        	for (size_t vd = 0; vd < num_vertices; ++vd) {
        		is >> v;
        		g.insert_vertex(v);
        	}

        	for (size_t ed = 0; ed < num_edges; ++ed) {
        		is >> vd1 >> vd2 >> e;
        		g.insert_edge(vd1, vd2, e);
        	}

        	return is;
        }

      //operation to print a graph
      /// @brief output operator
      /// @param is output stream
      /// @param g graph
      /// @return output stream
      template<typename V, typename E>
        friend std::ostream& operator<<(std::ostream& os, const graph<V, E>& g) {
          os << g.num_vertices() << " " << g.num_edges() << std::endl;
          for (const_vertex_iterator vi = g.vertices_cbegin(); vi != g.vertices_cend(); ++vi)
            os << (*vi)->property() << std::endl;

          for (const_edge_iterator ei = g.edges_cbegin(); ei != g.edges_cend(); ++ei)
            os << (*ei)->source() << " " << (*ei)->target() << " "
                << (*ei)->property() << std::endl;

          return os;
        }

      /// @brief Label class used by MST_prim_jarniks
      /// stores a distance and vertex descriptor for the parent
      class MSTLabel {
        public:
          double distance; //< D[v], the distance from a vertex to the cloud
          size_t parent; //< Parent vertex descriptor
        };

      /// @brief Compare class used by MST_prim_jarniks
      /// compares distance from cloud of two vertex iterators
      class MSTCompare {
        public:
          /// @brief compararator operator
          /// @param v vertex iterator
          /// @param u vertex iterator
          /// @return if the distance of v is less than the distance of u
          bool operator() (const_vertex_iterator v, const_vertex_iterator u) const {
            return (*v)->getDistance() < (*u)->getDistance();
          }
        };



    private:

      ///required internal classes

      //global count for vertex descriptor
      vertex_descriptor v_count; //< vertex counter

      //containers for vertices and edges
      std::set<vertex*, vertex_comp > vertex_set; //< set of vertices using vertex_comp to order
      std::set<edge*, edge_comp> edge_set; //< set of edges using edge_comp to order the edges


      ////////////////////////////////////////////////////////////////////////////////
      /// @brief Vertex Internal  structure for the graph
      ////////////////////////////////////////////////////////////////////////////////
      class vertex {
        public:
          ///required constructors/destructors

          ////////////////////////////////////////////////////////////////////////
          /// @name Constructors
          /// @{

          /// @brief Constructor
          /// @param descriptor vertex descriptor
          /// @param v value of vertex
          vertex(vertex_descriptor descriptor, const VertexProperty& v)
            : vdescriptor(descriptor), value(v) {}

          /// @}
          ////////////////////////////////////////////////////////////////////////////

          ///required vertex operations

          //iterators
          ////////////////////////////////////////////////////////////////////////
          /// @name Iterators
          /// @{
          // @return Iterator to beginning of adjacent edges
          adj_edge_iterator begin() {return adj_edge_set.begin();}
          const_adj_edge_iterator cbegin() const {return adj_edge_set.cbegin();}
          // @return Iterator to end of adjacent eges
          adj_edge_iterator end() {return adj_edge_set.end();}
          const_adj_edge_iterator cend() const {return adj_edge_set.cend();}

          /// @}
          ////////////////////////////////////////////////////////////////////////////

          ////////////////////////////////////////////////////////////////////////
          /// @name Accessors
          //accessors

          /// @brief gets descriptor
          /// @return vertex desciptor of vertex
          const vertex_descriptor descriptor() const {return vdescriptor;}
          /// @brief gets value of the vertex
          /// @return value of vertex
          VertexProperty& property() {return value;}
          const VertexProperty& property() const {return value;}
          /// @}
          ////////////////////////////////////////////////////////////////////////////

          ////////////////////////////////////////////////////////////////////////
          /// @name Helper
          /// @{
          // meant to be only used with in the graph

          /// @brief gets a reference of the adjacency edge
          /// @return referenct to acjacent edge set
          std::set<edge*, edge_comp>& data() {return adj_edge_set;}

          // for completeness

          /// @brief degree of vertex
          /// @return size of the adjacency set
          size_t degree() {return adj_edge_set.size();}

          // algorithms functions
          /// @brief gets label of  vertex
          /// @return label of the vertex
          Label getLabel(){return label;}

          /// @brief changes the label of vertex
          /// @param the label of the vertex
          void setLabel(Label l) {label = l;}

          /// @brief sets the distance of the vertex
          /// @param d distance
          /// @return distance
          double setDistance(double d) {
            l.distance = d;
            return d;
          }

          /// @brief sets the parent vertex of this vertex
          /// @param v vertex descriptor of the parent vertex
          /// @return vertex descriptor of the parent vertex
          vertex_descriptor setParent(vertex_descriptor v) {
            l.parent = v;
            return v;
          }

          /// @brief gets the distance
          /// @return distance
          double getDistance() {return l.distance;}
          /// @brief gets the parent vertex
          /// @return vertex descriptor of parent vertex
          vertex_descriptor getParent() {return l.parent;}
          /// @}
          ////////////////////////////////////////////////////////////////////////////


        private:
          Label label; //<  label of vertex for BFS and DFS
          const vertex_descriptor vdescriptor; //< vertex descriptor an indentifier for the vertex
          VertexProperty value; //< value of the vertex
          std::set<edge*, edge_comp> adj_edge_set; //< adjacency edge set
          MSTLabel l; //< label for the mst algorithm
      };


      ////////////////////////////////////////////////////////////////////////////////
      /// @brief edge Internal  structure for the graph
      ////////////////////////////////////////////////////////////////////////////////

      class edge {
        public:
          ///required constructors/destructors
          ////////////////////////////////////////////////////////////////////////////
          /// @name Constructors
          /// @{

          /// @brief edge constructor
          /// @param v_i source vertex descriptor
          /// @param v_j target vertex descriptor
          // @param e edge weight
          edge(vertex_descriptor v_i, vertex_descriptor v_j, const EdgeProperty& e)
            : weight(e), ed(std::make_pair(v_i, v_j)) {}

          ///required edge operations
          /// @}
          ////////////////////////////////////////////////////////////////////////////

          //accessors
          ////////////////////////////////////////////////////////////////////////////
          /// @name Accessors
          /// @{

          /// @brief gets the source vertex descriptor
          /// @return vertex descriptor of the source in the edge
          const vertex_descriptor source() const {return ed.first;}

          /// @brief gets the target vertex descriptor
          /// @return vertex descriptor of the target in the edge
          const vertex_descriptor target() const {return ed.second;}

          /// @brief gets the edge descriptor
          /// @return edge descriptor of the edge
          const edge_descriptor descriptor() const {return ed;}

          /// @brief gets the weight of the edge
          /// @return weight value of the edge
          EdgeProperty& property() {return weight;}
          const EdgeProperty& property() const {return weight;}

          // algorithm functions

          /// @brief gets label
          /// @return label value of edge
          Label getLabel(){return label;}

          /// @brief sets the label
          /// @param label of the edge
          void setLabel(Label l) {label = l;}

          /// @}
          ////////////////////////////////////////////////////////////////////////////

        private:
          EdgeProperty weight; //< weight of the edge
          const edge_descriptor ed; //< edge descriptor
          Label label; //< label of the edge
      };


      //comparator classes used in std::set to sort the set by the object's descriptor(s)

      // @brief vertex comparator for the vertex set
      class vertex_comp {
      public:
        // @brief compararator operator
        /// @param f vertex pointer
        /// @param s vertex pointer
        /// @return if the descriptor of f is less than the descriptor of s
        bool operator() (const vertex* f,const vertex* s) const {
          return f->descriptor() < s->descriptor();
        }
      };

      /// @brief edge comparater for the edge set
      class edge_comp {
        public:
          // @brief compararator operator
          /// @param f edge pointer
          /// @param s edge pointer
          /// @return if the descriptor of f is less than the distance of s
          bool operator() (const edge* f, const edge* s) const {
            return f->descriptor() < s->descriptor();
          }
      };
  };
}

#endif
