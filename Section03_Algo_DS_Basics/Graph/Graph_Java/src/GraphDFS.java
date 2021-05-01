import java.util.ArrayList;

public class GraphDFS {

    private Graph G;
    private boolean[] visited;
    private ArrayList<Integer> order = new ArrayList<>();

    public GraphDFS(Graph G) {//构造函数
        this.G = G;
        visited = new boolean[G.V()];
        // dfs(0); 这步需改进
        for (int v = 0; v < G.V(); v ++)
            if (!visited[v])
                dfs(v);
    }

    private void dfs(int v) {
        visited[v] = true;
        order.add(v);
        for (int w: G.adj(v))
            if (!visited[w]) dfs(w);
    }

    public Iterable<Integer> order() {
        return order;
    }
    
    public static void main(String[] args) {
        Graph g = new Graph("D:/GitHub/GitHub_code/LeetCode_Notes_Public/Section03_Algo_DS_Basics/Graph/Graph_Java/g.txt");
        GraphDFS graphDFS = new GraphDFS(g);
        System.out.println(graphDFS.order());
    }
}
/*输出：
[0, 1, 2, 3, 4, 5, 6]
*/