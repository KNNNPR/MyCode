#include <iostream>
#include <vector>
#include <limits>
#include <queue>

class Vertex
{
private:
	bool isVisited;
public:
	std::vector<std::pair<int, int>> neighbours;
	Vertex()
	{
		isVisited = false;
	}
};

class Graph
{
private:
	int vertexAmount;
	std::vector<Vertex> listConnects;
public:
	Graph(int v)
	{
		this->vertexAmount = v;
		listConnects.resize(v);
	}
	void addConnection(int from, int to, int weight)
	{
		listConnects[from].neighbours.push_back(std::make_pair(to, weight));
        listConnects[to].neighbours.push_back(std::make_pair(from, weight));
	}
	void showGraphText()
	{
		for (int i = 0; i < vertexAmount; i++)
		{
			std::cout << "Vertex " << i << " has connections: \n";
			for (int j = 0; j < listConnects[i].neighbours.size(); j++)
			{
				std::cout << "      to vertex" << listConnects[i].neighbours[j].first << " with weight " << listConnects[i].neighbours[j].second << '\n';
			}
		}
	}
    std::vector<int> dijkstraShortestPath(int start, int end) {
        std::vector<int> distance(vertexAmount, std::numeric_limits<int>::max());
        std::vector<int> previous(vertexAmount, -1);

        distance[start] = 0;
        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq;
        pq.push(std::make_pair(0, start));

        while (!pq.empty()) {
            int currentVertex = pq.top().second;
            int currentDistance = pq.top().first;
            pq.pop();

            if (currentDistance > distance[currentVertex]) {
                continue;
            }

            for (const auto& neighbour : listConnects[currentVertex].neighbours) {
                int newDistance = currentDistance + neighbour.second;
                if (newDistance < distance[neighbour.first]) {
                    distance[neighbour.first] = newDistance;
                    previous[neighbour.first] = currentVertex;
                    pq.push(std::make_pair(newDistance, neighbour.first));
                }
            }
        }

        // Восстановление пути
        std::vector<int> shortestPath;
        for (int at = end; at != -1; at = previous[at]) {
            shortestPath.push_back(at);
        }

        std::reverse(shortestPath.begin(), shortestPath.end());
        return shortestPath;
    }
    std::vector<int> calculateVertexRating() {
        std::vector<int> rating(vertexAmount);
        for (int i = 0; i < vertexAmount; ++i) {
            rating[i] = i;
        }

        std::sort(rating.begin(), rating.end(), [this](int a, int b) {
            return listConnects[a].neighbours.size() > listConnects[b].neighbours.size();
            });

        return rating;
    }
};

int main() {
    Graph graph(6);

    graph.addConnection(0, 1, 2);
    graph.addConnection(0, 2, 6);
    graph.addConnection(0, 3, 4);
    graph.addConnection(1, 3, 7);
    graph.addConnection(1, 4, 8);
    graph.addConnection(2, 3, 8);
    graph.addConnection(2, 5, 5);
    graph.addConnection(3, 4, 2);
    graph.addConnection(3, 5, 8);
    graph.addConnection(3, 5, 8);
    graph.addConnection(4, 5, 4);

    graph.showGraphText();

    int startVertex = 0;
    int endVertex = 4;

    std::vector<int> shortestPath = graph.dijkstraShortestPath(startVertex, endVertex);

    std::cout << "Shortest path from vertex " << startVertex << " to vertex " << endVertex << ":";
    for (int vertex : shortestPath) {
        std::cout << vertex << " ";
    }
    std::cout << '\n';

    std::vector<int> vertexRating = graph.calculateVertexRating();
    for (int i = 0; i < vertexRating.size(); i++)
    {
        std::cout << vertexRating[i] << '\n';
    }
}