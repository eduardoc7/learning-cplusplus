/**
* @file Dijkstras.cpp
* @brief This algorithm is used to find the shortest path from
 * one node to every other node in the graph
* @author Eduardo Cordeiro (github.com/eduardoc7)
* @date 19-09-2022
* @license MIT License
**/
#include <iostream>
#include <limits>
#include <unordered_map>
#include <vector>
#include "algorithms.hpp"

void algorithms::GraphDijkstra::addVertice(const std::string &name,
                                           const std::unordered_map<std::string, std::uint64_t> &edges) {
    m_vertices.emplace(name, edges);
}


auto algorithms::GraphDijkstra::findBetterPath(const std::string &initial, const std::string &finish)
-> std::vector<std::string> {
    std::cout << finish << std::endl;
    std::unordered_map<std::string, std::uint64_t> distances;
    std::unordered_map<std::string, std::string> previous;
    std::vector<std::string> nodes;
    std::vector<std::string> path;

    // lambda function used to modify the vector that has the nodes
    // which returns true if the first argument is less than the second
    auto comparator = [&](const std::string &left, const std::string &right) {
        return distances[left] > distances[right];
    };

    for (const auto &v: m_vertices) {
        if (v.first == initial) {
            distances[v.first] = 0;
        } else {
            distances[v.first] = std::numeric_limits<std::uint64_t>::max();
        }

        // add elements into vector container
        nodes.emplace_back(v.first);

        // add nodes on heap and change the order by comparator function
        std::push_heap(std::begin(nodes), std::end(nodes), comparator);
    }

    while (!nodes.empty()) {
        // change the order again to get the last element that be the smallest
        std::pop_heap(std::begin(nodes), std::end(nodes), comparator);

        auto smallest = nodes.back();
        nodes.pop_back();

        // setting the path from the previous node checked
        if(smallest == finish) {
            while(previous.find(smallest) != std::end(previous)) {
                path.emplace_back(smallest);
                smallest = previous[smallest];
            }
            break;
        }

        if (distances[smallest] == std::numeric_limits<int>::max())
        {
            break;
        }

        // setting the better distance from the less cost
        // adding elements to distances, because now we know the less cost
        // and the less distance, should be the previous node also that we know in the vertex
        for(const auto &neighbor : m_vertices[smallest]) {
            auto current_cost = distances[smallest] + neighbor.second;
            if(current_cost < distances[neighbor.first]) {
                distances[neighbor.first] = current_cost;
                previous[neighbor.first] = smallest;
                std::make_heap(std::begin(nodes), std::end(nodes), comparator);
            }
        }
    }

    return path;
}

void algorithms::GraphDijkstra::showGraph() {
    for (const auto &v: m_vertices) {
        std::cout << "initial " << v.first;

        std::uint64_t count{0};
        for (const auto &v2: v.second) {
            if (count > 0) {
                std::cout << "AND " << v.first;
            }

            std::cout << " to " << v2.first;
            std::cout << " has a cost of " << v2.second << std::endl;
            count++;
        }
        std::cout << std::endl;
    }
}
