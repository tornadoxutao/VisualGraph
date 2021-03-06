// GraphCreator.cpp

#include <oggl/GraphCreator.h>
#include <oggl/Util.h>
#include <vector>

namespace oggl {

    void CreateGrid(ogdf::Graph& g, ogdf::GraphAttributes& ga, int cols, int rows)
    {
        const double width = 30;
        const double dist = 60;

        double x = 0;
        double y = 0;

        int nodeCount = cols * rows;

		ogdf::LayoutStandards::setDefaultEdgeStroke(
			ogdf::Stroke(ogdf::Color::Black));

        std::vector<ogdf::node> nodes(nodeCount);

        for (int i = 0; i < nodeCount; i++)
            nodes[i] = g.newNode();

        for (int j = 0; j < rows; j++)
        {
            x = 0;
            for (int i = 0; i < cols; i++)
            {
                ogdf::node v = nodes[i + j*rows];
                ga.x(v) = x;
                ga.y(v) = y;
                ga.width(v) = width;
                ga.height(v) = width;
				ga.fillColor(v) = RandomOgdfColor();

                if (i < (cols - 1))
                    g.newEdge(v, nodes[i + 1 + j*rows]);
                if (j < (rows - 1))
                    g.newEdge(v, nodes[i + (j + 1)*rows]);

                x += dist;
            }
            y += dist;
        }
    }

}
