#include "graph.h"
#include "unit_test.h"
#include <fstream>
#include "graph_algorithms.h"
#include <unordered_map>

using namespace std;
using mystl::graph;
////////////////////////////////////////////////////////////////////////////////
/// @brief Testing of graph
/// @ingroup Testing
////////////////////////////////////////////////////////////////////////////////

class graph_test : public test_class {

  protected:

    void test() {

      test_file_input();

      test_find_vertex();

      test_find_edge();

      test_insert_vertex();

      test_insert_edge();

      test_insert_edge_undirected();

      test_erase_vertex();

      test_breadth_first_search();

      test_erase_edge();

      test_clear();

      test_mst_prim_jarniks();
    }

  private:
    /// @brief sets up test graph
    void setup_dummy_graph(graph<int, int>& g) {
      g.insert_vertex(1);
      g.insert_vertex(2);
      g.insert_vertex(3);
      g.insert_vertex(4);
      g.insert_edge(0, 1, 1);
      g.insert_edge(1, 2, 2);
      g.insert_edge(2, 3, 3);
      g.insert_edge(0, 3, 4);
    }
    
    /// @brief sets up larger test graph
    void setup_larger_dummy_graph(graph<int, int>& g) {
      for(size_t i = 0; i < 200; i++){
        g.insert_vertex(i);
      }
      size_t i = 1;
      for(auto vi1 = g.vertices_cbegin(); vi1 != g.vertices_cend(); ++vi1) {
        for(auto vi2 = g.vertices_cbegin(); vi2 != g.vertices_cend(); ++vi2) {
          if((*vi1)->descriptor() != (*vi2)->descriptor())
            g.insert_edge((*vi1)->descriptor(), (*vi2)->descriptor(), i++);
        }
      }
    }

    /// @brief test input operator
    void test_file_input(){
      graph<int, int> g;
      ifstream is("graph_input.txt");
      is >> g;

      assert_msg(g.num_vertices() == 119 && g.num_edges() == 596, "Input stream test failed" );
    }

    /// @brief test find vertex operation
    void test_find_vertex() {
      graph<int, int> g;
      setup_larger_dummy_graph(g);
      auto i = g.find_vertex(1);
      assert_msg((*i)->property() == 1, "Find vertex failed");
    }

    /// @brief tests insert vertex operaion
    void test_insert_vertex() {
      graph<int, int> g;

      g.insert_vertex(5);

      assert_msg(g.num_vertices() == 1, "Insert vertex failed.");
    }

    /// @brief test insert edge operation
    void test_insert_edge() {
      graph<int, int> g;

      g.insert_vertex(5);
      g.insert_vertex(1);

      g.insert_edge(0, 1, 10);

      assert_msg(g.num_edges() == 1 && (*g.find_vertex(0))->degree() == 1 && (*g.find_vertex(1))->degree() == 1, "Insert edge failed.");
    }

    /// @brief test find edge operation
    void test_find_edge() {
      graph<int, int> g;
      setup_larger_dummy_graph(g);
      graph<int,int>::edge_descriptor id = std::make_pair(140, 130);
      auto iter = g.find_edge(id);

      assert_msg((*iter)->source() == 140 && (*iter)->target() == 130, "Find edge failed");
    }

    /// @brief test erase vertex operation
    void test_erase_vertex() {
      graph<int, int> g;
      setup_dummy_graph(g);
      g.erase_vertex(1);

      assert_msg(g.num_vertices() == 3 && g.num_edges() == 2, "Erase Vertex failed");
    }

    /// @brief test erase egde operation
    void test_erase_edge() {
      graph<int, int> g;
      setup_dummy_graph(g);
      auto _1 = *g.find_vertex(1);
      auto _2 = *g.find_vertex(2);
      g.erase_edge(std::make_pair(1,2));

      assert_msg(g.num_edges() == 3 && _1->degree() == 1 && _2->degree() == 1, "Erase Edge Failed");
    }

    /// @brief test breadth first search
    void test_breadth_first_search() {
      graph<int, int> g;
      setup_dummy_graph(g);
      typedef graph<int,int>::vertex_descriptor vertex_descriptor;
      unordered_map<vertex_descriptor, vertex_descriptor> test_map;
      mystl::breadth_first_search(g,test_map);

      assert_msg(test_map.size() == 2, "breadth first search failed");
    }

    /// @brief test clear graph
    void test_clear() {
      graph<int, int> g;
      setup_dummy_graph(g);
      g.clear();

      assert_msg(g.num_vertices() == 0 && g.num_edges() == 0, "Clearing Graph failed");
    }

    /// @brief test inserting undirected edge
    void test_insert_edge_undirected() {
      graph<int, int> g;
      setup_dummy_graph(g);
      g.insert_edge_undirected(0, 2, 10);

      assert_msg(g.num_edges() == 6, "Erase Vertex failed");
    }

    /// @brief test prim jarniks mst
    void test_mst_prim_jarniks() {
      graph<int, int> g;
      setup_dummy_graph(g);
      typedef graph<int,int>::vertex_descriptor vertex_descriptor;
      unordered_map<vertex_descriptor, vertex_descriptor> test_map;
      mystl::mst_prim_jarniks(g,test_map);

      assert_msg(test_map.size() == 4, "MST Prim Jarnik's failed");
    }
};


/// @brief main
int main() {
  graph_test ge;

  if(ge.run())
    cout << "All tests passed." << endl;

  return 0;
}
