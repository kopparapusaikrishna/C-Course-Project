#include<iostream>

class Edge
{
    public:
        Edge();
        Edge(int u, int v, double w);

        int getStartVertex() { return startVertex ; }
        void setStartVertex(int u) { startVertex = u ; }

        int getEndVertex() { return endVertex ; }
        void setEndVertex(int v) { endVertex = v ; }

        double getWeight() { return weight ; }
        void setWeight(double w) { weight = w ; }

    private:
        int startVertex;
        int endVertex;
        double weight;
};