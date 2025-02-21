using static GraphDrawingApp.MainWindow;
using System.Collections.Generic;
using System.Linq;


public class GraphNode
{
    public string Name { get; set; } // ��� ����
    public List<GraphNode> ConnectedNodes { get; set; } // ������ ������� �����

    public GraphNode(string name)
    {
        Name = name;
        ConnectedNodes = new List<GraphNode>();
    }

    // �������� ������� ����
    public void AddConnection(GraphNode node)
    {
        if (!ConnectedNodes.Contains(node))
            ConnectedNodes.Add(node);
    }

    // ������� ������� ����
    public void RemoveConnection(GraphNode node)
    {
        if (ConnectedNodes.Contains(node))
            ConnectedNodes.Remove(node);
    }
}



public class Graph
{


    // ������ ������������� FirstOrDefault
    public GraphNode FindNodeByName(string name)
    {
        return nodes.FirstOrDefault(n => n.Name == name);  // ������������ FirstOrDefault
    }


    private List<GraphNode> nodes; // ������ ���� ����� �����

    public Graph()
    {
        nodes = new List<GraphNode>();
    }

    // �������� ����
    public void AddNode(string name)
    {
        var node = new GraphNode(name);
        nodes.Add(node);
    }

    // ������� ����
    public void RemoveNode(string name)
    {
        var node = nodes.FirstOrDefault(n => n.Name == name);
        if (node != null)
        {
            // ������� ��� ����, ������� ��������� �� ���� ����
            foreach (var n in nodes)
            {
                n.RemoveConnection(node);
            }

            nodes.Remove(node);
        }
    }

    // �������� ���� ����� ����� ������
    public void AddEdge(string node1Name, string node2Name)
    {
        var node1 = nodes.FirstOrDefault(n => n.Name == node1Name);
        var node2 = nodes.FirstOrDefault(n => n.Name == node2Name);

        if (node1 != null && node2 != null)
        {
            node1.AddConnection(node2);
            node2.AddConnection(node1); // ��� ��� ���� �����������������
        }
    }

    // ������� ���� ����� ����� ������
    public void RemoveEdge(string node1Name, string node2Name)
    {
        var node1 = nodes.FirstOrDefault(n => n.Name == node1Name);
        var node2 = nodes.FirstOrDefault(n => n.Name == node2Name);

        if (node1 != null && node2 != null)
        {
            node1.RemoveConnection(node2);
            node2.RemoveConnection(node1); // ��� ��� ���� �����������������
        }
    }

    // �������� ��� ����
    public List<GraphNode> GetNodes()
    {
        return nodes;
    }

    // �������� ��� ���� ��� ���������� ����
    public List<GraphNode> GetConnections(string nodeName)
    {
        var node = nodes.FirstOrDefault(n => n.Name == nodeName);
        return node?.ConnectedNodes ?? new List<GraphNode>();
    }
}
