using static GraphDrawingApp.MainWindow;
using System.Collections.Generic;
using System.Linq;


public class GraphNode
{
    public string Name { get; set; } // Имя узла
    public List<GraphNode> ConnectedNodes { get; set; } // Список смежных узлов

    public GraphNode(string name)
    {
        Name = name;
        ConnectedNodes = new List<GraphNode>();
    }

    // Добавить смежный узел
    public void AddConnection(GraphNode node)
    {
        if (!ConnectedNodes.Contains(node))
            ConnectedNodes.Add(node);
    }

    // Удалить смежный узел
    public void RemoveConnection(GraphNode node)
    {
        if (ConnectedNodes.Contains(node))
            ConnectedNodes.Remove(node);
    }
}



public class Graph
{


    // Пример использования FirstOrDefault
    public GraphNode FindNodeByName(string name)
    {
        return nodes.FirstOrDefault(n => n.Name == name);  // Используется FirstOrDefault
    }


    private List<GraphNode> nodes; // Список всех узлов графа

    public Graph()
    {
        nodes = new List<GraphNode>();
    }

    // Добавить узел
    public void AddNode(string name)
    {
        var node = new GraphNode(name);
        nodes.Add(node);
    }

    // Удалить узел
    public void RemoveNode(string name)
    {
        var node = nodes.FirstOrDefault(n => n.Name == name);
        if (node != null)
        {
            // Удаляем все рёбра, которые ссылаются на этот узел
            foreach (var n in nodes)
            {
                n.RemoveConnection(node);
            }

            nodes.Remove(node);
        }
    }

    // Добавить рёбер между двумя узлами
    public void AddEdge(string node1Name, string node2Name)
    {
        var node1 = nodes.FirstOrDefault(n => n.Name == node1Name);
        var node2 = nodes.FirstOrDefault(n => n.Name == node2Name);

        if (node1 != null && node2 != null)
        {
            node1.AddConnection(node2);
            node2.AddConnection(node1); // Так как граф неориентированный
        }
    }

    // Удалить рёбер между двумя узлами
    public void RemoveEdge(string node1Name, string node2Name)
    {
        var node1 = nodes.FirstOrDefault(n => n.Name == node1Name);
        var node2 = nodes.FirstOrDefault(n => n.Name == node2Name);

        if (node1 != null && node2 != null)
        {
            node1.RemoveConnection(node2);
            node2.RemoveConnection(node1); // Так как граф неориентированный
        }
    }

    // Получить все узлы
    public List<GraphNode> GetNodes()
    {
        return nodes;
    }

    // Получить все рёбер для указанного узла
    public List<GraphNode> GetConnections(string nodeName)
    {
        var node = nodes.FirstOrDefault(n => n.Name == nodeName);
        return node?.ConnectedNodes ?? new List<GraphNode>();
    }
}
