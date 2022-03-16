#include <iostream>
#include <list>
#include <unordered_map>
using namespace std;
class graph{
private:
	unordered_map <string, list <pair <string, int>>> um;
public:
	void addEdge(string x, string y, bool bidirect, int weight){
		um[x].push_back({y, weight});
		if(bidirect) um[y].push_back({x, weight}); 
	}
	void printGraph(){
		for(auto p : um){
			cout<<"Vertex "<<p.first<<" -> ";
			for(auto nbr : p.second){
				cout<<"("<<nbr.first<<", "<<nbr.second<<"), ";
			}
			cout<<endl;
		}
	}
};
int main(){
	graph g;
	g.addEdge("A", "B", true, 20);
	g.addEdge("A", "C", true, 10);
	g.addEdge("B", "D", true, 40);
	g.addEdge("C", "D", true, 30);
	g.addEdge("A", "D", false, 50);
	g.printGraph();
	return 0;
}